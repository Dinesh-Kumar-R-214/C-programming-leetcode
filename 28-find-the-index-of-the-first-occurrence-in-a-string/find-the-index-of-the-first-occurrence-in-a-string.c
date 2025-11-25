int strStr(char * haystack, char * needle){
    if(needle[0] == '\0') return 0;

    int n = 0, m = 0;
    while(haystack[n] != '\0') n++;
    while(needle[m] != '\0') m++;

    if(m > n) return -1;

    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(haystack[i + j] != needle[j]) break;
        }
        if(j == m) return i;
    }

    return -1;
}
