#include<stdio.h>
#include<stdlib.h>

#define Row 6
#define Column 6

int g_miGong[Row][Column] = {0, 0, 1, 0, 1, 0,
                             1, 1, 1, 0, 1, 0,
                             0, 0, 1, 0, 0, 1,
                             0, 0, 1, 0, 0, 1,
                             0, 0, 1, 0, 0, 1,
                             0, 0, 1, 0, 0, 1,
};

struct Pos {
    int x;
    int y;
};

struct Node {
    struct Pos pos;
    struct Node *next;
};

struct Stack {
    struct Node *top;
    struct Node *bottom;
};

struct Stack* NewStack(int i, int j)
{
    struct Stack *s = malloc(sizeof(struct Stack));
    struct Node *node = malloc(sizeof(struct Node));
    node->pos.x = i;
    node->pos.y = j;
    g_miGong[i][j] = 2;
    node->next = NULL;
    s->top = node;
    s->bottom = node;
    return s;
}

void PushStack(struct Stack *s, int i, int j)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->pos.x = i;
    node->pos.y = j;
    g_miGong[i][j] = 2;
    node->next = s->top;
    s->top = node;
}

void PopStack(struct Stack *s)
{
    struct Node *node = s->top;
    g_miGong[node->pos.x][node->pos.y] = 1;
    s->top = node->next;
    free(node);
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

void FinNextPath(struct Stack *s, int *i, int *j);
void FinNextPath(struct Stack *s, int *i, int *j)
{
    if (*i == (Row - 1)) {
        printf("the result of map is:\n");
        DrawTheMap();
        return;
    }

    if (g_miGong[*i - 1][*j] == 1) {
        PushStack(s, (*i - 1), *j);
        FindNextPath(s, (*i - 1), *j);
    }
    if (g_miGong[*i + 1][*j] == 1) {
        PushStack(s, (*i + 1), *j);
        FindNextPath(s, (*i + 1), *j);
    }
    if (g_miGong[*i][*j + 1] == 1) {
        PushStack(s, *i, *j + 1);
        FindNextPath(s, *i, *j + 1);
    }
    if (g_miGong[*i][*j -1] == 1) {
        PushStack(s, *i, *j - 1);
        FindNextPath(s, *i, *j - 1);
    }
    PopStack(s);
}

void FindPath()
{
    int i = 0, j = 0;
    struct Stack *s = NULL;
    for (j = 0; j < Column; j++) {
        if (g_miGong[i][j] == 1) {
            s = NewStack(i, j);
            while (i != (Row - 1)) {
                FindNextPath(s, &i, &j);
            }
        }
    }

}

int main(void)
{
    //struct Stack *path = null;
    //NewAMap();
    DrawTheMap();
    FindPath();
    return 0;
}
