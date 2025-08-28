#include<stdio.h>
#include<stdlib.h>

float win_top = 8, win_bottom = 4, win_right = 10, win_left = 4;

int ComputeCode(float x, float y){
    int code = 0, top = 8, bottom = 4, right = 2, left = 1;

    if(y > win_top) code |= top;
    else if(y < win_bottom) code |= bottom;
    if(x > win_right) code |= right;
    else if(x < win_left) code |= left;

    return code;
}

void CohenSutherland(float x1, float y1, float x2, float y2){
    int accept = 0;
    int c1 = ComputeCode(x1, y1), c2 = ComputeCode(x2, y2);
    while(1){
        if(c1 == 0 && c2 == 0){
            accept = 1;
            break;
        }
        else if(c1 & c2){
            break;
        }
        else{
            int out_code = (c1 != 0)?c1:c2;
            float x, y;
            if(out_code & (int)win_top) x = x1 + (x2 - x1)*(win_top - y1)/(y2 - y1), y = win_top;
            else if(out_code & (int)win_bottom) x = x1 + (x2 - x1)*(win_bottom - y1)/(y2 - y1), y = win_bottom;
            else if(out_code & (int)win_right) x = win_right, y = y1 + (y2 - y1)*(win_right - x1)/(x2 - x1);
            else if(out_code & (int)win_left) x = win_left, y = y1 + (y2 - y1)*(win_left - x1)/(x2 - x1);

            if(out_code == c1){
                x1 = x, y1 = y;
                c1 = ComputeCode(x1, y1);
            }
            else{
                x2 = x, y2 = y;
                c2 = ComputeCode(x2, y2);
            }
        }
    }
    if(accept){
        printf("\nEnd-points of line inside the window: (%.1f, %.1f) & (%.1f, %.1f)\n", x1, y1, x2, y2);
    }
    else printf("\nLine outside the window\n");
}

int main(void){ 
    float x1 = 7, y1 = 9, x2 = 11, y2 = 4;
    CohenSutherland(x1, y1, x2, y2);
    return 0;
}