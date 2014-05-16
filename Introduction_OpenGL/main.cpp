#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl\glut.h>

int angleX = 5 ,angleY = 5 ,angleZ = 5 ;
int x = 0 , y = 0 , z = 0;
int d= 5;

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
     //glRotatef( angleX, x, 0, 0);
     //glRotatef( angleY, x, y, z);
     //glRotatef( angleZ, x, y, z);
     
     // choisé la couleur de dessin
     glColor3f(1.0 , 0.0 , 0.0 );
     
     // dessin de triangle
     glBegin (GL_TRIANGLES);
             glVertex2f (0.0 , 0.0 );glColor3f(0.0 , 1.0 , 0.0 );
             glVertex2f (0.5 , 0.0 );glColor3f(0.0 , 0.0 , 1.0 );
             glVertex2f (0.5 , 1.0 );
     glEnd();
     
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
          gluLookAt( 0,0,5,  0,0,0,  0,1,0 );
          glMatrixMode(GL_MODELVIEW);
}

// fonction d'ecoute de clavier pour la translation et la rotation
/*void Key (unsigned char key , int x , int y )
{
     if(angleX==360) angleX=0;
     if(angleY==360) angleY=0;
     if(angleZ==360) angleZ=0;
     
     switch (key)
     {
            case 27 : exit(0); break;
            
            case 49 : x=1;angleX+=d; break;
            case 51 : x=1;angleX-=d;  break;

            
     }
     Dessin();
}*/

// fonction d'ecoute de clavier pour la translation et la rotation
void TR (int key , int x , int y )
{
     //printf("key = %d ",key);
     switch (key)
     {
            case 27 : exit(0); break;
            
            case GLUT_KEY_UP : x=1;angleX=d; break;
            case GLUT_KEY_DOWN : x=1;angleX=d; break;
            /*case 52 : glRotatef( 5 , 0 , -1 , 0 ); break;
            case 54 : glRotatef( 5 , 0 , 1 , 0 ); break;
            case 55 : glRotatef( 5 , 0 , 0 , -1 ); break;
            case 57 : glRotatef( 5 , 0 , 0 , 1 ); break;*/
            
     }
     Dessin();
}

//  programme pricipal
int main (int ac , char **av)
{
     glutInit(&ac , av);
     glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
     //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(700 , 500);
     glutInitWindowPosition(100 , 100);
     glutCreateWindow("          K' Agent");

     glutDisplayFunc(Dessin);
     glutReshapeFunc(Camera);
     //glutKeyboardFunc(Key);
     glutSpecialFunc(TR);
     
     glutMainLoop();
     return 0;
}
