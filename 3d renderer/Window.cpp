#include "Window.h"
#include <GL/freeglut_std.h>



Window::Window(string title, int width, int height, int x, int y) : title(title), width(width), height(height), x(x), y(y)
{
	
}

void Window::reShapeWindow(int width, int height)
{
    // Always use the largest square viewport possible
    if (width > height) {
        glViewport((width - height) / 2, 0, height, height);
    }
    else {
        glViewport(0, (height - width) / 2, width, width);
    }

    // Set up a perspective view, with square aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 50 degree fov, uniform aspect ratio, near = 1, far = 100
    gluPerspective(50.0, 1.0, 1.0, 100.0);
}

void Window::createWindow()
{
    // intialising the window
    glutInitWindowPosition(x, y);
    glutInitWindowSize(width, height);
    glutCreateWindow(title.c_str());
}
