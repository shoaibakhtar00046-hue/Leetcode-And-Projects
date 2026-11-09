int findNonMinOrMax(int* nums, int numsSize) {
    if (numsSize < 3) {
        return -1;
    }
    
    // Check the first three elements and return the one that is neither min nor max among them
    int a = nums[0], b = nums[1], c = nums[2];
    
    if ((a > b && a < c) || (a < b && a > c)) return a;
    if ((b > a && b < c) || (b < a && b > c)) return b;
    return c;
}