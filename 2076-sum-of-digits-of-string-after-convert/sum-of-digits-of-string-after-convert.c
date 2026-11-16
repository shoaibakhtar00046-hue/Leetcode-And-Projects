int getLucky(char * s, int k) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int val = s[i] - 'a' + 1;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
    }
    
    for (int i = 1; i < k; i++) {
        int temp = sum;
        sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
    }
    
    return sum;
}