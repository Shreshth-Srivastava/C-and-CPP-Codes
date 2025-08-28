#include <stdio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}
void circleBres(int xc, int yc, int r){
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x){
        if (d > 0) {
            y--; 
            d = d + 4 * (x - y) + 10;
        }
        else d = d + 4 * x + 6;
        x++;

        drawCircle(xc, yc, x, y);
        delay(50);
    }
}
int main(){
    int xc = 50, yc = 50, r = 30;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    circleBres(xc, yc, r);
    return 0;
}
