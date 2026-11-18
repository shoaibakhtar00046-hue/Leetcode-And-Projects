int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
    *returnSize = numsSize;
    int* target = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j > index[i]; j--) {
            target[j] = target[j - 1];
        }
        target[index[i]] = nums[i];
    }
    return target;
}