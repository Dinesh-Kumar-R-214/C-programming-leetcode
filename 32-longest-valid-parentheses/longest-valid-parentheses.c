#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char * s) {
    int n = strlen(s);
    int *stack = malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxLen = 0;

    // Initialize stack with -1 to handle edge case
    stack[++top] = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            stack[++top] = i;  // push index of '('
        } else {
            top--; // pop for ')'
            if(top == -1) {
                stack[++top] = i; // push current index as base
            } else {
                int len = i - stack[top];
                if(len > maxLen) maxLen = len;
            }
        }
    }

    free(stack);
    return maxLen;
}
