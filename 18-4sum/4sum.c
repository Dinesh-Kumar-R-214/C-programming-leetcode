int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 50000;
    int** res = malloc(cap * sizeof(int*));
    int* col = malloc(cap * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            long t = (long)target - nums[i] - nums[j];
            int l = j + 1, r = numsSize - 1;

            while (l < r) {
                long sum = (long)nums[l] + nums[r];

                if (sum == t) {
                    res[*returnSize] = malloc(4 * sizeof(int));
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[l];
                    res[*returnSize][3] = nums[r];
                    col[*returnSize] = 4;
                    (*returnSize)++;

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if (sum < t) l++;
                else r--;
            }
        }
    }

    *returnColumnSizes = col;
    return res;
}
