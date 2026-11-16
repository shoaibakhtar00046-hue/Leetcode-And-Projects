#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digitSum(char* s, int k) {
    // Continue the process as long as the length of s is greater than k
    while (strlen(s) > k) {
        int len = strlen(s);
        // Estimate the maximum possible length for the new string
        // Each group of size up to 100 sums to at most 9 * 100 = 900 (3 digits + null terminator)
        int new_len = ((len + k - 1) / k) * 4 + 1;
        char* new_s = (char*)malloc(new_len);
        new_s[0] = '\0';
        
        for (int i = 0; i < len; i += k) {
            int current_sum = 0;
            // Sum the digits in the current group of size up to k
            for (int j = i; j < i + k && j < len; j++) {
                current_sum += s[j] - '0';
            }
            
            // Convert current_sum to string and append to new_s
            char temp[10];
            sprintf(temp, "%d", current_sum);
            strcat(new_s, temp);
        }
        
        // Free old s (if dynamically allocated) and update reference
        // Note: For LeetCode, ensure memory handling matches their expected signature.
        strcpy(s, new_s);
        free(new_s);
    }
    return s;
}

