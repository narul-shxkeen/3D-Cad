#pragma once

#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "winged_edge.h"

class Renderer : protected QOpenGLFunctions {
public:
    Renderer();
    void initialize();
    void resize(int w, int h);
    void render();
    void rotate(float angle, float x, float y, float z);
    void translate(float x, float y, float z);

private:
    WingedEdge model;
    QMatrix4x4 projection;
    QMatrix4x4 modelView;
};