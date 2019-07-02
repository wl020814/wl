#include <stdlib.h>
#include <stdio.h>

int ismatch(char *s, char *p)
{
    int i = 0, j = 0, tmp = 0;
    char regex = 0;
    if ((s == NULL) || (p == NULL)) {
        return 0;
    }

    while (p[j] != '\0') {
        if (p[j] == '*') {
            if(regex == s[i]) {
                i++;
            } else {
                j++;
            }
        }

        while (s[i] != '\0') {
            if ((s[i] == p[j]) || (p[j] == '.')) {
                i++;
                j++;
                regex = p[j];
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

char *s = "abbbbbbc";
char *p = "ababdsddd.b*cddbc";

int main(void)
{
    return ismatch(s, p);
}
