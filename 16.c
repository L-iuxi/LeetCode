bool isValid(char* s) {
    int len = strlen(s);
    int top = -1;
    char stack[len+1];
    if(len % 2 != 0)
    {
        return false;
    }
    for(int i = 0;i < len;i++)
    {
        if(s[i] == '('||s[i] == '['||s[i] == '{')
        {
            top++;
            stack[top] = s[i];
        }
        if(s[i] == ')'||s[i] == '}'||s[i] == ']')
        {
            if(top == -1)
            {
                return false;
            }
            if((stack[top] == '('&& s[i]!= ')')||(stack[top] == '{'&&s[i] != '}')||(stack[top] == '['&&s[i] != ']'))
            {
                return false;
            }
            top--;
        }
            }
    return top == -1;
}