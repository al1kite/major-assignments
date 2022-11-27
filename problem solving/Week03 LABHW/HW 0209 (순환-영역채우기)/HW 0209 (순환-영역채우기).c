/*#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};
int  flood_fill(int x, int y, int count);
int flood_fill(int x, int y, int count)
{
    int num;
    if (screen[x][y] == 0)
    {
        screen[x][y] = ++count;
        if (x != WIDTH - 1)
            count = flood_fill(x + 1, y, count); 
        if (y != 0)
            count = flood_fill(x, y - 1, count);
        if (y != HEIGHT - 1)
            count = flood_fill(x, y + 1, count);
        if (x != 0)
            count = flood_fill(x - 1, y, count);
        return count;
    }
    return count;
}
void display()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf("%2d ", screen[i][j]);
        printf("\n");
    }
}
int main(void)
{
    display();
    printf("\n");
    flood_fill(0, 0, 0);
    display();
}
*/

#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};
void flood_fill(int x, int y)
{
    static int count = 1;
    if (screen[x][y] == 0)
    {
        screen[x][y] = count++;

        if (y != HEIGHT - 1)
            flood_fill(x, y + 1);
        if (x != WIDTH - 1) 
            flood_fill(x + 1, y);
        if (y != 0)
            flood_fill(x, y - 1);
        if (x != 0)
            flood_fill(x - 1, y);
    }
}

int main(void)
{
    int i, j;

    printf("미로\n");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%3d", screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    flood_fill(0, 0);
    printf("시작점은 (0 0)으로 한 미로방문 (순서표기)\n");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++)
            printf("%3d", screen[i][j]);
        printf("\n");
    }
}
