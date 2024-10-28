#include <QApplication>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include "src/renderer.h"
#include "src/winged_edge.h"

class GLWidget : public QOpenGLWidget {
public:
    GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override {
        renderer.initialize();
    }

    void resizeGL(int w, int h) override {
        renderer.resize(w, h);
    }

    void paintGL() override {
        renderer.render();
    }

    void keyPressEvent(QKeyEvent *event) override {
        switch (event->key()) {
            case Qt::Key_Left:
                renderer.rotate(-5.0f, 0.0f, 1.0f, 0.0f);
                break;
            case Qt::Key_Right:
                renderer.rotate(5.0f, 0.0f, 1.0f, 0.0f);
                break;
            case Qt::Key_Up:
                renderer.rotate(-5.0f, 1.0f, 0.0f, 0.0f);
                break;
            case Qt::Key_Down:
                renderer.rotate(5.0f, 1.0f, 0.0f, 0.0f);
                break;
            case Qt::Key_W:
                renderer.translate(0.0f, 0.1f, 0.0f);
                break;
            case Qt::Key_S:
                renderer.translate(0.0f, -0.1f, 0.0f);
                break;
            case Qt::Key_A:
                renderer.translate(-0.1f, 0.0f, 0.0f);
                break;
            case Qt::Key_D:
                renderer.translate(0.1f, 0.0f, 0.0f);
                break;
        }
        update();
    }

private:
    Renderer renderer;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WingedEdge model;
    if (!model.loadFromFile("input.we")) {
        return -1;
    }

    QMainWindow window;
    GLWidget *glWidget = new GLWidget(&window);
    window.setCentralWidget(glWidget);
    window.resize(800, 600);
    window.show();

    return app.exec();
}