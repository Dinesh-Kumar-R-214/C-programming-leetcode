void backtrack(int n, int open, int close, char* path, int idx, char** res, int* returnSize) {
    if (idx == 2 * n) {
        path[idx] = '\0';
        res[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        path[idx] = '(';
        backtrack(n, open + 1, close, path, idx + 1, res, returnSize);
    }
    if (close < open) {
        path[idx] = ')';
        backtrack(n, open, close + 1, path, idx + 1, res, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 10000;
    char** res = malloc(capacity * sizeof(char*));
    char path[2 * n + 1];
    *returnSize = 0;
    backtrack(n, 0, 0, path, 0, res, returnSize);
    return res;
}
