#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

#include "snake.h" 


Snake::Snake()
{
 srand(time(NULL));
 mouse.posx = (rand() % 40 ) - 19;
 mouse.posy = (rand() % 40 ) - 19;
 IsGameOver=false;
 IsWinner=false;
 Snake_Head_Rotate_Degree=0;
 ResetSnake();
}


Snake::~Snake()
{

}

void Snake:: ResetSnake()
{
 units_nbr = 3;
 units[0].posx = 2;units[0].posy = 0;
 units[1].posx = 1;units[1].posy = 0;
 units[2].posx = 0;units[2].posy = 0;
}

void Snake::DrawUnit(int index)
{
 glPushMatrix();
 glTranslatef((float)((units[index].posx * 10) - 5) / 100,(float)((units[index].posy * 10) - 5) / 100,0.0);
 glutSolidSphere(0.05, 50, 50);
 glPopMatrix();   
}

void Snake::DrawSpecialUnit(int index)
{
 glPushMatrix();
 glTranslatef((float)((units[index].posx * 10) - 5) / 100,(float)((units[index].posy * 10) - 5) / 100,0.0);
 Snake_Head_Rotate_Degree += 2;
 glRotatef(Snake_Head_Rotate_Degree, 1, 1, 1); 
 glutSolidCube(0.1);
 glPopMatrix();
}

void Snake::DrawSnake()
{
 float unit_color[4] = {1, 0.5, 0.2, 1};
 glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, unit_color);
 this->DrawSpecialUnit(0);
 for(int i=1; i<units_nbr; i++)
 this->DrawUnit(i);
}

void Snake::DrawMouse()
{
 float mouse_color[4] = {1, 0, 0, 1};
 glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mouse_color);
 glPushMatrix();
 glTranslatef((float)((mouse.posx * 10) - 5) / 100,(float)((mouse.posy * 10) - 5) / 100,0.0);
 glColor4f(0.3, 0.7, 0.1, 1);
 glutSolidSphere(0.05, 50, 50);
 glPopMatrix();
}

bool Snake::IsThereCrash(int direction)
{
int newx = units[0].posx;    
int newy = units[0].posy;
switch(direction){
case GLUT_KEY_UP:
     if(units[0].posy == 20) return true;
     else newy++;
     break;
     
case GLUT_KEY_DOWN:
     if(units[0].posy == -19) return true;
     else newy--;
     break;
     
case GLUT_KEY_LEFT:
     if(units[0].posx == -19) return true;
     else newx--;
     break;

case GLUT_KEY_RIGHT:
     if(units[0].posx == 20) return true;
     else newx++;
     break;

default:break;
}
for(int i=2; i< units_nbr-1; i++)
 if((units[i].posx == newx) && (units[i].posy == newy))
 return true;
 
 return false;
}

void Snake::StepForward(int direction)
{
 int temp_x = units[0].posx; 
 int temp_y = units[0].posy;
 switch(direction){
case GLUT_KEY_UP:
     if(IsThereCrash(GLUT_KEY_UP))
     {
     IsGameOver = true;
     return;
     }
     else if(units[1].posy != (units[0].posy + 1))
          units[0].posy = units[0].posy + 1;
          else
          units[0].posy = units[0].posy - 1;
     break;
case GLUT_KEY_DOWN:
       if(IsThereCrash(GLUT_KEY_DOWN))
       {
       IsGameOver = true;
       return;
       }
       else if(units[1].posy != (units[0].posy - 1))
            units[0].posy = units[0].posy - 1;
            else
            units[0].posy = units[0].posy + 1;
       break;
       
case GLUT_KEY_LEFT:
     if(IsThereCrash(GLUT_KEY_LEFT))
     {
     IsGameOver = true;
     return;
     }
     else if(units[1].posx != (units[0].posx - 1))
     units[0].posx = units[0].posx - 1;
     else
     units[0].posx = units[0].posx + 1;
break;

case GLUT_KEY_RIGHT:
     if(IsThereCrash(GLUT_KEY_RIGHT))
     {
     IsGameOver = true;
     return;
     }
     else if(units[1].posx != (units[0].posx + 1))
     units[0].posx = units[0].posx + 1;
     else
     units[0].posx = units[0].posx - 1;
     break;

default:break;
}

if(units[0].posx == mouse.posx)
  if(units[0].posy == mouse.posy)
  {
  units_nbr++;
  mouse.posx = (rand() % 21);
  mouse.posy = (rand() % 21);
  }
  
for(int i = units_nbr-1; i>1; i--)
 {
 units[i].posx = units[i-1].posx;
 units[i].posy = units[i-1].posy;
 }

units[1].posx = temp_x;
units[1].posy = temp_y;

if(units_nbr == 49)  IsWinner = true;

}
