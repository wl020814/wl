#include<stdio.h>
#include<stdlib.h>

#define Row 6
#define Column 6
int g_miGong[Row][Column] = {0};


struct Pos {
    int x;
    int y;
};

struct Node {
    struct Pos pos;
    struct Node *next;
}

struct Stack {
    struct Node *top;
    struct Node *bottom;
};

Stack NewStack(int i, int j)
{
    struct Stack s;
    struct Node *node = malloc(sizeof(Node));
    node->pos.x = i;
    node->pos.y = j;
    g_miGong[i][j] = 2;
    node->next = null;
    s.top = node;
    s.bottom = node;
    return s;
}

void PushStack(struct Stack s, int i, int j)
{
    struct Node *node = malloc(sizeof(Node));
    node->pos.x = i;
    node->pos.y = j;
    g_miGong[i][j] = 2;
    node->next = s->top;
    s->top = node;
}

void PopStack(struct Stack s)
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

void FinNextPath(struct s, int *i, int *j)
{
    if (g_miGong[*i - 1][*j] == 1) {
        pushStack(s, (*i - 1), *j);
        FindNextPath(s, (*i - 1), *j);
    }
    if (g_miGong[*i + 1][*j] == 1) {
        pushStack(s, (*i + 1), *j);
        FindNextPath(s, (*i + 1), *j);
    }
    if (g_miGong[*i][*j + 1] == 1) {
        pushStack(s, *i, *j + 1);
        FindNextPath(s, *i, *j + 1);
    }
    if (g_miGong[*i][*j -1] == 1) {
        pushStack(s, *i, *j - 1);
        FindNextPath(s, *i, *j - 1);
    }
}

void FindPath()
{
    int i = 0, j = 0;
    struct Stack s = {null, null};
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
    Stack *path = null;
    NewAMap();
    DrawTheMap();
    return 0;
}
