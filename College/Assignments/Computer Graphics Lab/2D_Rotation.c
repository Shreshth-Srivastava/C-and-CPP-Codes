#include <stdio.h>
#include <math.h>

void rotatePoints(int x, int y, float angle) {
    float radian = angle * 3.14 / 180.0;

    float cosTheta = cos(radian);
    float sinTheta = sin(radian);

    float newX = x * cosTheta - y * sinTheta;
    float newY = x * sinTheta + y * cosTheta;

    printf("\nRotated Points: (%f, %f)", newX, newY);

}

int main() {
    int x, y;
    float angle;

    printf("Enter the coordinates of the points (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);

    rotatePoints(x, y, angle);

    return 0;
}