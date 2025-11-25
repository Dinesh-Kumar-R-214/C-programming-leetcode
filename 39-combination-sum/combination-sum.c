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
        if (candidates[i] > target) continue;

        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i,
                  temp, tempSize + 1, result, resultSize, columnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    int** result = (int**)malloc(sizeof(int*) * 200);
    int* columnSizes = (int*)malloc(sizeof(int) * 200);

    int temp[100];
    int resultSize = 0;

    backtrack(candidates, candidatesSize, target, 0,
              temp, 0,
              result, &resultSize, columnSizes);

    *returnSize = resultSize;
    *returnColumnSizes = columnSizes;

    return result;
}
