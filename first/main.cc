#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl\glut.h>

int angleX = 5 ,angleY = 5 ,angleZ = 5 ;
int X = 0 , Y = 0 , Z = 0;
int d= 5;

int X_Camera = 5 , Y_Camera = 10 , Z_Camera = 50; 

//  fonction pour le dessin 
void Dessin (void)
{
     glClearColor(0.0 , 0.0 , 0.0 , 0.0);
     glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
     glLoadIdentity();
     
     // debut de dessin
     
     // translation     
     //glTranslatef( 2.0 , 0.0 , 0.0 );
     
     // rotation
     glRotatef( angleX, X, 0, 0);
     glRotatef( angleY, 0, Y, 0);
     glRotatef( angleZ, 0, 0, Z);
     
     // choisé la couleur de dessin
     glColor3f(1.0 , 0.0 , 0.0 );
     
     // dessin de triangle

     glutSolidTeapot(6);

/*
     glBegin (GL_TRIANGLES);
             glVertex3f (0.0 , 0.0 , 0.0 );
             glVertex3f (0.0 , 20.0 , 0.0 );
             glVertex3f (10.0 , 0.0 , 0.0 );
     glEnd();

     glColor3f(0.0 , 1.0 , 0.0 ); 
     glBegin (GL_TRIANGLES);
             glVertex3f (0.0 , 0.0 , 0.0 );
             glVertex3f (0.0 , 20.0 , 0.0 );
             glVertex3f (0.0 , 0.0 , 10.0 );
     glEnd();
   
   glColor3f(1.0 , 1.0 , 1.0 ); 
     glBegin (GL_TRIANGLES);
             glVertex3f (0.0 , 0.0 , 0.0 );
             glVertex3f (10.0 , 0.0 , 0.0 );
             glVertex3f (0.0 , 0.0 , 10.0 );
     glEnd();
     
     glColor3f(0.0 , 0.0 , 1.0 ); 
     glBegin (GL_TRIANGLES);
             glVertex3f (10.0 , 0.0 , 0.0 );
             glVertex3f (0.0 , 20.0 , 0.0 );
             glVertex3f (0.0 , 0.0 , 10.0 );
     glEnd();
  */
     
     // fin de dessin
     
     glutSwapBuffers();
}


// foction de positionnement de caméra et ... en cas de changement de la taille fe fenetre (volume)
void Camera (int w , int h)
{
          glViewport( 0 , 0 , w , h );
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          gluPerspective(45.0 , (float)w / (float)h , 1.0 , 800.0);
          //gluOrtho2D(0 , 7 , 0 , 16);
          gluLookAt( X_Camera , Y_Camera , Z_Camera ,  0,0,0,  0,1,0 );
          glMatrixMode(GL_MODELVIEW);
}

// fonction d'ecoute de clavier pour la translation et la rotation
void Key (unsigned char key , int x , int y )
{
     /*if(angleX==360) angleX=0;
     if(angleY==360) angleY=0;
     if(angleZ==360) angleZ=0;*/
     
     switch (key)
     {
            case 27 : exit(0); break;
            
            case 49 : X=1;angleX+=d; break;
            case 51 : X=1;angleX-=d;  break;
            case 52 : Y=1;angleY+=d; break;
            case 54 : Y=1;angleY-=d;  break;
            case 55 : Z=1;angleZ+=d; break;
            case 57 : Z=1;angleZ-=d;  break;
            
            case 100: X_Camera++;break;             
            case 113: X_Camera--;break;                      
            case 122: Y_Camera++;break;           
            case 115: Y_Camera--;break;            
            case GLUT_KEY_DOWN : Z_Camera++;break;           
            case GLUT_KEY_UP : Z_Camera--;break;
     }
     Dessin();Camera(700,500);
}



//  programme pricipal
int main (int ac , char **av)
{
     glutInit(&ac , av);
     glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
     //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(700 , 500);
     glutInitWindowPosition(100 , 100);
     glutCreateWindow("llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll     K' Agent    llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

     glutDisplayFunc(Dessin);
     glutReshapeFunc(Camera);
     glutKeyboardFunc(Key);
     
     glutMainLoop();
     return 0;
}
