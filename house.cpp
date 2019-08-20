#include<GL/glut.h>
#include<math.h>
#define PI 3.14159265358979323846

void init(void){
  glClearColor(0.18,0.18,0.18,0.1);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,200,0,150);
}

void lst(void){
  //glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(3);
  float radius;
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);   //stars
  glColor3f(1,1,1);
  glVertex2i(10,137);
  glVertex2i(25,143);
  glVertex2i(85,140);
  glVertex2i(96,129);
  glVertex2i(107,140);
  glVertex2i(123,125);
  glVertex2i(132,137);
  glVertex2i(144,120);
  glVertex2i(159,137);
  glVertex2i(172,132);
  glVertex2i(185,143);
  glVertex2i(189,120);
  glEnd();

  glBegin(GL_POLYGON);   //lake
  glColor3f(0,0.4,0.4);
  glVertex2i(0,0);
  glVertex2i(200,0);
  glVertex2i(200,30);
  glVertex2i(0,30);
  glEnd();

  glBegin(GL_POLYGON);        //moon
  radius=12;
  glColor3f(1,1,1);
  for (float i = -PI; i <= PI; i += 0.001)
      glVertex2f(62+(sin(i)*radius), 134+(cos(i)*radius));
  glEnd();

  glBegin(GL_LINES);       //cloud base
  glColor3f(0.5,0.5,0.5);
  glVertex2i(22,115);
  glVertex2i(70,115);
  glEnd();

  radius=20;               //cloud
  float twoPI=2*PI;
  glBegin(GL_POLYGON);
  glColor3f(0.5,0.5,0.5);
  glVertex2i(50,115);
  for (float i = PI/5; i <= PI/2; i += 0.001)
      glVertex2f(50+(sin(i)*radius), 115+(cos(i)*radius));
  glEnd();

  glBegin(GL_POLYGON);
  radius=15;
  glVertex2i(46,130);
  //for (float i = -PI/2.8; i <= PI/2; i += 0.001)
  for (float i = -PI; i <= PI; i += 0.001)
      glVertex2f(47+(sin(i)*radius), 130+(cos(i)*radius));
  glEnd();

  glBegin(GL_POLYGON);
  radius=13;
  glVertex2i(22,115);
  for (float i = -PI/2; i <= PI/2; i += 0.001)
      glVertex2f(22+(sin(i)*radius), 115+(cos(i)*radius));
  glEnd();

  glBegin(GL_POLYGON);
  radius=10;
  for (float i = -PI; i <= PI; i += 0.001)
      glVertex2f(31+(sin(i)*radius), 129+(cos(i)*radius));
  glEnd();

  glBegin(GL_QUADS);
  glVertex2i(30,115);
  glVertex2i(50,115);
  glVertex2i(50,125);
  glVertex2i(30,125);
  glEnd();

  glBegin(GL_QUADS);     //rect part of house
  glColor3f(0.9,0.6,0.6);
  glVertex2i(115,44);
  glVertex2i(170,44);
  glVertex2i(170,84);
  glVertex2i(115,84);
  glEnd();

  glBegin(GL_QUADS);     //roof of house
  glColor3f(0.5,0.5,0.5);
  glVertex2i(105,84);
  glVertex2i(180,84);
  glVertex2i(170,103);
  glVertex2i(115,103);
  glEnd();

  glBegin(GL_QUADS);     //tree base
  glColor3f(0.5,0.3,0.2);
  glVertex2i(50,40);
  glVertex2i(64,40);
  glVertex2i(64,65);
  glVertex2i(50,65);
  glEnd();

  glBegin(GL_POLYGON);   //tree top
  glColor3f(0,.7,0.3);
  glVertex2i(72,65);
  glVertex2i(42,65);
  glVertex2i(52,78);
  glVertex2i(43.2,75);
  glVertex2i(53,88);
  glVertex2i(46,84);
  glVertex2i(57,100);
  glVertex2i(68,84);
  glVertex2i(61,88);
  glVertex2i(70.5,75);
  glVertex2i(62,78);
  glVertex2i(72,65);
  glEnd();

  float j;
  for(j=0;j<144;j+=0.008){
    glBegin(GL_QUADS);         //lake loop
    glColor3f(0,0.4,0.4);
    glVertex2i(0,0);
    glVertex2i(200,0);
    glVertex2i(200,30);
    glVertex2i(0,30);
    glEnd();

    glBegin(GL_QUADS);          //lake above loop
    glColor3f(0.18,0.18,0.18);
    glVertex2i(0,30);
    glVertex2i(200,30);
    glVertex2i(200,50);
    glVertex2i(0,50);
    glEnd();
    glBegin(GL_QUADS);     //tree base
    glColor3f(0.5,0.3,0.2);
    glVertex2i(50,40);
    glVertex2i(64,40);
    glVertex2i(64,65);
    glVertex2i(50,65);
    glEnd();

    glBegin(GL_QUADS);          //boat
    glColor3f(0.8,0.3,0.01);
    glVertex2f(30+j,20);
    glVertex2f(22+j,33);
    glVertex2f(56+j,33);
    glVertex2f(48+j,20);
    glEnd();
    glBegin(GL_QUADS);   //boat flag POLE
    glColor3f(0.6,0.6,0.6);
    glVertex2f(35+j,33);
    glVertex2f(35+j,44);
    glVertex2f(34.5+j,44);
    glVertex2f(34.5+j,33);
    glEnd();
    glBegin(GL_TRIANGLES);   //boat flag
    glColor3f(0.6,0.6,0.6);
    glVertex2f(34.5+j,44);
    glVertex2f(31+j,38);
    glVertex2f(34.5+j,38);
    glEnd();

    glFlush();
 }
 while(1){
 for(j=144;j>=-22;j-=0.008){
   glBegin(GL_QUADS);         //lake loop
   glColor3f(0,0.4,0.4);
   glVertex2i(0,0);
   glVertex2i(200,0);
   glVertex2i(200,30);
   glVertex2i(0,30);
   glEnd();

   glBegin(GL_QUADS);          //lake above loop
   glColor3f(0.18,0.18,0.18);
   glVertex2i(0,30);
   glVertex2i(200,30);
   glVertex2i(200,50);
   glVertex2i(0,50);
   glEnd();
   glBegin(GL_QUADS);     //tree base
   glColor3f(0.5,0.3,0.2);
   glVertex2i(50,40);
   glVertex2i(64,40);
   glVertex2i(64,65);
   glVertex2i(50,65);
   glEnd();

   glBegin(GL_QUADS);          //boat
   glColor3f(0.8,0.3,0.01);
   glVertex2f(30+j,20);
   glVertex2f(22+j,33);
   glVertex2f(56+j,33);
   glVertex2f(48+j,20);
   glEnd();
   glBegin(GL_QUADS);   //boat flag POLE
   glColor3f(0.6,0.6,0.6);
   glVertex2f(35+j,33);
   glVertex2f(35+j,44);
   glVertex2f(34.5+j,44);
   glVertex2f(34.5+j,33);
   glEnd();
   glBegin(GL_TRIANGLES);   //boat flag
   glColor3f(0.6,0.6,0.6);
   glVertex2f(34.5+j,44);
   glVertex2f(31+j,38);
   glVertex2f(34.5+j,38);
   glEnd();

   glFlush();
}
for(j=-22;j<144;j+=0.008){
  glBegin(GL_QUADS);         //lake loop
  glColor3f(0,0.4,0.4);
  glVertex2i(0,0);
  glVertex2i(200,0);
  glVertex2i(200,30);
  glVertex2i(0,30);
  glEnd();

  glBegin(GL_QUADS);          //lake above loop
  glColor3f(0.18,0.18,0.18);
  glVertex2i(0,30);
  glVertex2i(200,30);
  glVertex2i(200,50);
  glVertex2i(0,50);
  glEnd();
  glBegin(GL_QUADS);     //tree base
  glColor3f(0.5,0.3,0.2);
  glVertex2i(50,40);
  glVertex2i(64,40);
  glVertex2i(64,65);
  glVertex2i(50,65);
  glEnd();

  glBegin(GL_QUADS);          //boat
  glColor3f(0.8,0.3,0.01);
  glVertex2f(30+j,20);
  glVertex2f(22+j,33);
  glVertex2f(56+j,33);
  glVertex2f(48+j,20);
  glEnd();
  glBegin(GL_QUADS);   //boat flag POLE
  glColor3f(0.6,0.6,0.6);
  glVertex2f(35+j,33);
  glVertex2f(35+j,44);
  glVertex2f(34.5+j,44);
  glVertex2f(34.5+j,33);
  glEnd();
  glBegin(GL_TRIANGLES);   //boat flag
  glColor3f(0.6,0.6,0.6);
  glVertex2f(34.5+j,44);
  glVertex2f(31+j,38);
  glVertex2f(34.5+j,38);
  glEnd();

  glFlush();
}
}
}
int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(600,338);
  glutInitWindowPosition(50,47);
  glutCreateWindow("House");
  init();
  glutDisplayFunc(lst);
  glutMainLoop();
  return 0;
}
