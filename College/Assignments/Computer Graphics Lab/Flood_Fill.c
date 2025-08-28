#include <stdio.h>
#include <graphics.h>
 
void flood(int x, int y, int new_col, int old_col)
{
    if (getpixel(x, y) == old_col) {
        putpixel(x, y, new_col);
        delay(5);
        flood(x + 1, y, new_col, old_col);
        flood(x - 1, y, new_col, old_col);
        flood(x, y + 1, new_col, old_col);
        flood(x, y - 1, new_col, old_col);
    }
}
 
int main()
{
    int gd = DETECT, gm, top, left, bottom, right, x = 51, y = 51, newcolor = 12, oldcolor = 0;
    initgraph(&gd, &gm, "");
 
    top = left = 50;
    bottom = right = 300;
    rectangle(left, top, right, bottom);
    flood(x, y, newcolor, oldcolor);
    getch();
 
    return 0;
}