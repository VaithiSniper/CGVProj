#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#define CIRCLE_RADIUS 0.15f
#define PI 3.14159265358979323846

unsigned int intro;

int eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0;

// typeOfEgg denotes the type of egg, if 1 it is white egg (normal), else it
// is gold (special)
int typeOfEgg;
int egg_xc, egg_yc;
// for coordinates of egg
int basket_x, basket_y;
// for coordinates of basket
int a = 600, b = 650; // for default size of the screen
int s = 0;
// for menu option
int dropped_eggs = 0;
double speed_1 = 1, speed_2 = 1.5, speed_3 = 2, speed_4 = 2.5;
int w = 48, h = 48, t = 10, e = 9, g = 12;
void myinit();
void start_screen(int, int);
void displayIntro();
void cloud1();
void egg();
void drawLine(int *, int *);
void basket(int, int);
void duck(int, int);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int, int);
void myReshape(int, int);
void keys(unsigned char, int, int);
void menu(int);
void myinit()
{
  glViewport(0, 0, a, b);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, (GLdouble)a, 0, (GLdouble)b);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

void sun()
{

  float theta;

  GLfloat angle;
  glLineWidth(1.5);
  glColor3f(1, 0.2, 0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(500 + 80 * cos(theta) / 2, 600 + 80 * sin(theta) / 2);
  }

  glEnd();
  glFlush();
}

void cloud1()
{

  float theta;

  GLfloat angle;
  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(100 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
  }

  glEnd();
  // GLfloat angle;
  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(130 + 50 * cos(theta) / 2, 580 + 50 * sin(theta) / 2);
  }
  glEnd();

  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(140 + 50 * cos(theta) / 2, 600 + 50 * sin(theta) / 2);
  }
  glEnd();

  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(170 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);
  }

  glEnd();
  glFlush();
}

void cloud2()
{
  float theta;
  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(420 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
  }

  glEnd();

  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(455 + 45 * cos(theta) / 2, 550 + 45 * sin(theta) / 2);
  }

  glEnd();

  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(455 + 45 * cos(theta) / 2, 530 + 45 * sin(theta) / 2);
  }

  glEnd();

  glLineWidth(1.5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    theta = i * PI * i / 180;
    glVertex2f(490 + 45 * cos(theta) / 2, 540 + 45 * sin(theta) / 2);
  }

  glEnd();
  glFlush();
}

void line(int i, int j)
{

  glBegin(GL_QUADS);
  glColor3f(1.0, .5, 0.5);
  glVertex2f(0.0 + i, 10.0 + j);
  glVertex2f(0.0 + i, 15.0 + j);
  glVertex2f(600.0 + i, 15.0 + j);
  glVertex2f(600.0 + i, 10.0 + j);
  glEnd();
  glFlush();
}

void backk(int i, int j)
{

  glColor3f(0, .5, 1);
  glBegin(GL_QUADS);
  glVertex2f(0.0 + i, 0.0 + j);
  glVertex2f(600.0 + i, 0.0 + j);
  glVertex2f(600.0 + i, -500 + j);
  glVertex2f(0.0 + i, -500 + j);
  glEnd();
  glFlush();
}
void ground(int i, int j)
{

  glBegin(GL_QUADS);
  glColor3f(0, 1.0, 0);
  glVertex2f(0.0 + i, 0.0 + j);
  glVertex2f(600.0 + i, 0.0 + j);
  glVertex2f(600.0 + i, -j);
  glVertex2f(0.0 + i, -j);
  glEnd();
}

