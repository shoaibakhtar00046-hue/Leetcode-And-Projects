
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digitSum(char* s, int k) {
    while (strlen(s) > k) {
        int len = strlen(s);
        int new_len = ((len + k - 1) / k) * 4 + 1;
        char* new_s = (char*)malloc(new_len);
        new_s[0] = '\0';
        
        for (int i = 0; i < len; i += k) {
            int current_sum = 0;
            for (int j = i; j < i + k && j < len; j++) {
                current_sum += s[j] - '0';
            }
            
            char temp[10];
            sprintf(temp, "%d", current_sum);
            strcat(new_s, temp);
        }
        
        strcpy(s, new_s);
        free(new_s);
    }
    return s;
}

