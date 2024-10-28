#include "winged_edge.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool WingedEdge::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            vertices.push_back({QVector3D(x, y, z), nullptr});
        } else if (type == "f") {
            int v1, v2, v3;
            iss >> v1 >> v2 >> v3;
            Face face;
            faces.push_back(face);

            Edge edge1, edge2, edge3;
            edges.push_back(edge1);
            edges.push_back(edge2);
            edges.push_back(edge3);

            // Set up the winged-edge structure
            // This is a simplified setup and doesn't handle all cases
            edges[edges.size() - 3].start = &vertices[v1 - 1];
            edges[edges.size() - 3].end = &vertices[v2 - 1];
            edges[edges.size() - 2].start = &vertices[v2 - 1];
            edges[edges.size() - 2].end = &vertices[v3 - 1];
            edges[edges.size() - 1].start = &vertices[v3 - 1];
            edges[edges.size() - 1].end = &vertices[v1 - 1];

            faces.back().edge = &edges[edges.size() - 3];

            // This is a simplified setup and doesn't handle all cases
            edges[edges.size() - 3].left = &faces.back();
            edges[edges.size() - 2].left = &faces.back();
            edges[edges.size() - 1].left = &faces.back();

            edges[edges.size() - 3].leftNext = &edges[edges.size() - 2];
            edges[edges.size() - 2].leftNext = &edges[edges.size() - 1];
            edges[edges.size() - 1].leftNext = &edges[edges.size() - 3];

            edges[edges.size() - 3].leftPrev = &edges[edges.size() - 1];
            edges[edges.size() - 2].leftPrev = &edges[edges.size() - 3];
            edges[edges.size() - 1].leftPrev = &edges[edges.size() - 2];
        }
    }

    return true;
}