int findGCD(int* nums, int numsSize) {
    int min = nums[0];
    int max = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    while (min != 0) {
        int temp = min;
        min = max % min;
        max = temp;
    }
    
    return max;
}