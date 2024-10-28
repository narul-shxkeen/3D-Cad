#include "Rotate.h"
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Helper to convert degrees to radians
float degreesToRadians(float degrees) {
    return degrees * M_PI / 180.0;
}

void rotate(Polyhedron &polyhedron, float angleDegrees, float rx, float ry, float rz) {
    // Normalize the axis of rotation
    float magnitude = std::sqrt(rx * rx + ry * ry + rz * rz);
    
    if (magnitude == 0) {
        std::cerr << "Error: Rotation axis cannot be a zero vector!" << std::endl;
        return;
    }
    
    // Normalize the axis
    rx /= magnitude;
    ry /= magnitude;
    rz /= magnitude;

    // Convert the angle to radians
    float angle = degreesToRadians(angleDegrees);
    float cosA = std::cos(angle);
    float sinA = std::sin(angle);

    for (auto &v : polyhedron.getVertices()) {
        float newX = v.x * (cosA + rx * rx * (1 - cosA)) + v.y * (rx * ry * (1 - cosA) - rz * sinA) + v.z * (rx * rz * (1 - cosA) + ry * sinA);
        float newY = v.x * (ry * rx * (1 - cosA) + rz * sinA) + v.y * (cosA + ry * ry * (1 - cosA)) + v.z * (ry * rz * (1 - cosA) - rx * sinA);
        float newZ = v.x * (rz * rx * (1 - cosA) - ry * sinA) + v.y * (rz * ry * (1 - cosA) + rx * sinA) + v.z * (cosA + rz * rz * (1 - cosA));
        
        v.x = newX;
        v.y = newY;
        v.z = newZ;
    }
}
