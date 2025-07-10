int strStr(char* haystack, char* needle) {
    int i = 0;
    int result = -1;
    int len = strlen(needle);
    while(haystack[i] != '\0')
    {
        if(result != -1)
        {
            break;
        }
        if(haystack[i] == needle[0])
        {
            int h = i;
            result = i;
            for(int j = 0;j < len;j++)
            {

                if(haystack[h] != needle[j])
                {
                    result = -1;
                    break;
                }
                h++;
            }
        
        }
        i++;
    }
    return result;
}