
#include <stdio.h>
#include <string.h>

// Calculate the LPS array
void computeLPS(char pat[], int m, int lps[]) {
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len > 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
}

// KMP searching
void KMPSearch(char pat[], char txt[]) {
    int m = strlen(pat);
    int n = strlen(txt);

    if (m == 0) return;

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0, j = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        else if (j > 0) {
            j = lps[j - 1];
        }
        else {
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    KMPSearch(pat, txt);

    return 0;
}
