#include <GL/glut.h>
#include <iostream>
#include <math.h>

void drawBarn() {
  // Draw the barn using OpenGL
  glBegin(GL_QUADS);
  glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
  glVertex2f(-0.5f, -0.5f);    // Bottom left corner
  glVertex2f(0.5f, -0.5f);     // Bottom right corner
  glVertex2f(0.5f, 0.5f);      // Top right corner
  glVertex2f(-0.5f, 0.5f);     // Top left corner
  glEnd();
}

void drawEgg(float x, float y) {
  // Draw an egg using OpenGL
  glPushMatrix();
  glTranslatef(x, y, 0.0f); // Translate to the specified position
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
  for (int i = 0; i < 360; i++) {
    float rad = i * 3.14159 / 180;
    glVertex2f(cos(rad) * 0.05f, sin(rad) * 0.1f);
  }
  glEnd();
  glPopMatrix();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawBarn();
  drawEgg(-0.2f, 0.2f);
  drawEgg(0.2f, -0.2f);
  drawEgg(0.0f, 0.0f);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Farm");
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
