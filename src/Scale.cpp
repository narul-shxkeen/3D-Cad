#include "Scale.h"

void scale(Polyhedron &polyhedron, float sx, float sy, float sz) {
    for (auto &v : polyhedron.getVertices()) {
        v.x *= sx;
        v.y *= sy;
        v.z *= sz;
    }
}
