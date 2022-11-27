#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
-1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};
void flood_fill(int x, int y);
void flood_fill(int x, int y)
{
    int num;
    if (screen[x][y] == 0)
    {
        screen[x][y] = 9;
        flood_fill(x + 1, y);
        flood_fill(x, y - 1);
        flood_fill(x, y + 1);
        flood_fill(x - 1, y);
    }
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
    flood_fill(4, 3);
    display();
}