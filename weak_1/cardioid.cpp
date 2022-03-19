
/* Module      : MainFile.cpp
 * Author      : 
 * Email       : 
 * Course      : Computer Graphics
 *
 * Description : 
 *
 *
 * Date        : 
 *
 * History:
 * Revision      Date          Changed By
 * --------      ----------    ----------
 * 01.00         ?????          ???
 * First release.
 *
 */

/* -- INCLUDE FILES ------------------------------------------------------ */
#define _USE_MATH_DEFINES

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

/* -- DATA STRUCTURES ---------------------------------------------------- */
// Our point class.
class GLintPoint  {

};

/* -- GLOBAL VARIABLES --------------------------------------------------- */

/* -- LOCAL VARIABLES ---------------------------------------------------- */


/* ----------------------------------------------------------------------- */
/* Function    : void drawDot( GLint x, GLint y )
 *
 * Description : Draw a point at location (x, y) in the window.
 *
 * Parameters  : GLint x : X coordinate of point to draw.
 *               GLint y : X coordinate of point to draw.
 *
 * Returns     : void
 */

void drawDot( GLint x, GLint y )  {

}

/* ----------------------------------------------------------------------- */
/* Function    : void myInit( void )
 *
 * Description : Initialize OpenGL and the window where things will be
 *               drawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */

void myInit( void )  {
  glClearColor( 1.0, 1.0, 1.0, 0.0 );
  glColor3f( 0.0, 0.0, 0.0 );
  glPointSize( 1.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluOrtho2D( 0.0, 640.0, 0.0, 480.0 );
}


/* ----------------------------------------------------------------------- */
/* Function    : void myDisplay( void )
 *
 * Description : This function gets called everytime the window needs to
 *               be redrawn.
 *
 * Parameters  : void
 *
 * Returns     : void
 */
float radius = 5.0f, x = 300, y = 300, x_1, y_1;
void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT );
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_LINES);
  for (float angle = 0; angle < 361; angle++){
    x_1 = x;
    y_1 = y;
  	x = 300+ 15 * cos(angle * M_PI / 180) * radius*(1-cos(angle * M_PI / 180));
  	y = 300+ 15 * sin(angle * M_PI / 180) * radius*(1-cos(angle * M_PI / 180));
  	
  	//radius += 0.1f;
  	glVertex2f(x, y);
  	glVertex2f(x_1, y_1);
  } 
  /*radius = 0.0f; x = 300; y = 300; 
  for (float angle = 0; angle < 181; angle++){
    x_1 = x;
    y_1 = y;
  	x = 300 - 15 * sin(angle * M_PI / 180) * radius;
  	y = 300 + 15 * cos(angle * M_PI / 180) * radius;
  	
  	radius += 0.1f;
  	glVertex2f(x, y);
  	glVertex2f(x_1, y_1);
  } */
  glEnd();
  glFlush();
}



int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  // Set the window size in screen pixels.
  glutInitWindowSize( 800, 800 );
  // Set the window position in screen pixels.
  glutInitWindowPosition( 100, 150 );
  // Create the window.
  glutCreateWindow( "Lab" );
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( myDisplay );
  // Initialize some things.
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */

