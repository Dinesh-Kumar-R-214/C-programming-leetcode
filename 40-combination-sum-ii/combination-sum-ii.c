int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* temp, int tempSize,
               int** result, int* resultSize, int* columnSizes) {

    if (target == 0) {
        int* combination = (int*)malloc(sizeof(int) * tempSize);
        for (int i = 0; i < tempSize; i++)
            combination[i] = temp[i];

        result[*resultSize] = combination;
        columnSizes[*resultSize] = tempSize;
        (*resultSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Skip duplicates
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        temp[tempSize] = candidates[i];

        backtrack(candidates, candidatesSize, target - candidates[i],
                  i + 1, temp, tempSize + 1, result, resultSize, columnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);

    int** result = (int**)malloc(sizeof(int*) * 150);
    int* columnSizes = (int*)malloc(sizeof(int) * 150);

    int temp[100];
    int resultSize = 0;

    backtrack(candidates, candidatesSize, target,
              0, temp, 0,
              result, &resultSize, columnSizes);

    *returnSize = resultSize;
    *returnColumnSizes = columnSizes;

    return result;
}
