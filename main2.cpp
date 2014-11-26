//#include <gl/gl.h>     // The GL Header File
//#include <windows.h>	//Solo para Windows
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		// Descomentar para Linux
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

float angulo1 = 0.0;
float angulo2 = 0.0;
float angulo3 = 0.0;
float giro = 0.0;
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
CTexture forraje;
CTexture pasto;
CTexture ventanah;
CTexture ventanaderecho;
CTexture pista;
CTexture pistah;
CTexture arriba;
CTexture bibliolat1;
CTexture central2;
CTexture central11;
CTexture central22;
CTexture central3;
CTexture central4;


CTexture rocas;
CTexture lateral;
CTexture suelorojo;
CTexture centroder;
CTexture basedesnivel;
CTexture central1;
CTexture ventanacentral;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;


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
    
    text1.LoadBMP("Texturas/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	pista.LoadTGA("Texturas/pista.tga");
	pista.BuildGLTexture();
	pista.ReleaseImage();


	ventanacentral.LoadTGA("Texturas/ventanacentral.tga");
	ventanacentral.BuildGLTexture();
	ventanacentral.ReleaseImage();

	central2.LoadTGA("Texturas/central2.tga");
	central2.BuildGLTexture();
	central2.ReleaseImage();

	central22.LoadTGA("Texturas/central22.tga");
	central22.BuildGLTexture();
	central22.ReleaseImage();

	central11.LoadTGA("Texturas/central1.tga");
	central11.BuildGLTexture();
	central11.ReleaseImage();
	
	central3.LoadTGA("Texturas/central3.tga");
	central3.BuildGLTexture();
	central3.ReleaseImage();

	central4.LoadTGA("Texturas/central4.tga");
	central4.BuildGLTexture();
	central4.ReleaseImage();


	central1.LoadTGA("Texturas/central.tga");
	central1.BuildGLTexture();
	central1.ReleaseImage();


	bibliolat1.LoadTGA("Texturas/bibliolat1.tga");
	bibliolat1.BuildGLTexture();
	bibliolat1.ReleaseImage();

	suelorojo.LoadTGA("Texturas/suelorojo.tga");
	suelorojo.BuildGLTexture();
	suelorojo.ReleaseImage();

	forraje.LoadTGA("Texturas/forraje.tga");
	forraje.BuildGLTexture();
	forraje.ReleaseImage();


	lateral.LoadTGA("Texturas/lateral.tga");
	lateral.BuildGLTexture();
	lateral.ReleaseImage();

	rocas.LoadTGA("Texturas/islas2.tga");
	rocas.BuildGLTexture();
	rocas.ReleaseImage();

	arriba.LoadTGA("Texturas/arribalateral.tga");
	arriba.BuildGLTexture();
	arriba.ReleaseImage();

	pistah.LoadTGA("Texturas/pistah.tga");
	pistah.BuildGLTexture();
	pistah.ReleaseImage();


	basedesnivel.LoadTGA("Texturas/basedesnivel.tga");
	basedesnivel.BuildGLTexture();
	basedesnivel.ReleaseImage();


	centroder.LoadTGA("Texturas/centroder.tga");
	centroder.BuildGLTexture();
	centroder.ReleaseImage();

	pasto.LoadTGA("Texturas/islas.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();


	ventanah.LoadTGA("Texturas/ventanah.tga");
	ventanah.BuildGLTexture();
	ventanah.ReleaseImage();


	ventanaderecho.LoadTGA("Texturas/ventanaderecho.tga");
	ventanaderecho.BuildGLTexture();
	ventanaderecho.ReleaseImage();



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

void pilar()
{
	glPushMatrix(); //pilares

	glTranslatef(0, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pilares
	glTranslatef(2, -10,0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(-2, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();




}

void torreh()
{

	glPushMatrix();



	glPushMatrix(); //CUADRO PRINCIPAL
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);

	fig1.prisma(15, 5, 10, ventanah.GLindex, 6, 12);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //cuadro de abajo
	glTranslatef(0,-5,0 );
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
    fig1.prisma(15, 1,3, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //PARTE DE abajo
	glTranslatef(0, -7.5, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.prisma(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //PARTE DE ARRIBA
	glTranslatef(0, 7.5, 0);
	glColor3f(1, 0, 0);
	glDisable(GL_LIGHTING);
	fig1.prisma(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //LATERAL
	glTranslatef(0, 0, -5.1);
	glColor3f(1, 0, 0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15.2, 5, .2, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //LATERAL
	glTranslatef(0, 0, 5.1);
	glColor3f(1,0, 0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15.2, 5, .2, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pilar1
	glTranslatef(0,0,0);
	pilar();
	glPopMatrix();

	glPushMatrix(); //pilar2
	glTranslatef(0, 0, 2);
	pilar();
	glPopMatrix();

	glPushMatrix(); //pilar2
	glTranslatef(0, 0, 4);
	pilar();
	glPopMatrix();

	glPushMatrix(); //pilar3
	glTranslatef(0, 0, -4);
	pilar();
	glPopMatrix();

	glPushMatrix(); //pilar4
	glTranslatef(0, 0, -2);
	pilar();
	glPopMatrix();





	glPopMatrix();

	glPopMatrix();



}




void pilaresder(){



	glPushMatrix(); //pilares

	glTranslatef(0, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pilares
	glTranslatef(2, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(4, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pilares
	glTranslatef(6, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(8, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(10, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(12, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(14, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(16, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(18, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(20, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(22, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(24, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(26, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(28, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(30, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(32, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(34, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(36, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(38, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(40, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pilares
	glTranslatef(42, -10, 0);
	glColor3f(.8, .8, .8);
	glDisable(GL_LIGHTING);
	fig1.cilindro(.2, 5, 10, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();



}




void derecho()
{

	glPushMatrix();



	glPushMatrix(); //lado derecho
	glTranslatef(-20,0,0);
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15, 35, 5, ventanaderecho.GLindex, 25, 3);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();



	glPushMatrix(); //centro
	glTranslatef(2.5, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15, 10, 5, centroder.GLindex, 2, 3);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //abajo
	glTranslatef(2.5, -7.6, 0);
	glColor3f(0, 0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(.2, 80.4, 5, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //arriba
	glTranslatef(2.5, 7.7, 0);
	glColor3f(0,0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(.2, 80.4, 5, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //parte que sale
	glTranslatef(37.4, -2.5, 3.5);
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(10, 10, 3, ventanaderecho.GLindex, 10, 3);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //lateral der
	glTranslatef(42.7, 0, 0);
	glColor3f(0,0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15.5, .2, 5,0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix(); //lateral izq
	glTranslatef(-37.6, 0, 0);
	glColor3f(0, 0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15.5, .2, 5, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //lado izquierdo
	glTranslatef(25, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	fig1.prisma(15, 35, 5, ventanaderecho.GLindex, 25, 3);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0,0,-2);
	pilaresder();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2);
	pilaresder();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-37.5, 0, 2);
	pilaresder();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-37.5, 0, -2);
	pilaresder();
	glPopMatrix();
	
	glPopMatrix();





}

void central(){
	glPushMatrix();


glPushMatrix(); //central
glColor3f(.89, .16, .16);
glDisable(GL_LIGHTING);
glTranslatef(-60, 13.2, -30);
fig1.prisma(20, 20, 7.5, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, 13., -26);
fig1.prisma(20, 20, .2, central4.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(0, .16, .16);
glDisable(GL_LIGHTING);
glTranslatef(-50, 13., -30);
fig1.prisma(20, .2, 7.9, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(0, .16, .16);
glDisable(GL_LIGHTING);
glTranslatef(-70, 13., -30);
fig1.prisma(20, .2, 7.9, 0);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //central
glColor3f(0, .16, .16);
glDisable(GL_LIGHTING);
glTranslatef(-60, 13., -34);
fig1.prisma(20, 20, .2, 0);
glEnable(GL_LIGHTING);
glPopMatrix();





glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, .1, -30);
fig1.prisma(.2, 20, 7.5, 0);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, 1.7, -30);
fig1.prisma(3, 20, 7.5, ventanacentral.GLindex, 3, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //mural1
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, 1.5, -20);
fig1.prisma(3, 10, .2, bibliolat1.GLindex,1,1);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, 1.5, -23.2);
fig1.prisma(3, .2, 6.2, central1.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-50, 1.5, -23.2);
fig1.prisma(3, .2, 6.2, central2.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-50, -5, -40);
fig1.prisma(10, .2, 40, lateral.GLindex,40,10);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //mural1
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, -20);
fig1.prisma(10, 10, .2, lateral.GLindex, 5, 10);
glEnable(GL_LIGHTING);
glPopMatrix();





glPopMatrix();
}

void suelo()
{



glPushMatrix(); //base general
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(0, -5, 0);
fig1.prisma(.1, 200, 115, rocas.GLindex,150, 150);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //RAMPA 
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-45, -8.4, 9);
glRotatef(-15,1,0,0);
fig1.prisma(10, 10, 20, rocas.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //RAMPA mini
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-56, -5.6,22);
glRotatef(85, 0,0, 1);
fig1.prisma(11, 10, 10, rocas.GLindex, 5, 7);
glEnable(GL_LIGHTING);
glPopMatrix();






glPushMatrix(); //RAMPA BARDITA
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-40, -7.9, 9);
glRotatef(-15, 1, 0, 0);
fig1.prisma(10, .2, 20, lateral.GLindex, 5, 7);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix();
glPushMatrix(); //PARTE ELEVADA
glColor3f(1, 1, .75);
glDisable(GL_LIGHTING);
glTranslatef(-45, -6,22.5);

fig1.prisma(10,10, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //cuadro de enfrente
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-45, -6, 22.5);
fig1.prisma(10, 10, 10, rocas.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();






glPushMatrix(); //desnivelbiblio
glColor3f(.86, .86, .86);
glDisable(GL_LIGHTING);
glTranslatef(-75, -5, -40);
fig1.prisma(10, 50, 40, suelorojo.GLindex, 50, 40);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //desnivelbiblio
glColor3f(1,1,1);
glDisable(GL_LIGHTING);
glTranslatef(-80, -5, 5);
fig1.prisma(10, 40, 50, basedesnivel.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, 3.5);
fig1.prisma(9.5, 10, 27,arriba.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras pte1
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, -10);
fig1.prisma(9.5, 10, .2, lateral.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras pte2
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, 17);
fig1.prisma(9.5, 10, .2, lateral.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras pte3
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-50, -5, 3.5);
fig1.prisma(9.5, .2, 27, forraje.GLindex, 9, 10);
glEnable(GL_LIGHTING);
glPopMatrix();






glPushMatrix(); //escalon1
glColor3f(0, 0, 0);
glDisable(GL_LIGHTING);
glTranslatef(-55, -4.5, -15);
fig1.prisma(.5, 10, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon2
glColor3f(1, 0, 0);
glDisable(GL_LIGHTING);
glTranslatef(-55, -4, -15);
fig1.prisma(.5, 9, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon3
glColor3f(0, 1, 0);
glDisable(GL_LIGHTING);
glTranslatef(-55, -3.5, -15);
fig1.prisma(.5, 8, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon4
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -3, -15);
fig1.prisma(.5, 7, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon5
glColor3f(1, 1, 0);
glDisable(GL_LIGHTING);
glTranslatef(-60, -2.5, -15);
fig1.prisma(.5, 6, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon6
glColor3f(1, 0, 0);
glDisable(GL_LIGHTING);
glTranslatef(-60, -2, -15);
fig1.prisma(.5, 3, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon7
glColor3f(0, 1, 0);
glDisable(GL_LIGHTING);
glTranslatef(-60, -1.5, -15);
fig1.prisma(.5, 2, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon8
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, -1, -15);
fig1.prisma(.5, 1, 10, 0);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //base pasto islas
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(10, -5, -10);
/*glTexCoord2f(50, 100);
glTexCoord2f(100, 50);*/
fig1.prisma(.2, 90, 30, pasto.GLindex, 25, 75);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //pista
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(10,-5, -25.5);

fig1.prisma(.2, 90, 1,pista.GLindex, 1, 75);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //pistalateral
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(55.5, -5, -10);
fig1.prisma(.2, 1, 32,  pistah.GLindex, 30, 1);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //pistalateral
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(-35.5, -5, -10);
fig1.prisma(.2, 1, 32, pistah.GLindex, 30, 1);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //pista
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(10, -5, 5.5);

fig1.prisma(.2, 90, 1, pista.GLindex, 1, 90);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //base pasto islas
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(15, -54, -15);
fig1.esfera(50, 10, 10, pasto.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //base pasto islas
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(0, -9.5, 0);

fig1.esfera(5, 10, 10, pasto.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //base pasto islas
glColor3f(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
glTranslatef(-15, -54, -15);
fig1.esfera(50, 10, 10, pasto.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPopMatrix();

}
















void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glColor3f(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(200.0, 130.0, 115.0, text1.GLindex);

	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //biblioteca central 
	central();
	glPopMatrix();

	glPushMatrix(); //cargamos suelo 
	suelo();
	glPopMatrix();


	glPushMatrix(); //cargamos torre de humanidades 
	glTranslatef(60, 4, -10);
	torreh();	
	glPopMatrix();



	glPushMatrix(); //cargamos derecho 
	glTranslatef(-5.5, 5, -40);
	derecho();
	glPopMatrix();









	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
		glColor3f(0.0,0.0,0.0);
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
	
	/*fig2.text_izq-= 0.001;
	fig2.text_der-= 0.001;
	if(fig2.text_izq<-1)
		fig2.text_izq=0;
	if(fig2.text_der<0)
		fig2.text_der=1;*/
	giro-= 0.4;
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
			angulo1 += 2.5;
			break;

		case 'R':		//
			angulo1 -= 2.5;

			break;

		case 'g':		//
			angulo3 += 2.5;
			break;

		case 'G':		//
			angulo3 -= 2.5;

			break;
		case 'f':		//
			angulo2 += 2.5;
			break;
		case 'F':
			angulo2 -= 2.5;

			
			break;

		




		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
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
