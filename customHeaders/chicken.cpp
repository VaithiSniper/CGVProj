#include "egg.h"
#include <GL/glut.h>

Egg e1;
Chicken c1;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  c1.chickenDisplay(1);
  c1.chickenDisplay(2);
  c1.chickenDisplay(3);
  e1.drawEgg();
  e1.drawEgg();
  e1.drawEgg();
  glFlush();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, width, 0, height, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Simple Chicken");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
