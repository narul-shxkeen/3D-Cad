#pragma once

#include <vector>
#include <QVector3D>

struct Edge;
struct Face;

struct Vertex {
    QVector3D position;
    Edge* edge;
};

struct Edge {
    Vertex* start;
    Vertex* end;
    Face* left;
    Face* right;
    Edge* leftPrev;
    Edge* leftNext;
    Edge* rightPrev;
    Edge* rightNext;
};

struct Face {
    Edge* edge;
};

class WingedEdge {
public:
    bool loadFromFile(const std::string& filename);
    const std::vector<Vertex>& getVertices() const { return vertices; }
    const std::vector<Edge>& getEdges() const { return edges; }
    const std::vector<Face>& getFaces() const { return faces; }

private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Face> faces;
};