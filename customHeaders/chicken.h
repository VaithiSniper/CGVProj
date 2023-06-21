// chicken co-ordinates
#define CHICKEN1_X 115.0f
#define CHICKEN2_X 255.0f
#define CHICKEN3_X 390.0f
// chicken drawing related
#define CHICKEN_SCALE_FACTOR 100.0f
// include libraries
#include <GL/glew.h>
#include <cstdio>
#include <math.h>

using namespace std;

typedef GLfloat VERTEX[3];

class Chicken {
public:
  void chickenDisplay(int chickenNumber) {
    glTranslatef(getXChickenPosition(chickenNumber), 500.0f, 0.0f);
    // Scale the chicken to make it larger
    glScalef(CHICKEN_SCALE_FACTOR, CHICKEN_SCALE_FACTOR, 1.0f);
    drawChicken();
    glLoadIdentity();
    glFlush();
  }

  GLfloat getXChickenPosition(int chickenNumber) {
    switch (chickenNumber) {
    case 1:
      return CHICKEN1_X;
      break;
    case 2:
      return CHICKEN2_X;
      break;
    case 3:
      return CHICKEN3_X;
      break;
    default:
      return 0;
    }
  }

private:
  void drawChicken() {
    // Body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glEnd();

    // Eyes
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glVertex2f(-0.05f, 0.05f);
    glVertex2f(0.05f, 0.05f);
    glEnd();

    // Beak
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05f, -0.05f);
    glVertex2f(-0.05f, -0.05f);
    glEnd();

    // Comb (Red crest on the head)
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.0f, 0.3f);
    glEnd();

    // Legs
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glVertex2f(-0.05f, -0.2f);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, -0.3f);
    glEnd();
  }
};
// end of class