void start_screen()
{
  // Set background color
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw background
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.5, 1.0);
  glVertex2f(-800.0, 900.0);
  glVertex2f(-800.0, -800.0);
  glColor3f(0.0, 0.2, 0.5);
  glVertex2f(800.0, -800.0);
  glVertex2f(800.0, 800.0);
  glEnd();

  // Draw stars
  glPointSize(4.0);
  glBegin(GL_POINTS);
  glColor3f(1.0, 1.0, 1.0);
  for (int i = 0; i <= 10; i++)
  {
    int x = rand() % 600;
    int y = rand() % 600;
    glVertex2f(x, y);
  }
  glEnd();

  int k;
  char cat[4] = "EGG";
  char orr[9] = "Catching";
  char hatch[5] = "Game";
  char start[20] = "Press S for start";
  char authors[8] = "Made by";
  char author1[16] = "Vaitheeswaran J";
  char author2[8] = "Shivani";

  glColor3f(0, 1, 0);
  glRasterPos2i(150, 320);
  for (k = 0; k < 4; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[k]);
  glColor3f(1, 1, 1);
  glRasterPos2i(200, 320);
  for (k = 0; k < 9; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orr[k]);
  glColor3f(1, 0, 0);
  glRasterPos2i(300, 320);
  for (k = 0; k < 5; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hatch[k]);
  glColor3f(1, 1, 0);
  glRasterPos2i(210, 200);
  for (k = 0; k < 20; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);
  glRasterPos2i(400, 50);
  for (k = 0; k < 8; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, authors[k]);
  glRasterPos2i(400, 30);
  for (k = 0; k < 16; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, author1[k]);
  glRasterPos2i(400, 10);
  for (k = 0; k < 8; k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, author2[k]);
  glColor3f(1, .5, .5);

  glFlush();
  glutSwapBuffers();
}

void loadIntro(void)
{
  glGenTextures(1, &intro);
  glBindTexture(GL_TEXTURE_2D, intro);
  // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load and generate the bg1
  int width, height, nrChannels;
  unsigned char *data = stbi_load("introBanner.psd", &width, &height,
                                  &nrChannels, STBI_rgb_alpha);
  if (data)
  {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, data);
    // glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cout << "Failed to load bg1" << std::endl;
  }
  stbi_image_free(data);
}

void displayIntro()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
  glColor3f(1, 1, 1);
  glBindTexture(GL_TEXTURE_2D, intro);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 10);
  glTexCoord2f(0, 0);
  glVertex3f(0, 5000, 10);
  glTexCoord2f(0, 1);
  glVertex3f(5000, 5000, 10);
  glTexCoord2f(1, 1);
  glVertex3f(5000, 0, 10);
  glTexCoord2f(1, 0);
  glEnd();
  glFlush();
  glDisable(GL_TEXTURE_2D);
  glutSwapBuffers();
}

void egg()
{
  float x, y, z;
  int t;
  if (typeOfEgg == 1)
    glColor3f(1.0, 1.0, 1.0);
  else if (typeOfEgg == 2)
    glColor3f(0.05, 0.33, 0.04);
  else
    glColor3f(1.0, 0.843, 0);
  glBegin(GL_POLYGON);
  for (t = 0; t <= 360; t += 1)
  {
    x = egg_xc + 8 * (cos(t));
    y = egg_yc + 16 * (sin(t));
    z = 0;
    glVertex3f(x, y, z);
  }
  glEnd();
}

void basket(int i, int j)
{
  j = 10;
  if (i >= a - 60)
    i = a - 60;
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
  glVertex2f(0.0 + i, 30.0 + j);
  glVertex2f(10.0 + i, 10.0 + j);
  glVertex2f(50.0 + i, 10.0 + j);
  glVertex2f(60.0 + i, 30.0 + j);
  glEnd();
}
void duck(int i, int j)
{
  int h;
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(45 + i, 45 + j);
  glVertex2f(70 + i, 20 + j);
  glVertex2f(95 + i, 20 + j);
  glVertex2f(120 + i, 45 + j);
  glVertex2f(95 + i, 70 + j);
  glVertex2f(70 + i, 70 + j);
  glVertex2f(95 + i, 95 + j);
  glVertex2f(82.5 + i, 107.5 + j);
  glVertex2f(32.5 + i, 57.5 + j);
  glEnd();
  glFlush();
  for (h = 0; h < 13; h += 4)
  {
    glBegin(GL_LINES);
    glColor3f(0.7, 0.4, 0);
    glVertex2f(57.5 + h + i, 52.5 + h + j);
    glVertex2f(100 + h + i, 30 + h + j);
    glEnd();
    glFlush();
  }
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(82.5 + i, 107.5 + j);
  glVertex2f(65 + i, 107.5 + j);
  glVertex2f(50 + i, 95 + j);
  glVertex2f(70 + i, 95 + j);
  glEnd();
  glFlush();
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2f(76 + i, 101 + j);
  glEnd();
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(72.5 + i, 107.5 + j);
  glVertex2f(67.5 + i, 112.5 + j);
  glVertex2f(72.5 + i, 110 + j);
  glVertex2f(77.5 + i, 112.5 + j);
  glEnd();
  glFlush();
}

