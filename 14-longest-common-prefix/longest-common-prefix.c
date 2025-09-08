#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    static char prefix[200]; 
    strcpy(prefix, strs[0]); // start with first string

    for (int i = 1; i < strsSize; i++) {
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {
            prefix[strlen(prefix) - 1] = '\0'; 
            if (strlen(prefix) == 0) return "";
        }
    }
    return prefix;
}
