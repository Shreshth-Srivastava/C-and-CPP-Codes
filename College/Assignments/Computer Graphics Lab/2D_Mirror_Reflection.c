#include <stdio.h>

void reflectPoints(int x, int y, char axis) {
    int newX = x, newY = y;
    if (axis == 'x') {
        newY = -newY;
    } else if (axis == 'y') {
        newX = -newX;
    }
    printf("\nReflected Points: (%d, %d)", newX, newY);
}

int main() {
    int x, y;
    char axis;
    printf("Enter the coordinates of the points (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the axis of reflection (x or y): ");
    scanf(" %c", &axis);
    reflectPoints(x, y, axis);
    return 0;
}