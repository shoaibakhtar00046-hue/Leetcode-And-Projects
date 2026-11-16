/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    
    // Step 1: Find the maximum number of candies currently among all kids
    int maxCandies = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }
    
    // Step 2: Check if each kid's candies + extraCandies >= maxCandies
    for (int i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }
    
    return result;
}