void displayScore()
{

  std::string::iterator k;

  // Set background color
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw background
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.5, 1.0);
  glVertex2f(-800.0, 900.0);
  glVertex2f(-800.0, -800.0);
  glColor3f(0.0, 0.2, 0.5);
  glVertex2f(800.0, -800.0);
  glVertex2f(800.0, 800.0);
  glEnd();

  // Draw stars
  glPointSize(2.0);
  glBegin(GL_POINTS);
  glVertex2f(300, 300);
  glColor3f(1.0, 1.0, 1.0);
  for (int i = 0; i <= 10; i++)
  {
    int x = rand() % 600;
    int y = rand() % 600;
    glVertex2f(x, y);
  }
  glEnd();

  char cat[11] = "Scoreboard";
  char eggTotal[11] = "Total eggs";
  char eggCaught[12] = "Eggs caught";
  char eggMissed[12] = "Eggs missed";
  std::string eggTotalValue = std::to_string(dropped_eggs);
  std::string eggCaughtValue = std::to_string(eggs_caught);
  std::string eggMissedValue = std::to_string(missed_eggs);

  int kc;

  glColor3f(0, 1, 0);
  glRasterPos2i(260, 540);
  for (kc = 0; kc < 11; kc++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[kc]);
  glColor3f(1, 1, 1);
  glRasterPos2i(180, 450);
  for (kc = 0; kc < 11; kc++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, eggTotal[kc]);
  glRasterPos2i(180, 390);
  for (kc = 0; kc < 11; kc++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, eggCaught[kc]);
  glColor3f(1, 0, 0);
  glRasterPos2i(180, 330);
  for (kc = 0; kc < 12; kc++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, eggMissed[kc]);

  glColor3f(1, 1, 1);
  glRasterPos2i(320, 450);
  for (k = eggTotalValue.begin(); k != eggTotalValue.end(); k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *k);
  glRasterPos2i(320, 390);
  for (k = eggCaughtValue.begin(); k != eggCaughtValue.end(); k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *k);
  glColor3f(1, 0, 0);
  glRasterPos2i(320, 330);
  for (k = eggMissedValue.begin(); k != eggMissedValue.end(); k++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *k);

  glColor3f(1, 1, 1);
  int p1[2] = {300, 300};
  int p2[2] = {300, 500};
  drawLine(p1, p2);

  // int p3[2] = {180, 320};
  // int p4[2] = {320, 320};
  // drawLine(p3, p4);

  // int p5[2] = {180, 350};
  // int p6[2] = {320, 350};
  // drawLine(p5, p6);

  glFlush();
  glutSwapBuffers();
}

void drawLine(int *p1, int *p2)
{
  glLineWidth(2);
  glBegin(GL_LINES);
  glVertex2iv(p1);
  glVertex2iv(p2);
  glEnd();
}

void print_score()
{
  printf("\nLevel reached: %d\n\n", level_count);
  printf("\nNo. of eggs dropped= %d \n", dropped_eggs);
  printf("\nNo. of eggs caught = %d\n", eggs_caught);
  printf("\nNo. of eggs missed = %d\n", missed_eggs);

  getchar();
  exit(0);
}
void egg_start()
{
  egg_yc = 375;
  if (missed_eggs >= 10)
  {
    printf("\n\n\t\t\t\tGAME OVER\n\n");
    print_score();
  }

  int temp = rand() % 8;
  if (temp == 0)
    typeOfEgg = 0;
  else if (temp == 7 || temp == 3)
    typeOfEgg = 2;
  else
    typeOfEgg = 1;

  if (typeOfEgg != 2)
    dropped_eggs++;

  switch (rand() % 9)
  {
  case 0:
    egg_xc = 115;
    break;
  case 1:
    egg_xc = 255;
    break;
  case 2:
    egg_xc = 390;
    break;
  case 5:
    egg_xc = 115;
    break;
  case 3:
    egg_xc = 255;
    break;
  case 4:
    egg_xc = 390;
    break;
  case 7:
    egg_xc = 115;
    break;
  case 6:
    egg_xc = 255;
    break;
  case 8:
    egg_xc = 390;
    break;
  }
}

