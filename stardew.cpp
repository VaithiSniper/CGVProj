#include <GL/glut.h>

void introbackground() {
  // Set background color
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw background
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.5, 1.0);
  glVertex2f(-1.0, 1.0);
  glVertex2f(-1.0, -1.0);
  glColor3f(0.0, 0.2, 0.5);
  glVertex2f(1.0, -1.0);
  glVertex2f(1.0, 1.0);
  glEnd();

  // Draw stars
  glPointSize(3.0);
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.5, 0.5);
  glVertex2f(-0.3, 0.7);
  glVertex2f(-0.1, 0.6);
  glVertex2f(0.2, 0.8);
  glVertex2f(0.4, 0.5);
  glVertex2f(0.6, 0.7);
  glVertex2f(0.8, 0.6);
  glVertex2f(-0.7, 0.4);
  glVertex2f(-0.9, 0.2);
  glVertex2f(-0.6, 0.1);
  glVertex2f(-0.4, -0.1);
  glVertex2f(-0.2, -0.3);
  glVertex2f(0.1, -0.5);
  glVertex2f(0.3, -0.2);
  glVertex2f(0.5, -0.4);
  glVertex2f(0.7, -0.3);
  glVertex2f(0.9, -0.1);
  glEnd();

  // Render
  glFlush();
}

int main(int argc, char **argv) {
  // Initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Stardew Valley Background");

  // Set display function
  glutDisplayFunc(display);

  // Enter main loop
  glutMainLoop();

  return 0;
}
