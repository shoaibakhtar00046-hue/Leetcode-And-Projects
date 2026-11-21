#include <string.h>

int strStr(char* haystack, char* needle) {
    int hLen = (int)strlen(haystack);
    int nLen = (int)strlen(needle);

    if (nLen == 0) {
        return 0;
    }
    if (nLen > hLen) {
        return -1;
    }

    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == nLen) {
            return i;
        }
    }

    return -1;
}