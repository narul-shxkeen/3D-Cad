#include "Translate.h"

void translate(Polyhedron &polyhedron, float tx, float ty, float tz) {
    for (auto &v : polyhedron.getVertices()) {
        v.x += tx;
        v.y += ty;
        v.z += tz;
    }
}
