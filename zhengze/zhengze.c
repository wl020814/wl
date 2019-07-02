#include <stdlib.h>
#include <stdio.h>

int ismatch(char *s, char *p)
{
    int i = 0, j = 0, tmp = 0;
    if ((s == NULL) || (p == NULL)) {
        return 0;
    }

    while (p[j] != '\0') {
        while (s[i] != '\0') {
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                i = 0;
                j = tmp++;
            }
        }
        printf("match from p pos:%d\n", tmp);
        return 1;
    }
    printf("not match p");
    return 0;
}

char *s = "abc";
char *p = "ababddddabcdabc";

int main(void)
{
    return ismatch(s, p);
}
