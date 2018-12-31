#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.1416
static GLfloat spin = 0.0;//initial degree for spinning
static GLfloat spin2 = 0.0;//initial degree for spinning
static float	tx	=  0.0;
static float	ty	=  0.0;
static float	car_x	=  71;
bool winMillx = false, carx = false;

void spinDisplay_right(void)
{
	car_x -= .03;
   spin = spin + 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   if (car_x < -60)
	   car_x = 71;
   glutPostRedisplay();

}

void spinDisplay_right_w(void)
{
	
	spin2= spin2 + .5;
	if (spin2 > 360.0)
		spin2 = spin2 - 360.0;
	glutPostRedisplay();

}


void circle(float radius)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
		glColor3d((double)106/255, (double)44/255, (double)109/255);
		for(i = 0; i < 25; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius, sin(angle) * radius, 0);
		}

		glColor3d((double)24/255, (double)6/255, (double)25/255);
		for(; i < 50; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius, sin(angle) * radius, 0);
		}
		glColor3d((double)60/255, (double)23/255, (double)61/255);
		for(; i < 75; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius, sin(angle) * radius, 0);
		}
		glColor3d((double)24/255, (double)6/255, (double)25/255);
		for(; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius, sin(angle) * radius, 0);
		}

	glEnd();
}

void _circle(float radius)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
	glColor3d((double)106 / 255, (double)44 / 255, (double)109 / 255);
	for (i = 0; i < 100; i++)
	{
		angle = 2 * PI * i / 100;
		glVertex3f(cos(angle) * radius, sin(angle) * radius, 0);
	}
	glEnd();
}
void road(){
	glPushMatrix();
			glColor3d((double)58/255, (double)58/255, (double)58/255);
			glTranslated(0,-8,0);
			glBegin(GL_POLYGON);
				glVertex2d(50,0);
				glVertex2d(-50,0);
				
				glVertex2d(-50,15);
				glVertex2d(50,15);
				//glVertex2d(tx,ty);
			glEnd();


			glColor3d((double)83/255, (double)96/255, (double)97/255);
			glTranslated(0,-50,0);
			glBegin(GL_POLYGON);
				glVertex2d(50,0);
				glVertex2d(-50,0);
				
				glVertex2d(-50,50);
				glVertex2d(50,50);
				//glVertex2d(tx,ty);
			glEnd();

		glPopMatrix();
}
void Car(){
	glPushMatrix();
		glPushMatrix();
			glColor3d((double)51/255, (double)0/255, (double)219/255);
			glBegin(GL_POLYGON);
				glVertex2d(-20,0);
				glVertex2d(10,0);
				glVertex2d(10,6);
				glVertex2d(-20,6);
				glVertex2d(-12,7);
				glVertex2d(-10,12);
				glVertex2d(6,12);
				glVertex2d(8,10);
				glVertex2d(8,6);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3d((double)142/255, (double)140/255, (double)147/255);
			
			glBegin(GL_POLYGON);
				glVertex2d(-9,11);
				glVertex2d(-12,7);
				glVertex2d(-2,7);
				glVertex2d(-2,11);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3d((double)142/255, (double)140/255, (double)147/255);
			glTranslated(-3,0,0);
			glBegin(GL_POLYGON);
				glVertex2d(9,11);
				glVertex2d(10,7);
				glVertex2d(2,7);
				glVertex2d(2,11);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslated(4,0,0);
			glRotated(spin,0,0,1);
			circle(3);
		glPopMatrix();
		glTranslated(-14,0,0);
		glRotated(spin,0,0,1);
			circle(3);
		glPopMatrix();
}
void cater(){
	glPushMatrix();
	glTranslated(-.5,0,0);
		glColor3d((double)255/255, (double)250/255, (double)244/255);
			glBegin(GL_POLYGON);
				glVertex2d(0,0);
				glVertex2d(1,0);
				glVertex2d(1,16);
				glVertex2d(0,16);
			glEnd();
		glPopMatrix();
}
void winMill(){
	glPushMatrix();

		glTranslated(7, 0, 0);
		
		glPushMatrix();
		glTranslated(27,34,0);
				glBegin(GL_POLYGON);
					glVertex2d(0,5);
					glVertex2d(0,0);
					glVertex2d(3,0);
					glVertex2d(3,5);
				
				glEnd();
			
		glPopMatrix();
		
		glPushMatrix();
			glBegin(GL_POLYGON);
	
				glVertex2d(28,34);
				glVertex2d(28,7);
				glVertex2d(29,7);
				glVertex2d(29,34);
			glEnd();
		glPopMatrix();

		glTranslated(28.5, 37, 0);
		glPushMatrix();
		glRotated(spin2, 0, 0, 1);
			glPushMatrix();
				cater();
			glPopMatrix();

			glPushMatrix();
				glRotated(127, 0, 0, 1);
				cater();
			glPopMatrix();
			glPushMatrix();
				glRotated(237, 0, 0, 1);
				cater();
			glPopMatrix();
			glPushMatrix();
				_circle(1);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void window(){
	glPushMatrix();
	glColor3d((double)255/255, (double)255/255, (double)0/255);
	glBegin(GL_POLYGON);
				glVertex2d(-48,35);
				glVertex2d(-45,35);
				glVertex2d(-45,32);
				glVertex2d(-48,32);
			glEnd();
			
		glPopMatrix();
}
void Building(){
	glPushMatrix();
			glColor3d((double)96/255, (double)73/255, (double)73/255);
			glBegin(GL_POLYGON);
				glVertex2d(-49,37);
				glVertex2d(-49,7);
				glVertex2d(-36,7);
				glVertex2d(-36,37);
			glEnd();
			glColor3d((double)102/255, (double)97/255, (double)96/255);
			glBegin(GL_POLYGON);
				glVertex2d(-49.5,25);
				glVertex2d(-49.5,24);
				glVertex2d(-35.5,24);
				glVertex2d(-35.5,25);
			glEnd();
			
			window();
			glTranslated(7,0,0);
			window();
			glTranslated(0,-5,0);
			window();
			glTranslated(-7,0,0);
			window();
			glTranslated(0,-9,0);
			window();
			glTranslated(0,-7,0);
			window();
			glTranslated(7,0,0);
			window();
			glTranslated(0,7,0);
			window();



		glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	cout << tx << " : " << ty << endl;
	glPushMatrix();
	road();
	winMill();
	glPushMatrix();
		Building();
		glTranslated(16,0,0);
		Building();
	glPopMatrix();

	glTranslated(car_x,0,0);
		Car();
	glPopMatrix();
	glFlush();
}

void init(void)
{
	glClearColor ((double)47/255, (double)65/255, (double)94 /255, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {
	case 's':
		carx = true;
		glutIdleFunc(spinDisplay_right);
		break;
	case 'q':
		carx = false;
		winMillx = false;
		glutIdleFunc(spinDisplay_right);
		break;
	case 'w':
		winMillx = true;
		glutIdleFunc(spinDisplay_right_w);
		break;

	  default:
			glutIdleFunc(NULL);
			break;
	}
}


void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=1;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				ty -=1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
			
				ty +=1;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}

void autoLoad(){
	if (carx)
		spinDisplay_right();
	if (winMillx){
		spinDisplay_right_w();
	}
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Translating Circle");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);//up,down,left,right
	glutIdleFunc(autoLoad);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

