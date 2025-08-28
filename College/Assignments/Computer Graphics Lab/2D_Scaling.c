#include <stdio.h>

void scalePoints(int x, int y, float sx, float sy) {
    float newX = x * sx;
    float newY = y * sy;
    printf("\nScaled Points: (%f, %f)", newX, newY);
}

int main() {
    int x, y;
    float sx, sy;

    printf("Enter the coordinates of the points (x y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    scalePoints(x, y, sx, sy);

    return 0;
}
