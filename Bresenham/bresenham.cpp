#include<GL/glut.h>
#include<iostream>
using namespace std;

void init(void)
{
 glClearColor(1.0,1,0,1.0);
 glMatrixMode(GL_PROJECTION);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250,250,-250,250);
}
void writepoints(int k){
  char *c;
  char s[5];
  gcvt(k,5,s);
  glColor3f(0,0,0);
  glRasterPos2f(k,-10);
  for(c=s; *c!='\0';c++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
  if(k!=0){
    glRasterPos2f(10,k);
    for(c=s; *c!='\0';c++){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
    }
  }
}
void pointd(){
  int k=-250;
  for(k=-250;k<=250;k+=50){
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2i(k,0);
    glVertex2i(0,k);
    glEnd();
    writepoints(k);

    glFlush();
  }
}
void display(){
  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2i(-250,0);
  glVertex2i(250,0);
  glVertex2i(0,250);
  glVertex2i(0,-250);
  glEnd();

  pointd();

  glFlush();
}

int i=1;
float x1,yy;
float xval, yval;
int xarr[2];
int yarr[2];

void setPixel(float x, float y){
  glPointSize(1);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}
void zto(int x1, int y1, int x2, int y2){
  if(x2>x1){
    int x=x1, y=y1;
    int dx=x2-x1, dy=y2-y1;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x2){
      setPixel(x,y);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
  else{
    int x=x2, y=y2;
    int dx=x1-x2, dy=y1-y2;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x1){
      setPixel(x,y);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
}
void gto(int x1, int y1, int x2, int y2){
  int xx1=y1, yy1=x1, xx2=y2, yy2=x2;
  x1=xx1, y1=yy1, x2=xx2, y2=yy2;
  if(x2>x1){
    int x=x1, y=y1;
    int dx=x2-x1, dy=y2-y1;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x2){
      setPixel(y,x);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
  else{
    int x=x2, y=y2;
    int dx=x1-x2, dy=y1-y2;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x1){
      setPixel(y,x);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
}
void ltz(int x1, int y1, int x2, int y2){
  int xx1=x1, yy1=(-1)*y1, xx2=x2, yy2=(-1)*y2;
  x1=xx1, y1=yy1, x2=xx2, y2=yy2;
  if(x2>x1){
    int x=x1, y=y1;
    int dx=x2-x1, dy=y2-y1;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x2){
      setPixel(x,-y);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
  else{
    int x=x2, y=y2;
    int dx=x1-x2, dy=y1-y2;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x1){
      setPixel(x,-y);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
}
void lto(int x1, int y1, int x2, int y2){
  int xx1=x1, yy1=(-1)*y1, xx2=x2, yy2=(-1)*y2;
  x1=yy1, y1=xx1, x2=yy2, y2=xx2;
  if(x2>x1){
    int x=x1, y=y1;
    int dx=x2-x1, dy=y2-y1;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x2){
      setPixel(y,-x);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
  else{
    int x=x2, y=y2;
    int dx=x1-x2, dy=y1-y2;
    int dT=(2*dy)-(2*dx), dS=2*dy;
    int d=(2*dy)-dx;
    while(x<x1){
      setPixel(y,-x);
      x++;
      if(d<0){
        d=d+dS;
      }
      else{
        y++;
        d=d+dT;
      }
    }
  }
}

void calc(int x1, int y1, int x2, int y2){
  float m=0;
  m=float(y2-y1)/(x2-x1);
  cout<<"m="<<m<<"\n";
  if(m>=0 && m<=1){
    zto(x1,y1,x2,y2);
  }
  else if(m>1){
    gto(x1,y1,x2,y2);
  }
  else if(m<-1){
    lto(x1,y1,x2,y2);
  }
  else if(m>-1 && m<0){
    ltz(x1,y1,x2,y2);
  }

}
void dda(int x1, int y1, int x2, int y2){
  int dx=x2-x1, dy=y2-y1, steps, i=0;
  float xinc, yinc, x=x1, y=y1;
  if(abs(dx)>abs(dy)){
    steps = abs(dx);
  }
  else{
    steps = abs(dy);
  }
  xinc = float(dx)/(steps);
  yinc = float(dy)/(steps);
  while(i<=steps){
    setPixel(ROUND(x), ROUND(y));
    x = x+xinc;
    y = y+yinc;
    i = i+1;
  }
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){

  if(button == GLUT_LEFT_BUTTON && action==GLUT_DOWN)
  {
      x1=xMouse;
      yy=500-yMouse;

      xval = x1-250;
      yval = yy-250;

      glPointSize(5);
      glBegin(GL_POINTS);
      glColor3f(1,0,0);
      glVertex2i(xval,yval);
      glEnd();
      glFlush();

      xarr[i]=xval;
      yarr[i]=yval;
      i++;

      if(i%2!=0){
        calc(xarr[i-1],yarr[i-1], xarr[i-2],yarr[i-2]);
      }
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Bresenham");

  init();
  glutDisplayFunc(display);
  glutMouseFunc(mousePtPlot);
  glutMainLoop();
  return 0;
}
