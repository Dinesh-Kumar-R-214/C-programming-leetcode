int* getNoZeroIntegers(int n, int* returnSize) {
    static int ans[2];

    for (int a = 1; a < n; a++) {
        int b = n - a;

        int temp = a, hasZeroA = 0;
        while (temp > 0) {
            if (temp % 10 == 0) {
                hasZeroA = 1;
                break;
            }
            temp /= 10;
        }

        temp = b;
        int hasZeroB = 0;
        while (temp > 0) {
            if (temp % 10 == 0) {
                hasZeroB = 1;
                break;
            }
            temp /= 10;
        }

        if (hasZeroA == 0 && hasZeroB == 0) {
            ans[0] = a;
            ans[1] = b;
            *returnSize = 2;
            return ans;
        }
    }

    *returnSize = 0;
    return NULL;
}
