#include <stdio.h>

void translatePoints(int x, int y, int tx, int ty) {
    int newX = x + tx;
    int newY = y + ty;
    printf("\nNew Co-ordinates : (%d, %d)", newX, newY);
}

int main() {
    int x, y, tx, ty;

    printf("Enter the coordinates of the points (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the translation vector (tx ty): ");
    scanf("%d %d", &tx, &ty);

    translatePoints(x, y, tx, ty);

    return 0;
}