#include "chicken.h"
#include <GL/glut.h>
using namespace std;

Chicken c1;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBindTexture(GL_TEXTURE_2D, c1.image_texture);
  glTexCoordPointer(2, GL_FLOAT, 0, c1.texCoords);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  c1.drawSquare();
  glFlush();
}

void myinit() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Chicken");
  glEnable(GL_TEXTURE_2D);

  c1.loadChickenImage();
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
}
