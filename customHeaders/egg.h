#include "chicken.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include <math.h>

using namespace std;

class Egg {
public:
  // store the egg's x and y co-ordinates
  int x_coordinate, y_coordindate;
  /*
   * ENUM that determines the type of egg.
   * The mapping denotes the score obtained on catching that corresponding egg
   * Gold egg is special and thus awards 2 points
   * White is normal and thus awards 1 point
   * Green is bad and thus awards -1 point, i.e, it reduces the player's point
   */
  enum typeOfEgg { gold = 2, white = 1, green = -1 };
  // store the type of egg
  typeOfEgg eggType;
  // overview public FUNCTION to draw an egg
  void drawEgg() {
    // refresh egg
    eggRefresh();
    glTranslatef(x_coordinate, 300.0f, 0.0f);
    // Scale the chicken to make it larger
    glScalef(CHICKEN_SCALE_FACTOR, CHICKEN_SCALE_FACTOR, 1.0f);
    // determine type of egg and set color
    getEggType();
    openGLSetEggColor();
    // draw the egg using openGL functions
    openGLDrawEgg();
    glLoadIdentity();
    glFlush();
  }

private:
  Chicken c1;
  void openGLSetEggColor() {
    if (eggType == white)
      glColor3f(1.0, 1.0, 1.0);
    else if (eggType == gold)
      glColor3f(0.05, 0.33, 0.04);
    else
      glColor3f(1.0, 0.843, 0);
  }

  void openGLDrawEgg() {
    float x, y, z;
    glBegin(GL_POLYGON);
    for (int t = 0; t <= 360; t++) {
      x = x_coordinate + 8 * (cos(t));
      y = y_coordindate + 16 * (sin(t));
      z = 0;
      glVertex3f(x, y, z);
      glEnd();
    }
  }

  void getEggType() {
    /*
     * We consider out of 8 chances
     * There is 1 chance of getting gold
     * There is 2 chances of getting green
     * There are 5 chances of getting white
     */
    int choice = rand() % 8;
    switch (choice) {
    case 0:
      eggType = gold;
      break;
    case 1:
    case 2:
      eggType = green;
      break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      eggType = green;
      break;
    default:
      printf("Out of bounds...\n");
    }
  }

  int getSourceChickenCoordinate() {
    /*
     * We consider out of 3 chances
     * There is 1 chance of each chicken dropping the egg
     * Find the chicken and return its corresponding X coordinate
     */
    int choice = rand() % 3;
    return c1.getXChickenPosition(choice + 1);
  }

  void eggRefresh() {
    // reset egg x_coordinate and y_coordindate
    y_coordindate = 300.0f;
    x_coordinate = getSourceChickenCoordinate();
  }
};
// end of class
