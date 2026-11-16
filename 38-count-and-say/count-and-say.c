char* countAndSay(int n) {
    if (n == 1) {
        char* res = (char*)malloc(2 * sizeof(char));
        res[0] = '1';
        res[1] = '\0';
        return res;
    }
    
    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* res = (char*)malloc((2 * len + 1) * sizeof(char));
    int res_idx = 0;
    
    for (int i = 0; i < len; ) {
        int count = 1;
        while (i + 1 < len && prev[i] == prev[i + 1]) {
            count++;
            i++;
        }
        res_idx += sprintf(res + res_idx, "%d%c", count, prev[i]);
        i++;
    }
    res[res_idx] = '\0';
    free(prev);
    return res;
}