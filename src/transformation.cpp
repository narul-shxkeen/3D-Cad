#include "transformation.h"
#include <cmath>

QMatrix4x4 rotationMatrix(float angle, float x, float y, float z) {
    QMatrix4x4 matrix;
    matrix.rotate(angle, x, y, z);
    return matrix;
}

QMatrix4x4 translationMatrix(float x, float y, float z) {
    QMatrix4x4 matrix;
    matrix.translate(x, y, z);
    return matrix;
}