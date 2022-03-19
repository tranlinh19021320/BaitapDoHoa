#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


GLfloat oldx=500, oldy=500;
void koch(GLdouble dir, GLint itr)
{
  GLfloat newx;
  GLfloat newy;
  GLdouble rdir = 3.14159265358979323846/180.0 * dir;
  newx = oldx + 3 * cos(rdir);
  newy = oldy + 3 * sin(rdir);

  if(itr==0)
  {
    glVertex2f(oldx, oldy);
    glVertex2f(newx, newy);
    oldx = newx;
    oldy = newy;
  }

  else
  {
    itr--;
    koch(dir, itr);
    dir+=60;
    koch(dir, itr);
    dir-=120;
    koch(dir, itr);
    dir+=60;
    koch(dir, itr);
  }
}

GLfloat i=4;
void display()
{
  glColor3f(1,0,0);
  glBegin(GL_LINES);
  koch(0,i);
  koch(-120,i);
  koch(120,i);
  glEnd();
  glFlush();
}



int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(1280, 720);


  glutCreateWindow("Snowfalke");
  gluOrtho2D(0,1280,0,720);
  glClearColor(1,1,1,0);

  glClearDepth(1);
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
