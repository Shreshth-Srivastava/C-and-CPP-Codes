#include <stdio.h>
#include <math.h>

void rotatePoints(int x, int y, int z, char axis, float angle) {
    float radian = angle * 3.14 / 180.0;
    float newX, newY, newZ;
    newX = x;
    newY = y;
    newZ = z;
    if (axis == 'x') {
        newY = y * cos(radian) - z * sin(radian);
        newZ = y * sin(radian) + z * cos(radian);
    } else if (axis == 'y') {
        newX = x * cos(radian) + z * sin(radian);
        newZ = -x * sin(radian) + z * cos(radian);
    } else if (axis == 'z') {
        newX = x * cos(radian) - y * sin(radian);
        newY = x * sin(radian) + y * cos(radian);
    }
    printf("\nRotated Points: (%f, %f, %f)", newX, newY, newZ);
}

int main() {
    int x, y, z;
    char axis;
    float angle;
    printf("\nEnter the coordinates of the points (x y z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter the axis of rotation (x, y, z): ");
    scanf(" %c", &axis);
    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);
    rotatePoints(x, y, z, axis, angle);
    return 0;
}
