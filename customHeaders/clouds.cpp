#include <GL/glut.h>
#include <ctime>
#include <math.h>
#include <stdlib.h>

#define MAX_CLOUDS 5
#define MAX_CLOUD_RADIUS 0.1f

typedef struct {
  float x;
  float y;
  float radius;
} Cloud;

Cloud clouds[MAX_CLOUDS];

void initClouds() {
  for (int i = 0; i < MAX_CLOUDS; ++i) {
    clouds[i].x = (float)(rand() % 21) / 20.0f -
                  0.5f; // Random x-coordinate between -0.5 and 0.5
    clouds[i].y = (float)(rand() % 21) / 20.0f -
                  0.5f; // Random y-coordinate between -0.5 and 0.5
    clouds[i].radius = (float)(rand() % 11) / 100.0f +
                       0.05f; // Random radius between 0.05 and 0.15
  }
}

void drawCloud(float x, float y, float radius) {
  const int numSegments = 100;
  const float angle = 2.0f * 3.1415926f / numSegments;
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f, 1.0f, 1.0f); // White color for clouds
  glVertex2f(x, y);            // Center of the cloud
  for (int i = 0; i <= numSegments; ++i) {
    float theta = i * angle;
    float px = x + radius * cos(theta);
    float py = y + radius * sin(theta);
    glVertex2f(px, py);
  }
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  for (int i = 0; i < MAX_CLOUDS; ++i) {
    drawCloud(clouds[i].x, clouds[i].y, clouds[i].radius);
  }

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
  glutCreateWindow("Clouds");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  srand(time(NULL)); // Initialize random seed
  initClouds();

  glutMainLoop();
  return 0;
}
