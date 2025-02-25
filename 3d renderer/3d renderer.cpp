#include <iostream> 
#include <GL/freeglut.h> 
#include "ObjFile.h" 
#include "Window.h"

ObjFile* objFile;
string windowName = "3D renderer"; 
// light position
GLfloat Lt0pos[] = { 1.0f, 1.0f, 5.0f, 1.0f };
Window* window;
// Function to initialize rendering settings
void initRendering() {
	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
	glEnable(GL_LIGHTING); // Enable lighting
	glEnable(GL_LIGHT0); // Enable light source 0
}

void drawScene(void) {

}
void reshapeFunc(int w, int h)
{
	// Always use the largest square viewport possible
	if (w > h) {
		glViewport((w - h) / 2, 0, h, h);
	}
	else {
		glViewport(0, (h - w) / 2, w, w);
	}

	// Set up a perspective view, with square aspect ratio
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 50 degree fov, uniform aspect ratio, near = 1, far = 100
	gluPerspective(50.0, 1.0, 1.0, 100.0);
}
void keyboardFunc(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27: // Escape key
		exit(0);
		break;
	case 'c':
		// add code to change color here
		//color = (rand() % 4) + 1;
		break;
	case 'r':
		//rotateObjectAlongY();
		cout << "rotated" << endl;
		break;
	default:
		cout << "Unhandled key press " << key << "." << endl;
	}

	// this will refresh the screen so that the user sees the color change
	glutPostRedisplay();
}


// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Lt0pos[1] = Lt0pos[1] + 0.5;
		break;
	case GLUT_KEY_DOWN:
		Lt0pos[1] = Lt0pos[1] - 0.5;
		break;
	case GLUT_KEY_LEFT:
		Lt0pos[0] = Lt0pos[0] - 0.5;
		break;
	case GLUT_KEY_RIGHT:
		Lt0pos[0] = Lt0pos[0] + 0.5;
		break;
	}
	glutPostRedisplay();
}


void reshapeFuncWrapper(int w, int h) {
    window->reShapeWindow(w, h);
}

int main(int argc, char** argv)
{
    objFile = new ObjFile("sphere.obj");

    // Initialize GLUT
    glutInit(&argc, argv);

    // Set the display mode for GLUT
    // GLUT_DOUBLE: Enable double buffering
    // GLUT_RGB: Use RGB color mode
    // GLUT_DEPTH: Enable depth buffer for 3D rendering
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    window = new Window(windowName, 800, 800, 100, 100);
    window->createWindow();

    initRendering(); // Initialize rendering settings

    // Set up callback functions for key presses
    glutKeyboardFunc(keyboardFunc); // Handles "normal" ascii symbols
    glutSpecialFunc(specialFunc);   // Handles "special" keyboard keys

    // Set up the callback function for resizing windows
    glutReshapeFunc(reshapeFuncWrapper);

    // Call this whenever window needs redrawing
    glutDisplayFunc(drawScene);

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop();
    return 0; // Return 0 to indicate successful execution
}
