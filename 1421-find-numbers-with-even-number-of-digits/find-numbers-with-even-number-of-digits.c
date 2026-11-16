int findNumbers(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int digits = 0;
        int temp = nums[i];
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
        if (digits % 2 == 0) {
            count++;
        }
    }
    return count;
}