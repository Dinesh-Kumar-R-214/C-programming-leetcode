bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);

    // DP table
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;  // empty string matches empty pattern

    // Handle patterns like *, **, ***, ****
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];  // direct match
            }

            else if (p[j - 1] == '*') {
                dp[i][j] =
                    dp[i][j - 1] ||  // '*' matches empty
                    dp[i - 1][j];    // '*' matches one or more characters
            }

            else dp[i][j] = false;
        }
    }

    return dp[n][m];
}
