

#ifndef SNAKE_H
#define SNAKE_H

typedef struct 
{ 
  int posx;
  int posy;        
}Unit;

class Snake
{
    private:
            
            Unit units[50];
            int units_nbr;
            Unit mouse;
            float Snake_Head_Rotate_Degree;
             
            void DrawUnit(int index);
            void DrawSpecialUnit(int index);
            bool IsThereCrash(int direction);
             
	public:
           
           bool IsGameOver;
           bool IsWinner;
        
           void ResetSnake();
           void DrawSnake(); 
           void DrawMouse();
           void StepForward(int direction);
           
		   Snake();

		   ~Snake();
};

#endif 
