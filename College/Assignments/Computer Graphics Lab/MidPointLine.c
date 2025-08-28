#include<stdio.h>
#include<graphics.h>

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
	    dx=x1-x0;
	    dy=y1-y0;
	    x=x0;
	    y=y0;
	    p=dy-(0.5*dx);
	    while(x<x1){
		if(p>=0){
		   putpixel(x,y,7);
		   y=y+1;
		   p=p+dy-dx;
		}
		else{
		   putpixel(x,y,7);
		   p=p+dy;
		}
		x=x+1;
		delay(100);
	   }
}

int main(){
	   int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
	   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	   printf("\nEnter co-ordinates of first point(X0): ");
	   scanf("%d",&x0);
	   printf("\nEnter co-ordinates of first point(Y0): ");
	   scanf("%d",&y0);
	   printf("\nEnter co-ordinates of second point(X1): ");
	   scanf("%d",&x1);
	   printf("\nEnter co-ordinates of second point(Y1): ");
	   scanf("%d",&y1);
	   drawline(x0, y0, x1, y1);
	   getch();
	   return 0;
}
