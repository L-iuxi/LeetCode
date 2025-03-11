#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>


void handle_sigint(int sig)
{
    printf("td");
    exit(0);
}
void jiexi(char* input,char **args)//解析命令的函数
{
    int i = 0;
    char *command = strtok(input," \t\n\r");
    //int i = 0;
    while(command != NULL)
    {
         if (command[0] == '"') {
            // 去除引号
            command++; 
            char *test = strchr(command, '"');
            if (test != NULL) {
                *test = '\0'; 
            }
        }
        args[i++] = command;
        command = strtok(NULL," \t\n\r");

    }
    args[i] = NULL;
}
void zhixing(char **args)//执行命令的函数
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork failed");
        exit(1);
    }else if(pid == 0)
    {
        printf("now Command is(000): %s\n", args[0]);//现在读入的命令
        if(execvp(args[0], args) == -1) 
        {
        perror("exec failed");
        exit(1);
        }

        // if(execvp(args[0],args) == -1)
        // {
        //      perror("exec failed");
        // exit(1);
        // }
    }else{
            wait(NULL);
        }
}
// void easy_zhixing()
// {
//     if(execvp(args[0],args) == -1)
//         {
//              perror("exec failed");
//         exit(1);
//         }
// }
void cd_command(char *dir) {
  
    if (dir == NULL) {
        dir = getenv("HOME");
    }

    if (chdir(dir) == -1) {
        perror("cd failed");
    }
}
void pipe_zhixing(char* input)
{
     char *commands[100];
    char *command = strtok(input,"|");
    int i = 0;
    
    //char *args[10086];
    while(command != NULL)
    {
        commands[i++] = command;
        command = strtok(NULL,"|");
    }
     int pipefd[2];
        pid_t pid;
        int prev = -1; 
        //char buf[10086];
    for(int k = 0;k < i;k++)
    {
        //pid = fork();

        if (pipe(pipefd) == -1)
         {
        perror("pipe");
        exit(1);
         }

        pid = fork();
        if(pid == -1)
        {
            perror("fork");
            exit(1);
        }
        if(pid == 0)
        {
            if(prev != -1)
            {
                 if(dup2(prev, STDIN_FILENO) == -1)
            {
                perror("dup_stdin");
                exit(1);
            }
            
            close(prev);
            }
            
            if(k < i - 1)
            {
                 if(dup2(pipefd[1], STDOUT_FILENO) == -1)
            {
                perror("dup_stdout");
                exit(1);
            }
            }
            close(pipefd[0]);
            close(pipefd[1]);
             
             
             
             char *args[100];
            jiexi(commands[k],args);
            printf("now Command(111): %s\n", args[0]);//现在读入的命令
             if(execvp(args[0],args) == -1)
        {

            perror("exec failed");
            exit(1);
        }
    }else{
          close(pipefd[1]);
           if (prev != -1)
            {
                close(prev);
            }
            prev = pipefd[0];

        }
       
            wait(NULL);
           }
    }
    

    
int main(int argc, char *argv[])
{
    signal(SIGINT, handle_sigint);
    char *args[100];
    char input[100];
    //int i = 0;
    while (1)
    {
        //i++;
        printf("shell> ");
        if (fgets(input, 100, stdin) == NULL)
        {
            break;
        }

       
        if (strchr(input, '|'))
        {
            pipe_zhixing(input);
        }
        else
        {
            input[strcspn(input, "\n")] = '\0'; // 去掉换行符

            
            if (strcmp(input, "exit") == 0)
            {
                break;
            }

          
            char *args[100];
            jiexi(input, args);

            if (strcmp(args[0], "cd") == 0)
            {
                if (args[1] != NULL)
                {
                 
                    cd_command(args[1]);
                }
                else
                {
                   
                    cd_command(NULL);
                }
                continue;
            }

            
            zhixing(args);
        }
    }

    return 0;
}