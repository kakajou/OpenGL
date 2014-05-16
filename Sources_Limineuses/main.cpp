#include <GL/glut.h> 
#include <stdlib.h> 
 
GLfloat ambientMaterial[4] = { 0.0, 0.0, 0.0, 1.0 }; 
GLfloat diffuseMaterial[4] = { 0.0, 0.0, 0.0, 1.0 }; 
GLfloat specularMaterial[4] = { 0.0, 0.0, 0.0, 1.0 }; 
GLfloat shininessMaterial = 0.0; 
GLfloat emissionMaterial[4] = { 0.0, 0.0, 0.0, 1.0 }; 
 
GLfloat white[] = { 1.0, 1.0, 1.0, 0.0 }; 
GLfloat red[] = { 1.0, 0.0, 0.0, 0.0 }; 
GLfloat green[] = { 0.0, 1.0, 0.0, 0.0 }; 
GLfloat blue[] = { 0.0, 0.0, 1.0, 0.0 }; 
GLfloat black[] = { 0.0, 0.0, 0.0, 0.0 }; 
 
 
/*  Initialize material property, light source, lighting 
model, and depth buffer. 
 */ 
void init(void)  { 
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; 
 
   glClearColor (0.0, 0.0, 0.0, 0.0); 
   glShadeModel (GL_SMOOTH); 
   glEnable(GL_DEPTH_TEST); 
    
   glLightfv(GL_LIGHT0, GL_AMBIENT, red); 
   glLightfv(GL_LIGHT0, GL_DIFFUSE, green); 
   glLightfv(GL_LIGHT0, GL_SPECULAR, blue); 
   glLightfv(GL_LIGHT0, GL_POSITION, 
light_position); 
   glEnable(GL_LIGHTING); 
   glEnable(GL_LIGHT0);  
 
} 
 
void display(void) { 
   glClear(GL_COLOR_BUFFER_BIT | 
GL_DEPTH_BUFFER_BIT); 
   glMaterialfv(GL_FRONT, GL_AMBIENT, 
ambientMaterial); 
   glMaterialfv(GL_FRONT, GL_DIFFUSE, 
diffuseMaterial); 
   glMaterialfv(GL_FRONT, GL_SPECULAR, 
specularMaterial); 
   glMaterialf(GL_FRONT, GL_SHININESS, 
shininessMaterial); 
   glMaterialfv(GL_FRONT, GL_EMISSION, 
emissionMaterial); 
   /*   glutSolidSphere(1.0, 20, 16);*/ 
   glutSolidSphere(1.0, 40, 40); 
   glutSwapBuffers(); 
 
} 
 
void reshape (int w, int h) { 
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION); 
   glLoadIdentity(); 
   if (w <= h) 
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 
         1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0); 
   else 
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h, 
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 
10.0); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
} 
 
void incrementMaterial (GLfloat material[4], GLfloat 
delta) { 
  material[0] +=delta; 
  if (material[0] > 1.0)    material[0] = 1.0; 
  if (material[0] < 0.0)    material[0] = 0.0; 
   
  material[1] +=delta; 
  if (material[1] > 1.0)    material[1] = 1.0; 
  if (material[1] < 0.0)    material[1] = 0.0; 
   
  material[2] +=delta; 
  if (material[2] > 1.0)    material[2] = 1.0; 
  if (material[2] < 0.0)    material[2] = 0.0; 
} 
 
void keyboard(unsigned char key, int x, int y) 
{ 
  switch (key) { 
  case 'r': 
    
ambientMaterial[0]=ambientMaterial[1]=ambientMaterial[2]=0.0; 
    glMaterialfv(GL_FRONT, GL_AMBIENT, 
ambientMaterial); 
    
diffuseMaterial[0]=diffuseMaterial[1]=diffuseMaterial
[2]=0.0; 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, 
diffuseMaterial); 
    
specularMaterial[0]=specularMaterial[1]=specularMaterial[2]=0.0; 
    glMaterialfv(GL_FRONT, GL_EMISSION, 
emissionMaterial); 
 shininessMaterial=0.0; 
    glMaterialf(GL_FRONT, GL_SHININESS, 
shininessMaterial); 
    
emissionMaterial[0]=emissionMaterial[1]=emissionMaterial[2]=0.0; 
    glMaterialfv(GL_FRONT, GL_EMISSION, 
emissionMaterial); 
    glutPostRedisplay(); 
    break; 
 
  case 'a': 
    incrementMaterial(ambientMaterial, 0.1); 
    glMaterialfv(GL_FRONT, GL_AMBIENT, 
ambientMaterial); 
    glutPostRedisplay(); 
    break; 
  case 'A': 
    incrementMaterial(ambientMaterial, -0.1); 
    glMaterialfv(GL_FRONT, GL_AMBIENT, 
ambientMaterial); 
    glutPostRedisplay(); 
    break; 
 
  case 'd': 
    incrementMaterial(diffuseMaterial, 0.1); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, 
diffuseMaterial); 
    glutPostRedisplay(); 
    break; 
  case 'D': 
    incrementMaterial(diffuseMaterial, -0.1); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, 
diffuseMaterial); 
    glutPostRedisplay(); 
    break; 
      
  case 's': 
    incrementMaterial(specularMaterial, 0.1); 
    /*specularMaterial[0]=specularMaterial[1]=0.0;*/ 
    glMaterialfv(GL_FRONT, GL_SPECULAR, 
specularMaterial); 
    glutPostRedisplay(); 
    break; 
  case 'S': 
    incrementMaterial(specularMaterial, -0.1); 
    /*specularMaterial[0]=specularMaterial[1]=0.0;*/ 
    glMaterialfv(GL_FRONT, GL_SPECULAR, 
specularMaterial); 
    glutPostRedisplay(); 
break;      
      
  case 'b': 
    shininessMaterial +=2.0; if 
(shininessMaterial>128.0) shininessMaterial=128.0; 
    glMaterialf(GL_FRONT, GL_SHININESS, 
shininessMaterial); 
    glutPostRedisplay(); 
    break; 
  case 'B': 
    shininessMaterial -=2.0; if (shininessMaterial<0.0) 
shininessMaterial=0.0; 
    glMaterialf(GL_FRONT, GL_SHININESS, 
shininessMaterial); 
    glutPostRedisplay(); 
    break;      
      
  case 'e': 
    incrementMaterial(emissionMaterial, 0.1); 
    glMaterialfv(GL_FRONT, GL_EMISSION, 
emissionMaterial); 
    glutPostRedisplay(); 
    break; 
  case 'E': 
    incrementMaterial(emissionMaterial, -0.1); 
    glMaterialfv(GL_FRONT, GL_EMISSION, 
emissionMaterial); 
    glutPostRedisplay(); 
    break; 
      
  case 27: 
    exit(0); 
    break; 
   } 
} 
 
int main(int argc, char** argv) { 
   glutInit(&argc, argv); 
   glutInitDisplayMode (GLUT_DOUBLE | 
GLUT_RGB | GLUT_DEPTH); 
   glutInitWindowSize (500, 500);  
   glutInitWindowPosition (100, 100); 
   glutCreateWindow (argv[0]); 
   init (); 
   glutDisplayFunc(display);  
   glutReshapeFunc(reshape); 
   glutKeyboardFunc(keyboard); 
   glutMainLoop(); 
   return 0; 
} 

