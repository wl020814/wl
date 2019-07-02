#include<stdio.h>
#include<stdlib.h>

#define Row 6
#define Column 6
int g_miGong[Row][Column] = {0};


struct Pos {
    int x;
    int y;
};

struct Stack {
    struct Pos pos;
    struct Stack *stack;
};

void PushStack(struct Pos pos)
{

}

void NewAMap(void)
{
    int i, j;
    for (i = 0; i < Row; i++) {
        printf("please input %d nums to draw map row %d.\n", Column ,i);
        for (j = 0; j < Column; j++) {
            scanf("%d", &g_miGong[i][j]);
        }
    }
}

void DrawTheMap(void)
{
    int i, j;
    for (i = 0; i < Row; i++) {
        for (j = 0; j< Column; j++) {
            printf("%d ", g_miGong[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    NewAMap();
    DrawTheMap();
    return 0;
}
