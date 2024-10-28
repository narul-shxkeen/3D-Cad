#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include <vector>
#include <string>

struct Vertex {
    float x, y, z;
};

struct Edge {
    int v1, v2; // Indices to the vertex array
};

struct Face {
    std::vector<int> edgeIndices; // Indices to the edge array
};

class Polyhedron {
public:
    bool loadFromFile(const std::string &fileName);
    bool saveToFile(const std::string &fileName);

    std::vector<Vertex>& getVertices();  // Provide access to vertices
    const std::vector<Vertex>& getVertices() const;

private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Face> faces;
};

#endif
