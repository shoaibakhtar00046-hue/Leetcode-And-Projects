int alternateDigitSum(int n) {
    char s[12];
    sprintf(s, "%d", n);
    int sum = 0;
    int sign = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        sum += (s[i] - '0') * sign;
        sign *= -1;
    }
    return sum;
}