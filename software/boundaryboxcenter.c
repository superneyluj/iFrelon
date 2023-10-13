#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
} BoundingBox;

typedef struct {
    unsigned int centerX;
    unsigned int centerY;
} BoxCenter;

BoxCenter getBoundingBoxCenter(BoundingBox bb) {
    BoxCenter center;
    center.centerX = bb.x + bb.width / 2;
    center.centerY = bb.y + bb.height / 2;
    return center;
}

int main(){

    BoundingBox myBox = {100, 100, 50, 50}; // Exemple de coordonnées
    BoxCenter center = getBoundingBoxCenter(myBox);
    printf("Center: (%u, %u)\n", center.centerX, center.centerY);
    return 0;
}