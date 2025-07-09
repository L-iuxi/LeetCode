#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);

   
    char *arr1 = (char*)malloc(sizeof(char) * (len1 + 1)); 
    char *arr2 = (char*)malloc(sizeof(char) * (len2 + 1));
    
    int ind1 = len1 - 1, ind2 = len2 - 1;
    for (int i = 0; i < len1; i++) {
        arr1[i] = a[ind1--];
    }
    for (int i = 0; i < len2; i++) {
        arr2[i] = b[ind2--];
    }

   
    int max_len = (len1 > len2 ? len1 : len2) + 2;
    char *result = (char*)malloc(sizeof(char) * max_len);
    int w = 0;
    int carry = 0;

    while (w < len1 || w < len2 || carry) {
        int sum = carry;
        
        if (w < len1 && arr1[w] == '1') {
            sum += 1;
        }
        if (w < len2 && arr2[w] == '1') {
            sum += 1;
        }

        if (sum % 2 == 1) {
            result[w] = '1';
        } else {
            result[w] = '0';
        }

        carry = sum / 2;
        w++;
    }

    result[w] = '\0'; 

    
    char *end = (char*)malloc(sizeof(char) * (w + 1));
    int count = w - 1;
    for (int i = 0; i < w; i++) {
        end[i] = result[count--];
    }
    end[w] = '\0';

   
    free(arr1);
    free(arr2);
    free(result);

    return end;
}


