int numberOfChild(int n, int k) {
    int period = 2 * (n - 1);
    int rem = k % period;
    if (rem < n) {
        return rem;
    } else {
        return period - rem;
    }
}