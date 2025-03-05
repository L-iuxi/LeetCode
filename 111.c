#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;unistd.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/wait.h&gt;

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define PIPE_READ 0
#define PIPE_WRITE 1

// 函数：解析命令行
void parse_command(char *input, char **args) {
char *token = strtok(input, " \t\r\n");
int i = 0;

while (token != NULL) {
args[i++] = token;
token = strtok(NULL, " \t\r\n");
}
args[i] = NULL; // 结束符
}

// 函数：执行单个命令
void execute_command(char **args) {
pid_t pid = fork(); // 创建子进程

if (pid == -1) {
perror("fork failed");
exit(1);
} else if (pid == 0) {
// 子进程执行命令
if (execvp(args[0], args) == -1) {
perror("exec failed");
exit(1);
}
} else {
// 父进程等待子进程执行完
wait(NULL);
}
}

// 函数：执行带管道的命令
void execute_pipeline(char *input) {
int pipefds[2]; // 管道文件描述符
pid_t pid;
char *commands[MAX_ARGS]; // 存储各个命令
char *args[MAX_ARGS]; // 存储命令的参数
int i = 0;

// 分割输入的命令链，如 "ls -l | grep txt"
char *command = strtok(input, "|");

while (command != NULL) {
commands[i++] = command;
command = strtok(NULL, "|");
}

// 遍历所有命令
for (int j = 0; j &lt; i; j++) {
// 创建管道
if (pipe(pipefds) == -1) {
perror("pipe failed");
exit(1);
}

// 解析当前命令
parse_command(commands[j], args);

pid = fork(); // 创建子进程
if (pid == -1) {
perror("fork failed");
exit(1);
} else if (pid == 0) {
// 在子进程中处理管道

// 如果不是最后一个命令，将标准输出重定向到管道的写端
if (j &lt; i - 1) {
close(pipefds[PIPE_READ]); // 关闭管道读取端
dup2(pipefds[PIPE_WRITE], STDOUT_FILENO); // 将标准输出重定向到管道写端
}

// 如果不是第一个命令，将标准输入重定向到管道的读端
if (j &gt; 0) {
close(pipefds[PIPE_WRITE]); // 关闭管道写端
dup2(pipefds[PIPE_READ], STDIN_FILENO); // 将标准输入重定向到管道读端
}

// 关闭管道的读写端
close(pipefds[PIPE_READ]);
close(pipefds[PIPE_WRITE]);

// 执行命令
if (execvp(args[0], args) == -1) {
perror("exec failed");
exit(1);
}
}
}

// 关闭管道文件描述符
close(pipefds[PIPE_READ]);
close(pipefds[PIPE_WRITE]);

// 父进程等待所有子进程
for (int j = 0; j &lt; i; j++) {
wait(NULL);
}
}

int main() {
char input[MAX_CMD_LENGTH]; // 存储用户输入
char *args[MAX_ARGS]; // 存储解析后的命令和参数

while (1) {
// 显示提示符
printf("my_shell&gt; ");

// 读取输入
if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) {
break; // 用户输入结束
}

// 检查是否存在管道符
if (strchr(input, '|')) {
execute_pipeline(input); // 执行管道命令
} else {
// 解析命令并执行
parse_command(input, args);
if (args[0] != NULL &amp;&amp; strcmp(args[0], "exit") == 0) {
break; // 输入 "exit" 退出 shell
}
execute_command(args);
}
}

return 0;
}