#include <stdio.h>
#include <string.h>

void computeLPS(char* pattern, int* lps) {
    int len = strlen(pattern);
    int i = 1, j = 0;

    lps[0] = 0;
    while (i < len) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* text, char* pattern) {
    int lenT = strlen(text);
    int lenP = strlen(pattern);
    int lps[lenP];
    computeLPS(pattern, lps);

    int i = 0, j = 0;
    while (i < lenT) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == lenP) {
            printf("Pattern found at index %d\n", i-j);
            j = lps[j-1];
        }
        else if (i < lenT && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";
    KMPSearch(text, pattern);
    return 0;
}
