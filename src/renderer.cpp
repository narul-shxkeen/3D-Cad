#include "renderer.h"
#include "transformation.h"
#include <QOpenGLShaderProgram>

Renderer::Renderer() {}

void Renderer::initialize() {
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
    float aspect = float(w) / float(h ? h : 1);
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QOpenGLShaderProgram program;
    program.addShaderFromSourceCode(QOpenGLShader::Vertex,
        "attribute vec3 vertex;\n"
        "uniform mat4 matrix;\n"
        "void main() {\n"
        "   gl_Position = matrix * vec4(vertex, 1.0);\n"
        "}");
    program.addShaderFromSourceCode(QOpenGLShader::Fragment,
        "void main() {\n"
        "   gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
        "}");
    program.link();
    program.bind();

    QMatrix4x4 matrix = projection * modelView;
    program.setUniformValue("matrix", matrix);

    const auto& vertices = model.getVertices();
    const auto& edges = model.getEdges();

    QVector<QVector3D> lineVertices;
    for (const auto& edge : edges) {
        lineVertices.push_back(edge.start->position);
        lineVertices.push_back(edge.end->position);
    }

    program.enableAttributeArray("vertex");
    program.setAttributeArray("vertex", lineVertices.constData());
    glDrawArrays(GL_LINES, 0, lineVertices.size());
    program.disableAttributeArray("vertex");

    program.release();
}

void Renderer::rotate(float angle, float x, float y, float z) {
    modelView *= rotationMatrix(angle, x, y, z);
}

void Renderer::translate(float x, float y, float z) {
    modelView *= translationMatrix(x, y, z);
}