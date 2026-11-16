int numIdenticalPairs(int* nums, int numsSize) {
    int count[102] = {0};
    int goodPairs = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Each time we encounter a number, add how many times 
        // it has appeared previously to the good pairs count, 
        // then increment its frequency.
        goodPairs += count[nums[i]];
        count[nums[i]]++;
    }
    
    return goodPairs;
}