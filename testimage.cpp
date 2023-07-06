#include "headers/SOIL.c"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// int width = 480;
// int height = 640;

GLuint myImage;

static void loadImage() {
  myImage = SOIL_load_OGL_texture(
      "images/chicken.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
          SOIL_FLAG_COMPRESS_TO_DXT);
  if (0 == myImage) {
    printf("SOIL loading error: '%s'\n", SOIL_last_result());
  }
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GLUT_SINGLE | GLUT_RGB);
  glLoadIdentity();
  glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);
}

void display() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  loadImage();
  // glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
  // glEnable(GL_ALPHA_TEST);
  // glAlphaFunc(GL_EQUAL, 1.0);
  // glPixelZoom(1, 1);
  // glutSwapBuffers();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Testing images");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
