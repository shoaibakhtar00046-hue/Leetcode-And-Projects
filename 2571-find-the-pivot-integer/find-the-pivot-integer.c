int pivotInteger(int n) {
    int total_sum = n * (n + 1) / 2;
    int left_sum = 0;
    for (int i = 1; i <= n; i++) {
        left_sum += i;
        if (left_sum == total_sum - left_sum + i) {
            return i;
        }
    }
    return -1;
}