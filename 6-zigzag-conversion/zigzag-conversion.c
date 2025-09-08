char * convert(char * s, int numRows){
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) return strdup(s);

    char *result = (char*)malloc(len + 1);
    int pos = 0;

    char **rows = (char**)malloc(numRows * sizeof(char*));
    int *row_len = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = (char*)malloc(len + 1);

    int row = 0;
    int down = 1;

    for (int i = 0; i < len; i++) {
        rows[row][row_len[row]++] = s[i];
        if (row == 0) down = 1;
        else if (row == numRows - 1) down = 0;
        row += down ? 1 : -1;
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < row_len[i]; j++) {
            result[pos++] = rows[i][j];
        }
        free(rows[i]);
    }

    free(rows);
    free(row_len);

    result[len] = '\0';
    return result;
}
