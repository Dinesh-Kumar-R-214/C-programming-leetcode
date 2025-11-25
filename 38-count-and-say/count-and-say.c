char* countAndSay(int n) {
    if (n == 1) {
        char* base = (char*)malloc(2);
        strcpy(base, "1");
        return base;
    }

    char* prev = countAndSay(n - 1);
    int len = strlen(prev);

    char* result = (char*)malloc(2 * len + 1);
    int k = 0;

    for (int i = 0; i < len; ) {
        char current = prev[i];
        int count = 0;

        while (i < len && prev[i] == current) {
            count++;
            i++;
        }

        result[k++] = count + '0';
        result[k++] = current;
    }

    result[k] = '\0';
    free(prev);
    return result;
}
