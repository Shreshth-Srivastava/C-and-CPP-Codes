#include <stdio.h>

void reflectPoints(int x, int y, int z, char axis) {
    float newX = x;
    float newY = y;
    float newZ = z;
    if (axis == 'x') {
        newY = -newY;
        newZ = -newZ;
    } else if (axis == 'y') {
        newX = -newX;
        newZ = -newZ;
    } else if (axis == 'z') {
        newX = -newX;
        newY = -newY;
    }
    printf("\nReflected Points: (%f, %f, %f)", newX, newY, newZ);
}

int main() {
    int x, y, z;
    char axis;
    printf("\nEnter the coordinates of the points (x y z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter the axis of reflection (x, y, z): ");
    scanf(" %c", &axis);
    reflectPoints(x, y, z, axis);
    return 0;
}