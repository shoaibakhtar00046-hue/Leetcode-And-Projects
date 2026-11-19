
int findShortestSubArray(int* nums, int numsSize) {
    int count[50001] = {0};
    int first[50001];
    int last[50001];

    for (int i = 0; i < 50001; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    int degree = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        count[x]++;

        if (first[x] == -1)
            first[x] = i;

        last[x] = i;

        if (count[x] > degree)
            degree = count[x];
    }

    int ans = numsSize;

    for (int i = 0; i < 50001; i++) {
        if (count[i] == degree) {
            int len = last[i] - first[i] + 1;

            if (len < ans)
                ans = len;
        }
    }

    return ans;
}
