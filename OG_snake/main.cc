#include <windows.h> 
#include <GL/glut.h> 
#include "snake.h"
 
 float movex = 0 , movey= 0;
 bool keys[255];
 float angle = 0;
 
Snake s;
int CurrentDirection = GLUT_KEY_RIGHT;
bool   IsGameStarted = false;
char *GameOverMessage="Game Over";
char *WinnerMessage="Winner!";
 
void Reshape(int w, int h) 
{ 
  glViewport(0, 0, w, h); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
   gluPerspective(45.0, (float)w/(float)h, 1.0, 800.0); 
  gluLookAt(0,0,5  ,0,0,0, 0,1,0); 
  glMatrixMode(GL_MODELVIEW); 
} 

void ShowMessage (float x ,float y , float z , char *message)
{
  glDisable(GL_LIGHTING); 
  glRasterPos2f(x, y);
  while (*message) 
  {
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *message);
  message++;
  }
  glEnable(GL_LIGHTING);
}
 
void Display(void)  
{ 
  glClearColor(0.0,0.0,0.0,0.0); 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glLoadIdentity();

  if (s.IsGameOver)
  {
   IsGameStarted=false;
   ShowMessage(0, 0, 0, GameOverMessage);     
   s.ResetSnake();
   Sleep(500);           
  }
  if (s.IsWinner)
  {
   ShowMessage(0, 0, 0, WinnerMessage);               
   s.ResetSnake();
  }

    // debut Dessin
    
    float color[4] = {0.5, 0.5, 0.5, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    float i;
    // lines H
    for(i=-2; i<=2.1; i+=0.1)
    {
    glBegin(GL_LINES); 
       glVertex3f(i, 2.0, 0.0);
       glVertex3f(i, -2.0, 0.0);
    glEnd();
    }
    // lines V
    for(i=-2; i<=2.1; i+=0.1)
    {
    glBegin(GL_LINES);
    glVertex3f(-2, i, 0.0);
    glVertex3f(2, i, 0.0);
    glEnd();
    }
    // snake
    s.DrawSnake();
    //mouse
    s.DrawMouse();
    
    
    // fin Dessin
                   
  glutSwapBuffers(); 
} 

void Init_S_L (void)
{
     glEnable(GL_DEPTH_TEST);
     static GLfloat lightpos[4]={1.0,0.0,1.0,0.0};
     glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
}

void Key (unsigned char key , int x ,int y )
{
   if (key==27) exit(0);   
}

void Special_Keys (int key , int x , int y)
{
 CurrentDirection = key;   
 if(!IsGameStarted)
  {
  IsGameStarted = true; 
  s.IsGameOver=false;
  s.IsWinner=false;
  }        
}

void Special_Key_UP (int key , int x , int y)
{
 keys[key]=false;  
}

void Action (void)
{

     Display();   
}

void SnakeForwardingTimer(int value)
{
     
if (IsGameStarted)
   {
   switch(CurrentDirection){
   case GLUT_KEY_UP    : s.StepForward(GLUT_KEY_UP);break;
   case GLUT_KEY_DOWN  : s.StepForward(GLUT_KEY_DOWN);break;
   case GLUT_KEY_LEFT  : s.StepForward(GLUT_KEY_LEFT);break;
   case GLUT_KEY_RIGHT : s.StepForward(GLUT_KEY_RIGHT);break;
   default:break;
                            }
   }
   glutTimerFunc(60 , SnakeForwardingTimer , value);
}

int main(int ac, char **av) 
{ 
  glutInit(&ac, av); 
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
  glutInitWindowSize( 700,500); 
  glutInitWindowPosition (200,100); 
  glutCreateWindow("                SMA ---> MYSQL "); 
  
  Init_S_L();
  
  glutDisplayFunc(Display); 
  glutReshapeFunc(Reshape); 
  glutKeyboardFunc(Key); 
  glutSpecialFunc(Special_Keys);
  glutSpecialUpFunc(Special_Key_UP);
  glutIdleFunc(Action);
  
  SnakeForwardingTimer(0);
  
  //glutFullScreen();
  
  glutMainLoop(); 
}

