#include "Polyhedron.h"
#include <fstream>
#include <sstream>

bool Polyhedron::loadFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'v') {
            // Vertex
            Vertex v;
            iss >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        } else if (type == 'e') {
            // Edge
            Edge e;
            iss >> e.v1 >> e.v2;
            edges.push_back(e);
        } else if (type == 'f') {
            // Face
            Face f;
            int edgeIndex;
            while (iss >> edgeIndex) {
                f.edgeIndices.push_back(edgeIndex);
            }
            faces.push_back(f);
        }
    }

    file.close();
    return true;
}

bool Polyhedron::saveToFile(const std::string &fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) return false;

    for (const auto &v : vertices) {
        file << "v " << v.x << " " << v.y << " " << v.z << "\n";
    }
    for (const auto &e : edges) {
        file << "e " << e.v1 << " " << e.v2 << "\n";
    }
    for (const auto &f : faces) {
        file << "f";
        for (int ei : f.edgeIndices) {
            file << " " << ei;
        }
        file << "\n";
    }

    file.close();
    return true;
}

std::vector<Vertex>& Polyhedron::getVertices() {
    return vertices;
}

const std::vector<Vertex>& Polyhedron::getVertices() const {
    return vertices;
}