void score()
{
  if (egg_yc <= 50 && (egg_xc >= basket_x && egg_xc <= basket_x + 60))
  {
    printf("\a");
    if (typeOfEgg == 0)
      eggs_caught += 3;
    else if (typeOfEgg == 2)
      eggs_caught--;
    else
      eggs_caught++;
    egg_yc = -10;
  }
  missed_eggs = dropped_eggs - eggs_caught;
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  ground(0, 650);
  backk(0, 650);
  duck(40, 375);
  duck(180, 375);
  duck(320, 375);
  sun();
  cloud1();
  cloud2();
  line(0, 375);

  int i;
  char level1[12] = "LEVEL 1";
  char level2[12] = "LEVEL 2";
  char level3[12] = "LEVEL 3";
  char level4[12] = "LEVEL 4";

  if (s >= 1)
  {
    if (level_count == 1)
    {
      glColor3f(1, 1, 1);
      glRasterPos2i(500, 300);
      for (i = 0; i < 12; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level1[i]);
    }
    else if (level_count == 2)
    {
      glColor3f(1, 0, 0);
      glRasterPos2i(500, 300);
      for (i = 0; i < 12; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level2[i]);
    }
    else if (level_count == 3)
    {
      glColor3f(0, 1, 1);
      glRasterPos2i(500, 300);
      for (i = 0; i < 12; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level3[i]);
    }
    if (level_count == 4)
    {
      glColor3f(1, 0, 1);
      glRasterPos2i(500, 300);
      for (i = 0; i < 12; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level4[i]);
    }

    if (egg_yc <= 10)
      egg_start();

    egg();
    basket(basket_x, basket_y);
    if (eggs_caught >= 10)
    {
      egg_yc -= speed_2;
      level_count = 2;
    }
    if (eggs_caught >= 20)
    {
      egg_yc -= speed_3;
      level_count = 3;
    }
    if (eggs_caught >= 30)
    {
      egg_yc -= speed_4;
      level_count = 4;
    }
    else
      egg_yc -= speed_1;
    score();
  }
  glFlush();
  glutSwapBuffers();
}
void basket_set(int a, int b)
{
  basket_x = a;
  basket_y = b;
  glutPostRedisplay();
}
void myReshape(int w, int h)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glViewport(0, 0, w, h);
  a = w;
  b = h;
}
void keys(unsigned char key, int x, int y)
{
  if (key == 'q' || key == 'Q')
  {
    glutDisplayFunc(displayScore);
    glutIdleFunc(displayScore);
    glutPostRedisplay();
    // printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
    // print_score();
  }
  if (key == 's' || key == 'S')
  {
    s += 1;
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutPostRedisplay();
  }

  if (key == 'a' || key == 'A')
  {
    egg_xc -= 10;
    if (egg_xc <= 0)
      egg_xc = 10;
  }
  if (key == 'd' || key == 'D')
  {
    egg_xc += 10;
    if (egg_xc >= 500)
      egg_xc = 490;
  }
}
void menu(int id)
{
  switch (id)
  {
  case 1:
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutPostRedisplay();
    s += 1;
    break;
  case 2:
    glutDisplayFunc(displayScore);
    glutIdleFunc(displayScore);
    glutPostRedisplay();
    break;
  case 3:
    printf("\n\n\n\t\tQUIT BY PLAYER\n");
    exit(0);
    break;
  default:
    exit(0);
  }
  glutPostRedisplay();
}
int main(int argc, char **argv)
{
  printf("******************************************************************");
  printf("\n\t\t\t\t EGG GAME\n\n");
  printf("******************************************************************");
  printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the "
         "eggs in the basket.\n\t To move Basket use mouse.\n");
  printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse "
         "button then click 'Start Game'.\n");
  printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right "
         "mouse button then click 'Quit'.\n");
  printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");
  printf("\nFor each level, speed is Increased\n\n");
  printf("\n\nBEST OF LUCK\n");

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(a, b);
  glutCreateWindow("EGG GAME");
  myinit();
  glutInitWindowPosition(100, 100);
  glutCreateMenu(menu);
  glutAddMenuEntry("Start game", 1);
  glutAddMenuEntry("View score", 2);
  glutAddMenuEntry("Quit without score", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutDisplayFunc(start_screen);
  // loadIntro();
  // glutDisplayFunc(display);
  glutKeyboardFunc(keys);
  glutPassiveMotionFunc(basket_set);
  glutReshapeFunc(myReshape);
  glutMainLoop();
}
