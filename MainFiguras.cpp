//#include <gl/gl.h>     // The GL Header File
//#include <windows.h>	//Solo para Windows
#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		// Descomentar para Linux
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
CCamera objCamera; 

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int font=(int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



GLUquadricObj *quadratic;				// Storage For Our Quadratic Objects ( NEW )


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;

CTexture textEdificio;
CTexture textEdificio2;
CTexture textArbol;

CFiguras fig1;
CFiguras fig2;

float offset=0.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);


	textEdificio.LoadTGA("C:/Users/PC/Documents/Semestre 7/Computación gráfica/Murales/muralfrente.tga");
	textEdificio.BuildGLTexture();
	textEdificio.ReleaseImage();

	textEdificio2.LoadTGA("C:/Users/PC/Documents/Semestre 7/Computación gráfica/Murales/Venecia.tga");
	textEdificio2.BuildGLTexture();
	textEdificio2.ReleaseImage();

	textArbol.LoadTGA("C:/Users/PC/Documents/Semestre 7/Computación gráfica/Murales/Arbol.tga");
	textArbol.BuildGLTexture();
	textArbol.ReleaseImage();

    text1.LoadBMP("Texturas/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	objCamera.Position_Camera(0,2.5f,7, 0,2.5f,0, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();	
	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glColor3f(1.0, 1.0, 1.0);
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
				
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glLineWidth(2.0);
				glBegin(GL_LINES); //Ejes de Referencia
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(0.0, 0.0, 0.0);
					glVertex3f(80.0, 0.0, 0.0);
					glColor3f(0.0, 1.0, 0.0);
					glVertex3f(0.0, 0.0, 0.0);
					glVertex3f(0.0, 80.0, 0.0);
					glColor3f(0.0, 0.0, 1.0);
					glVertex3f(0.0, 0.0, 0.0);
					glVertex3f(0.0, 0.0, 80.0);
				glEnd();
				glEnable(GL_LIGHTING);
				
			glPopMatrix();
		
			//Poner Figuras Aqui
			/*glPushMatrix();
				
				glTranslatef(4.5,1.5,3.5);
				glPushMatrix();

					glColor3f(0.3, 0.3, 0.8);
					glScalef(9.0,3.0,7.0);
					fig2.prisma(1.0, 1.0, 1.0, 0.0);  //Edifico base

				glPopMatrix();
				glPushMatrix();

					glTranslatef(0, 5, 0);
					glPushMatrix();

						glColor3f(0.6,0.6,1.0);
						glScalef(5.0, 7.0, 5.0);
						fig2.prisma(1.0, 1.0, 1.0, textEdificio.GLindex);   //Edificio medio

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();
			*/
			if (offset < 1){
				offset += 0.001;
			}
			else{
				offset = 0;
			}
			glColor3f(1.0, 1.0, 1.0);
			fig2.figurota(0.0, textArbol.GLindex, offset);
			/*
			//Molino
			glPushMatrix();
				glTranslatef(2, 4.5, 0);
				glPushMatrix();
					glScalef(2, 9, 1);
					fig2.prisma(1.0, 2.0, 1.0, 0);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0, 2.5, 0.5);
					glScalef(2.0,2.0,0.5);
					glRotatef(90,1.0,0.0,0.0);
					glColor3f(1.0,1.0,0.0);
					fig2.cilindro(0.5,1.0,12,0);
				glPopMatrix();
				glRotatef(60, 0.0, 0.0, 1.0);
				glPushMatrix();
					glTranslatef(2.5, 0.0, 0.0);
					glColor3f(1.0, 0.0, 0.0);
					glScalef(1.5, 1.0, 1.0);
					fig2.prisma(1.0, 2.0, 1.0, 0);
				glPopMatrix();
				
			glPopMatrix();
			*/
			//fig2.esfera(1,12, 12, 0);  //Pueden mandar llamar nuevas figuras utilizando la variable fig2 y el operador punto
			

		glPopMatrix();

	
	glPopMatrix();
	

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
		glColor3f(1.0,0.0,0.0);
		pintaTexto(-0.25, 0.23,-0.25,(void *)font,"Figuras");
		pintaTexto(-0.25, 0.21,-0.25,(void *)font,"Crear modelos basicos");
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	/*x=Vo*t*cos(angulo)
	  y=Vo*t*sen(angulo)-0.5(g*t*t)*/

	/*fig2.text_izq-= 0.001;
	fig2.text_der-= 0.001;
	if(fig2.text_izq<-1)
		fig2.text_izq=0;
	if(fig2.text_der<0)
		fig2.text_der=1;*/
	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':		//
			break;

		case 'R':		//
			break;

		case 'f':		//
		case 'F':
			
			break;

		case 27:        // Cuando Esc es presionado...
			//exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Figura Examen"); // Nombre de la Ventana

  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
