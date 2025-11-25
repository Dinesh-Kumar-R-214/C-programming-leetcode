#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (num1[0] == '0' || num2[0] == '0') {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int* result = (int*)calloc(len1 + len2, sizeof(int));

    // Multiply each digit
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;      // store digit
            result[i + j] += sum / 10;        // carry
        }
    }

    // Convert to string
    int i = 0;
    while (i < len1 + len2 && result[i] == 0) i++;  // skip leading zeros

    int size = len1 + len2 - i;
    char* ans = (char*)malloc(size + 1);

    for (int k = 0; k < size; k++)
        ans[k] = result[i + k] + '0';

    ans[size] = '\0';

    free(result);
    return ans;
}

