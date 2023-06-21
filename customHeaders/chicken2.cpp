
#include <GL/glut.h>
#include <cmath>

void drawChicken() {
  // Body
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 0.0f); // Yellow color

  float radius = 0.1f;
  int numSegments = 100;
  for (int i = 0; i < numSegments; ++i) {
    float theta = 2.0f * 3.1415926f * static_cast<float>(i) /
                  static_cast<float>(numSegments);
    float x = radius * cos(theta);
    float y = radius * sin(theta);
    glVertex2f(x, y);
  }
  glEnd();

  // Beak
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.6f, 0.2f); // Orange color
  glVertex2f(0.0f, radius);
  glVertex2f(-0.03f, radius - 0.05f);
  glVertex2f(0.03f, radius - 0.05f);
  glEnd();

  // Eyes
  glPointSize(3.0f);
  glBegin(GL_POINTS);
  glColor3f(0.0f, 0.0f, 0.0f); // Black color
  glVertex2f(-0.02f, radius + 0.02f);
  glVertex2f(0.02f, radius + 0.02f);
  glEnd();

  // Legs
  glLineWidth(2.0f);
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 0.0f); // Black color
  glVertex2f(-0.03f, -radius);
  glVertex2f(-0.03f, -radius - 0.1f);

  glVertex2f(0.03f, -radius);
  glVertex2f(0.03f, -radius - 0.1f);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  // Move chicken to the center of the window
  glTranslatef(0.5f, 0.5f, 0.0f);

  // Scale the chicken to make it larger
  glScalef(1.0f, 1.0f, 1.0f);

  drawChicken();

  glFlush();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Complex Chicken");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
