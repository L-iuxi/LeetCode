void reverseString(char* s, int sSize) {
  // int len = strlen(s);
   int left = 0,right = sSize - 1;
   while(left < right)
   {
    char t;
    t = s[left];
    s[left] = s[right];
    s[right] = t;
    right--;
    left++;
   } 

}