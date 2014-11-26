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
//#include "cmodel/CModel.h"

float angulo1 = 0.0;
float angulo2 = 0.0;
float angulo3 = 0.0;
float giro = 0.0;
float offset2 = 0;
float offset = 0;
bool g_fanimacion = false;
//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float movBrazoDer = 0.0;
float movBrazoIzq = 0.0;
float rotRodDer = 0.0;
float movBrazoDerF = 0.0;
//animación sol
float movX = 0.0;
float movY = 0.0;
float Vo = 60.0;
float angulo =20 * 3.1416 / 180;
float t = 0.0;
bool mov_esfera = false;


DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


#define MAX_FRAMES 30
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;

	

	float giroMonitoInc;
	float movBrazoDer;
	float movBrazoDerInc;
	float movBrazoIzq;
	float movBrazoIzqInc;
	float rotRodDer;
	float rotRodDerInc;
	float movBrazoDerF;
	float movBrazoDerFInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];

int FrameIndex = 10;			//introducir datos
bool play = false;

int playIndex = 0;



//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];
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
CTexture mojito;
CTexture ventanarec;
CTexture forraje;
CTexture pasto;
CTexture nieve;
CTexture lluvia;
CTexture snow;
CTexture meteoro;

int year = 0, day = 0;
int year_m = 0, day_m = 0;
int rotMoon = 0;
CTexture ventanah;
CTexture ventanaderecho;
CTexture pista;
CTexture escalon;
CTexture pistah;
CTexture arriba;
CTexture bibliolat1;
CTexture biblioteca;
CTexture central2;
CTexture rocas;
CTexture muralrec;
CTexture muralrec1;
CTexture loseta;
CTexture lateral;
CTexture suelorojo;
CTexture centroder;
CTexture basedesnivel;
CTexture central1;
CTexture ventanacentral;
CTexture centralnorte;
CTexture centralsur;
//CTexture ventanasarqui;
/////INGENIERIA
CTexture t_textura;
CTexture ventana;
CTexture entrada;
CTexture pared;
CTexture pared2;
CTexture pared3;
CTexture pared4;
CTexture pared5;
CTexture pared6;
CTexture pared7;
CTexture bordes;
CTexture letrero;


CTexture arquiEdificioLArriba;
CTexture arquiEdificioLAtras;
CTexture arquiEdificioLFrente;
CTexture arquiMucaArriba;
CTexture arquiMucaFrente;
CTexture arquiPrincipalArriba;
CTexture arquiPrincipalLados;
CTexture ventanasarqui;
CTexture letrero2;
CTexture ventanas;
CTexture ventanas2;
CTexture ventanas3;
CTexture edificio;
CTexture baranda;
CTexture puentes;
CTexture techos;
CTexture techos2;
CTexture techos3;
CTexture jellyfish;
//FIN INGENIERIA

CTexture ladrillosarqui;
CTexture centraloriente;
CTexture rec;
CTexture agua;
CTexture caja;
CTexture centralponiente;
CFiguras fig1;
CFiguras fig2;
CFiguras fig3;


GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };
CFiguras fig7;



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


	jellyfish.LoadTGA("Texturas/jellyfish.tga");
	jellyfish.BuildGLTexture();
	jellyfish.ReleaseImage();

	pista.LoadTGA("Texturas/pista.tga");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	pista.BuildGLTexture();
	pista.ReleaseImage();

	mojito.LoadTGA("Texturas/nombres.tga");
	mojito.BuildGLTexture();
	mojito.ReleaseImage();

	escalon.LoadTGA("Texturas/escalon.tga");
	escalon.BuildGLTexture();
	escalon.ReleaseImage();

	agua.LoadTGA("Texturas/agua.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();

	caja.LoadTGA("Texturas/caja.tga");
	caja.BuildGLTexture();
	caja.ReleaseImage();
	///INGE
	pared.LoadBMP("Texturas/muro.bmp");
	pared.BuildGLTexture();
	pared.ReleaseImage();

	pared2.LoadBMP("Texturas/muro2.bmp");
	pared2.BuildGLTexture();
	pared2.ReleaseImage();

	pared3.LoadBMP("Texturas/muro3.bmp");
	pared3.BuildGLTexture();
	pared3.ReleaseImage();

	letrero.LoadBMP("Texturas/letrero.bmp");
	letrero.BuildGLTexture();
	letrero.ReleaseImage();

	letrero2.LoadBMP("Texturas/letrero2.bmp");
	letrero2.BuildGLTexture();
	letrero2.ReleaseImage();

	ventanas.LoadBMP("Texturas/ventana.bmp");
	ventanas.BuildGLTexture();
	ventanas.ReleaseImage();

	ventanas2.LoadBMP("Texturas/ventana2.bmp");
	ventanas2.BuildGLTexture();
	ventanas2.ReleaseImage();

	ventanas3.LoadBMP("Texturas/ventana3.bmp");
	ventanas3.BuildGLTexture();
	ventanas3.ReleaseImage();

	pared4.LoadBMP("Texturas/muro4.bmp");
	pared4.BuildGLTexture();
	pared4.ReleaseImage();

	pared5.LoadBMP("Texturas/muro5.bmp");
	pared5.BuildGLTexture();
	pared5.ReleaseImage();

	pared6.LoadBMP("Texturas/muro6.bmp");
	pared6.BuildGLTexture();
	pared6.ReleaseImage();

	pared7.LoadBMP("Texturas/muro7.bmp");
	pared7.BuildGLTexture();
	pared7.ReleaseImage();

	bordes.LoadBMP("Texturas/borde.bmp");
	bordes.BuildGLTexture();
	bordes.ReleaseImage();

	edificio.LoadBMP("Texturas/edif.bmp");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();

	baranda.LoadBMP("Texturas/barandal.bmp");
	baranda.BuildGLTexture();
	baranda.ReleaseImage();

	puentes.LoadBMP("Texturas/puente.bmp");
	puentes.BuildGLTexture();
	puentes.ReleaseImage();

	techos.LoadBMP("Texturas/techo.bmp");
	techos.BuildGLTexture();
	techos.ReleaseImage();

	techos2.LoadBMP("Texturas/techo2.bmp");
	techos2.BuildGLTexture();
	techos2.ReleaseImage();

	techos3.LoadBMP("Texturas/techo3.bmp");
	techos3.BuildGLTexture();
	techos3.ReleaseImage();
//FIN INGE
	rec.LoadTGA("Texturas/rec.tga");
	rec.BuildGLTexture();
	rec.ReleaseImage();

	biblioteca.LoadTGA("Texturas/biblioteca.tga");
	biblioteca.BuildGLTexture();
	biblioteca.ReleaseImage();


	loseta.LoadTGA("Texturas/loseta.tga");
	loseta .BuildGLTexture();
	loseta.ReleaseImage();

	muralrec.LoadTGA("Texturas/muralrec.tga");
	muralrec.BuildGLTexture();
	muralrec.ReleaseImage();
	muralrec1.LoadTGA("Texturas/muralrec1.tga");
	muralrec1.BuildGLTexture();
	muralrec1.ReleaseImage();



	ventanacentral.LoadTGA("Texturas/ventanacentral.tga");
	ventanacentral.BuildGLTexture();
	ventanacentral.ReleaseImage();


	ladrillosarqui.LoadTGA("Texturas/ladrillosarqui.tga");
	ladrillosarqui.BuildGLTexture();
	ladrillosarqui.ReleaseImage();


	central2.LoadTGA("Texturas/central2.tga");
	central2.BuildGLTexture();
	central2.ReleaseImage();


	central1.LoadTGA("Texturas/central.tga");
	central1.BuildGLTexture();
	central1.ReleaseImage();

	centralnorte.LoadTGA("Texturas/norte.tga");
	centralnorte.BuildGLTexture();
	centralnorte.ReleaseImage();

	

	centralsur.LoadTGA("Texturas/sur.tga");
	centralsur.BuildGLTexture();
	centralsur.ReleaseImage();

	centraloriente.LoadTGA("Texturas/oriente.tga");
	centraloriente.BuildGLTexture();
	centraloriente.ReleaseImage();

	centralponiente.LoadTGA("Texturas/poniente.tga");
	centralponiente.BuildGLTexture();
	centralponiente.ReleaseImage();





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




	arquiEdificioLArriba.LoadTGA("Texturas/arquiEdificioLArriba.tga");
	arquiEdificioLArriba.BuildGLTexture();
	arquiEdificioLArriba.ReleaseImage();

	arquiEdificioLAtras.LoadTGA("Texturas/arquiEdificioLAtras.tga");
	arquiEdificioLAtras.BuildGLTexture();
	arquiEdificioLAtras.ReleaseImage();

	arquiEdificioLFrente.LoadTGA("Texturas/arquiEdificioLFrente.tga");
	arquiEdificioLFrente.BuildGLTexture();
	arquiEdificioLFrente.ReleaseImage();

	arquiMucaArriba.LoadTGA("Texturas/arquiMucaArriba.tga");
	arquiMucaArriba.BuildGLTexture();
	arquiMucaArriba.ReleaseImage();

	arquiMucaFrente.LoadTGA("C:Texturas/arquiMucaFrente.tga");
	arquiMucaFrente.BuildGLTexture();
	arquiMucaFrente.ReleaseImage();

	arquiPrincipalArriba.LoadTGA("arquiPrincipalArriba.tga");
	arquiPrincipalArriba.BuildGLTexture();
	arquiPrincipalArriba.ReleaseImage();

	arquiPrincipalLados.LoadTGA("Texturas/arquiPrincipalLados.tga");
	arquiPrincipalLados.BuildGLTexture();
	arquiPrincipalLados.ReleaseImage();


	ventanasarqui.LoadTGA("Texturas/ventanasarqui.tga");
	ventanasarqui.BuildGLTexture();
	ventanasarqui.ReleaseImage();

	pistah.LoadTGA("Texturas/pistah.tga");
	pistah.BuildGLTexture();
	pistah.ReleaseImage();


	basedesnivel.LoadTGA("Texturas/basedesnivel.tga");
	basedesnivel.BuildGLTexture();
	basedesnivel.ReleaseImage();


	centroder.LoadTGA("Texturas/centroder.tga");
	centroder.BuildGLTexture();
	centroder.ReleaseImage();



	ventanarec.LoadTGA("Texturas/ventanas2rec.tga");
	ventanarec.BuildGLTexture();
	ventanarec.ReleaseImage();

	pasto.LoadTGA("Texturas/islas.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();


	ventanah.LoadTGA("Texturas/ventanah.tga");
	ventanah.BuildGLTexture();
	ventanah.ReleaseImage();


	ventanaderecho.LoadTGA("Texturas/ventanaderecho.tga");
	ventanaderecho.BuildGLTexture();
	ventanaderecho.ReleaseImage();

	nieve.LoadTGA("Texturas/nieve.tga");
	nieve.BuildGLTexture();
	nieve.ReleaseImage();

	snow.LoadTGA("Texturas/snow.tga");
	snow.BuildGLTexture();
	snow.ReleaseImage();

	lluvia.LoadTGA("Texturas/lluvia.tga");
	lluvia.BuildGLTexture();
	lluvia.ReleaseImage();

	meteoro.LoadTGA("Texturas/meteor.tga");
	meteoro.BuildGLTexture();
	meteoro.ReleaseImage();

	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].posY = 0;
		KeyFrame[i].posZ = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].rotRodIzq = 0;
		KeyFrame[i].rotInc = 0;
		KeyFrame[i].giroMonito = 0;
		KeyFrame[i].giroMonitoInc = 0;
		KeyFrame[i].rotRodDer = 0;
		KeyFrame[i].rotRodDerInc = 0;
		KeyFrame[i].movBrazoDer = 0;
		KeyFrame[i].movBrazoDerInc = 0;
		KeyFrame[i].movBrazoIzq = 0;
		KeyFrame[i].movBrazoIzqInc = 0;
	}


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







void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, 0);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(movBrazoIzq, 0.0, 0.0, 1.0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodDer, 1, 0, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}







void cajas()
{

	glPushMatrix(); //caja1
	glColor3f(1,1,1);
	glDisable(GL_LIGHTING);
	glTranslatef(-83.5, 1, 26);
	fig1.prisma(2, 4, 3, caja.GLindex, 4, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //caja2
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-87, 1, 26.5);
	fig1.prisma(2, 3, 2, caja.GLindex, 3, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //techo cajas
	glColor3f(.89, .16, .16);
	glDisable(GL_LIGHTING);
	glTranslatef(-85, 2.1, 25.5);
	fig1.prisma(.2, 7, 4, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //suelo cajas
	glColor3f(1,1,1);
	glDisable(GL_LIGHTING);
	glTranslatef(-85, .1, 25.5);
	fig1.prisma(.2, 7, 4, loseta.GLindex, 7, 4);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pared derecha
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-88.6, 1.1, 25.5);
	fig1.prisma(2.2, .2, 4, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pared izquierda
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-81.4, 1.1, 25.5);
	fig1.prisma(2.2, .2, 4, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //pared trasera
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-85, 1.1, 27.5);
	fig1.prisma(2.2, 7.4, .2, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();



}





void arquitectura(){



	fig2.arquiPrincipal(arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalArriba.GLindex);
	fig2.arquiEdificioL(arquiEdificioLFrente.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiEdificioLAtras.GLindex, arquiEdificioLArriba.GLindex);
	fig2.arquiMuca(arquiMucaFrente.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiPrincipalLados.GLindex, arquiMucaArriba.GLindex);
	fig2.arquiCuartoArriba(arquiPrincipalArriba.GLindex, arquiPrincipalArriba.GLindex, arquiPrincipalArriba.GLindex, arquiPrincipalArriba.GLindex, arquiPrincipalArriba.GLindex);



	//glPushMatrix(); //central de arqui
	//glColor3f(1, 1, 1);
	//glDisable(GL_LIGHTING);
	//glTranslatef(-65, 2, 40);
	//fig1.prisma(4, 10, 5, ventanasarqui.GLindex, 20, 4);
	//glEnable(GL_LIGHTING);
	//glPopMatrix();



	//glPushMatrix(); //central de arqui
	//glColor3f(1, 1, 1);
	//glDisable(GL_LIGHTING);
	//glTranslatef(-65, 2, 41);
	//fig1.prisma(4.1, 11, 6, ladrillosarqui.GLindex, 20, 4);
	//glEnable(GL_LIGHTING);
	//glPopMatrix();

	//glPushMatrix(); //central de arqui
	//glColor3f(1, 1, 1);
	//glDisable(GL_LIGHTING);
	//glTranslatef(-55.6, 2, 38.2);
	//fig1.prisma(4., 30, 1, ladrillosarqui.GLindex, 20, 4);
	//glEnable(GL_LIGHTING);
	//glPopMatrix();


}

void rectoria()
{


	glPushMatrix(); //central
	glColor3f(1,1,1);
	glDisable(GL_LIGHTING);
	glTranslatef(-80, 15.2,0);
	fig1.prisma(30, 15, 15, ventanarec.GLindex, 10, 15);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //central
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-90, 2, 7);
	fig1.prisma(4, 15, 15,rec.GLindex, 5, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //centraltecho
	glColor3f(.72, .47,.33);
	glDisable(GL_LIGHTING);
	glTranslatef(-90, 4.1, 7);
	fig1.prisma(.2, 15, 15, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //central mural
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-90, 2.9, 14.6);
	fig1.prisma(2.5, 15, .2, muralrec.GLindex, 1, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	glPushMatrix(); //central mural 2
	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glTranslatef(-92.5, 2.9,-.5);
	fig1.prisma(2.5, 10, .2, muralrec1.GLindex, 1, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

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

void ingenieria()
{
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, textura[5].texID);
	//vec1=CVector(12.5f, 0.0f, -12.5f)-CVector(12.5f, 0.0f, 12.5f);
	//vec2=CVector(-12.5f, 0.0f, 12.5f)-CVector(12.5f, 0.0f, 12.5f);
	//N=Normaliza(Cruz(vec1, vec2));
	//glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-19, -4, 30);
	glColor3f(1.0f, 1.0f, 1.0f);
	fig1.prisma(2.5, 5.0, 5.0, entrada.GLindex);//Entrada
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-24.5, -4, 30);
	glColor3f(1.0f, 1.0f, 1.0f);
	fig1.prisma(8.0, 6.5, 5.0, pared7.GLindex);//Muro Izq
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-17.5, -2.0, 33.3);
	glColor3f(1.0f, 1.0f, 1.0f);
	fig1.prisma(1.5, 11.8, 1.5, letrero.GLindex);//Letrero
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-16.2, -4, 33.2);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.5, 0.5, 1.5, pared.GLindex);//Muro Derecho Pequeño
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-16.2, -4.5, 35.5);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.6, 0.5, 3.5, pared2.GLindex);//Muro Derecho Continuación
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-14.0, -4.0, 33.2);
	glColor3f(0.5f, 0.5f, 0.5f);//Gris
	fig1.prisma(2.6, 4.0, 1.5, 0);//Muro Derecho Frente
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-7.0, -4.5, 37.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.6, 18.5, 0.5, pared2.GLindex);//Muro Derecho Frente Continuación
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.5, -4.5, 34.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.6, 1.5, 6.0, pared2.GLindex);//Muro Derecho Frente Continuación2
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.5, -4.0, 30.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.8, 1.5, 9.5, pared4.GLindex);//Muro Derecho Frente Continuación3
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.5, -4.0, 23.9);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.8, 1.5, 3.0, pared5.GLindex);//Muro Derecho Frente Continuación4 atrás
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.5, -4.0, 21.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.8, 1.5, 3.0, pared6.GLindex);//Muro Derecho Frente Continuación5 atrás
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.5, -4.0, 12.5);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(2.8, 1.5, 14.0, pared5.GLindex);//Muro Derecho Frente Continuación6 atrás
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-24.3, 1.0, 29.5);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 7.2, 8.3, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-24.3, 0.5, 29.5);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.7, 7.2, 8.3, ventanas.GLindex);//Ventanas0
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-17.3, 1.0, 29.4);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 8.0, 8.3, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-17.3, -0.0, 29.4);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(1.5, 8.0, 8.3, ventanas.GLindex);//Ventanas
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.35, -2.0, 32.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Rojo
	fig1.prisma(1.5, 1.5, 1.2, letrero2.GLindex);//Letrero/Cerca
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.3, 1.0, 28.9);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 9.0, 7.3, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.3, -0.0, 28.9);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(1.5, 9.0, 7.3, ventanas.GLindex);//Ventanas2
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-12.0, -2.0, 32.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Rojo
	fig1.prisma(1.5, 8.3, 1.2, letrero2.GLindex);//Franja Roja
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-2.8, 1.0, 29.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 10.0, 7.5, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-2.8, -1.0, 29.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(3.5, 10.0, 7.5, ventanas.GLindex);//Ventanas3
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.2, 1.0, 32.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 2.0, 1.5, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.2, -1.0, 32.0);
	glColor3f(0.7f, 0.8f, 0.9f);//Azul
	fig1.prisma(3.5, 2.0, 1.5, pared3.GLindex);//Ventanas4
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.2, 1.0, 28.2);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 2.0, 6.0, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.2, -1.0, 28.2);
	glColor3f(0.7f, 0.8f, 0.9f);//Azul
	fig1.prisma(3.5, 2.0, 6.0, ventanas2.GLindex);//Ventanas5
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-10.0, 6.1, 30.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(0.1, 25.0, 2.5, bordes.GLindex);//Base
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-10.0, 3.2, 30.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(4.0, 25.0, 2.5, edificio.GLindex);//Edificio A
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-25.0, 1.5, 30.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(1.0, 5.0, 2.5, baranda.GLindex);//Edificio Apequeño
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-10.0, 5.0, 30.0);
	glColor3f(1.0f, 1.0f, 1.0f);//Azul
	fig1.prisma(1.0, 22.0, 2.3, ventanas3.GLindex);//Edificio A-2
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-13.6, -4.0, 25.2);
	glColor3f(0.5f, 0.5f, 0.5f);//Gris
	fig1.prisma(9.9, 28.5, 0.1, 0);//Pared
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-20.0, -4.0, 23.2);
	glColor3f(0.5f, 0.5f, 0.5f);//Gris
	fig1.prisma(1.0, 3.5, 7.5, puentes.GLindex);//Puente
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-21.5, -4.0, 15.2);
	glColor3f(0.8f, 0.0f, 0.0f);//Gris
	fig1.prisma(1.0, 6.5, 9.5, techos.GLindex);//Edificio B
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-22.9, -4.0, 9.5);
	glColor3f(0.8f, 0.0f, 0.0f);//Gris
	fig1.prisma(1.0, 3.5, 9.5, techos.GLindex);//Edificio C
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-20.8, -4.0, 6.0);
	glColor3f(0.8f, 0.0f, 0.0f);//Gris
	fig1.prisma(1.0, 7.8, 3.5, techos.GLindex);//Edificio C-2
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-8.5, -4.0, 16.5);
	glColor3f(0.8f, 0.0f, 0.0f);//Negro
	fig1.prisma(4.0, 10.0, 20.0, techos.GLindex);//Edificio 3
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-1.0, -4.0, 19.5);
	glColor3f(1.0f, 1.0f, 1.0f);//Negro
	fig1.prisma(4.0, 4.6, 11.0, techos3.GLindex);//Edificio 3.extra
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-5.8, -1.6, 15.7);
	//glColor3f(0.5f, 0.1f, 0.2f);//Negro
	fig1.prisma(0.5, 7.5, 14.0, techos2.GLindex);//Edificio D
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-14.5, -4.0, 5.6);
	glColor3f(0.8f, 0.0f, 0.0f);//Negro
	fig1.prisma(3.8, 5.0, 2.0, techos.GLindex);//Edificio F
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
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
glColor3f(1,1,1);
glDisable(GL_LIGHTING);
glTranslatef(-60, 13., -26);
fig1.prisma(20, 20,.2, centralsur.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-70, 13., -30);
fig1.prisma(20, .2, 7.9, centralponiente.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //central
glColor3f(1, 1,1);
glDisable(GL_LIGHTING);
glTranslatef(-50, 13., -30);
fig1.prisma(20, .2, 7.9, centraloriente.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();



glPushMatrix(); //central
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, 13., -34);
fig1.prisma(20, 20, .2, centralnorte.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //mural agua
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-65, 2.8, -34.1);
fig1.prisma(5, 10, .3,biblioteca.GLindex, 1, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //agua
glColor3f(1, 1, 1);
glTranslatef(-65, .1, -36.1);
glScalef(10, .3, 5 );
glDisable(GL_LIGHTING);

fig1.prisma_anun( agua.GLindex,  0);
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


glPushMatrix(); //RAMPA arqui
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-45, -8.4, 34.5);
glRotatef(15, 1, 0, 0);
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

glPushMatrix(); //RAMPA BARDITA arqui
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-40, -7.9,34.5);
glRotatef(15, 1, 0, 0);
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



glPushMatrix(); //desnivelbiblio
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-80, -5, 40);
fig1.prisma(10,40, 30, basedesnivel.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, 3.5);
fig1.prisma(9.5, 10, 27,arriba.GLindex, 15, 10);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //desnivel parte izquierda vista de frente a las escaleras
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -5, 39);
fig1.prisma(9.5, 10, 27, arriba.GLindex, 15, 10);
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
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -4.5, -15);
fig1.prisma(.5, 10, 10, escalon.GLindex, 5, 10);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon2
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -4, -15);
fig1.prisma(.5, 9, 10, escalon.GLindex, 5, 9);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon3
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -3.5, -15);
fig1.prisma(.5, 8, 10, escalon.GLindex, 5,8);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon4
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-55, -3, -15);
fig1.prisma(.5, 7, 10, escalon.GLindex, 5, 7);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon5
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, -2.5, -15);
fig1.prisma(.5, 6, 10, escalon.GLindex, 5, 1);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //escalon6
glColor3f(1, 1,1);
glDisable(GL_LIGHTING);
glTranslatef(-60, -2, -15);
fig1.prisma(.5, 3, 10, escalon.GLindex, 5, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon7
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, -1.5, -15);
fig1.prisma(.5, 2, 10, escalon.GLindex, 5, 1);
glEnable(GL_LIGHTING);
glPopMatrix();


glPushMatrix(); //escalon8
glColor3f(1, 1, 1);
glDisable(GL_LIGHTING);
glTranslatef(-60, -1, -15);
fig1.prisma(.5, 1, 10, escalon.GLindex, 5, 1);
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
	
//moon
	glPushMatrix();
	glTranslatef(0.0, 40, 0.0);
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glRotatef(rotMoon, 1, 0, 0);
	glTranslatef(0.0, 40, 0.0);
	glColor3f(0.8, 0.8, 0.8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);


	glutWireSphere(1, 14, 14);//moon

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//sol
	glTranslatef(80, -2, -45);
		glPushMatrix();
	
		glColor3f(1, 1, 0);
		glDisable(GL_LIGHTING);
		glTranslatef(movX, movY, 0);
		fig1.esfera(4.0, 15.0, 15.0, 0);

		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPopMatrix();

	//agua
	glPushMatrix();

	glTranslatef(-60, .3, -39);
	glScalef(0.5, 0, .3);
	glRotatef(180, 0, 1, 1);
	glBindTexture(GL_TEXTURE_2D, agua.GLindex);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0 + offset, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 1.0);
	glVertex3f(20.0, 20.0, 0.0);
	glTexCoord2f(0.0 + offset, 1.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();


	//mono
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	glRotatef(giroMonito, 0, 1, 0);
	monito();
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
	//medusa
	glPushMatrix();
	glTranslatef(25,10,20);
	glRotatef(90, 1, 0, 0);

	glTranslatef(0, 0, 0);
	glScalef(0.5, 0, .3);
	glRotatef(90, 1, 1, 0);
	glBindTexture(GL_TEXTURE_2D, jellyfish.GLindex);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0 + offset, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 1.0);
	glVertex3f(20.0, 20.0, 0.0);
	glTexCoord2f(0.0 + offset, 1.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();


	//mojito
	glPushMatrix();
	glTranslatef(0, 15, -38);
	glRotatef(90, 1, 0, 0);

	glTranslatef(0, 0, 0);
	glScalef(0.5, 0, .3);
	glRotatef(-90, 1, 1, 0);
	glBindTexture(GL_TEXTURE_2D, mojito.GLindex);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0 + offset, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glTexCoord2f(1.0 + offset, 1.0);
	glVertex3f(20.0, 20.0, 0.0);
	glTexCoord2f(0.0 + offset, 1.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();



	glPushMatrix(); //biblioteca central 
	central();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,20);
	
	ingenieria();
	glPopMatrix();

	glPushMatrix(); //arquitectura 
	glTranslatef(-55,0,30);
	glScalef(.2,.2,.2);
	arquitectura();
	glPopMatrix();

	

	glPushMatrix(); //rectoria 
	rectoria();
	glPopMatrix();

	glPushMatrix(); //cargamos suelo 
	suelo();
	glPopMatrix();

	glPushMatrix(); //cargamos suelo 
	cajas();
	glPopMatrix();


	glPushMatrix(); //cargamos torre de humanidades 
	glTranslatef(60, 4, -10);
	torreh();	
	glPopMatrix();

	///////////////////////////////////////////////////
	//////////Nieve o lluvia segun textura/////////////
	///////////////////////////////////////////////////
	//Parámetros: (textura-nieve ó snow ó lluvia, velocidad de caida, x, y, z, cantidad de planos, raiz de cantidad de texturas por plano)
	glPushMatrix();
		glTranslatef(-100.0,0.0,-57.5);
		fig1.nieve_lluvia(lluvia.GLindex, 0.03, 200, 130, 115, 21, 20);
	glPopMatrix();

	glPushMatrix(); //cargamos derecho 
	glTranslatef(-5.5, 5, -40);
	derecho();
	glPopMatrix();

	//Elementos a crear: AGUA moviendose
	glPushMatrix();
	glDisable(GL_LIGHTING);	//Para que este iluminado siempre de la misma forma
	//	glEnable(GL_ALPHA_TEST);//Habilita la transparencia si es que la imagen tiene trasnparencia. Debe de ser antes del glBinTexture
	glEnable(GL_BLEND);//Habilita la transparencia si es que la imagen tiene trasnparencia. Debe de ser antes del glBinTexture
	//glAlphaFunc(GL_GREATER,0.1);//Si se tiene una tranaprecia mayor a 0.1 se utiliza
	//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
	glBindTexture(GL_TEXTURE_2D, agua.GLindex);//El objeto no se ve afectado por la texturade arriba
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0 + offset, 0 + offset2); glVertex3f(0, 0, 0);	//+offset es para simular movimiento horizontal
	glTexCoord2f(1 + offset, 0 + offset2); glVertex3f(20, 0, 0);//+offset2 es movimiento vertical
	glTexCoord2f(1 + offset, 1 + offset2); glVertex3f(20, 20, 0);
	glTexCoord2f(0 + offset, 1 + offset2); glVertex3f(0, 20, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	//	glDisable(GL_ALPHA_TEST);//Desabilita la transparecia, siempre desspues del objeto
	glDisable(GL_BLEND);
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

	dwCurrentTime = GetTickCount(); 
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		year = ((year + 3) % 360);
	
		day = (day + 5) % 360;
		day_m = (day_m + 1) % 360;
		year_m = (year_m + 2) % 360;
		rotMoon = (rotMoon -1) % 360;
		

		dwLastUpdateTime = dwCurrentTime;
	}


//movimiento del sol
	if (mov_esfera)
	{
	movX = -Vo * t * cos(angulo);
	movY = (Vo*t*sin(angulo))-(0.5*9.817*t*t);
	t  += 0.003;
	if (movX <= -200.0){
		movY = 0.0;
		movX = 0.0;
		t = 0.0;
	}

	}

	//movimiento de imagenes
	offset += 0.001;
	offset2 += 0.001;
	fig2.text_izq-= 0.001;
	fig2.text_der-= 0.001;
	if(fig2.text_izq<-1)
		fig2.text_izq=0;
	if(fig2.text_der<0)
		fig2.text_der=1;
	giro-= 0.4;
	if (play) //reprodece animacion con la tecla L
	{
		//dterminar cuando termina la animacion 
		if ((abs(KeyFrame[playIndex + 1].posX - posX))<0.1 &&
			(abs(KeyFrame[playIndex + 1].posY - posY))<0.1 &&
			(abs(KeyFrame[playIndex + 1].posZ - posZ))<0.1
			&&
			(abs(KeyFrame[playIndex + 1].rotRodIzq - rotRodIzq))<0.1 &&
			(abs(KeyFrame[playIndex + 1].giroMonito - giroMonito))<0.1 &&
			(abs(KeyFrame[playIndex + 1].movBrazoDer - movBrazoDer))<0.1 &&
			(abs(KeyFrame[playIndex + 1].movBrazoIzq - movBrazoIzq))<0.1 &&
			(abs(KeyFrame[playIndex + 1].rotRodDer - rotRodDer))<0.1
			)
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
		}
		else //Calculo de la interpolacion
		{
			KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / 100;		//100 frames
			posX += KeyFrame[playIndex].incX;

			KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / 100;		//100 frames
			posY += KeyFrame[playIndex].incY;

			KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / 100;		//100 frames
			posZ += KeyFrame[playIndex].incZ;

			KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / 100;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			KeyFrame[playIndex].movBrazoIzqInc = (KeyFrame[playIndex + 1].movBrazoIzq - KeyFrame[playIndex].movBrazoIzq) / 100;
			movBrazoIzq += KeyFrame[playIndex].movBrazoIzqInc;

			KeyFrame[playIndex].rotRodDerInc = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / 100;
			rotRodDer += KeyFrame[playIndex].rotRodDerInc;

			KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / 100;		//100 frames
			rotRodIzq += KeyFrame[playIndex].rotInc;

			KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / 100;		//100 frames
			giroMonito += KeyFrame[playIndex].giroMonitoInc;

		}

	}

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

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



	case'Z':
	case'z':
		mov_esfera = !mov_esfera;
		break;
	

	case 'l':
	case 'L':
		KeyFrame[0].posX = 0.0;
		KeyFrame[0].posY = 2.5;
		KeyFrame[0].posZ = -3.5;
		KeyFrame[0].rotRodIzq = 0.0;
		KeyFrame[0].rotRodDer = 0.0;
		KeyFrame[0].giroMonito = 0.0;
		KeyFrame[0].movBrazoDer = 0.0;
		KeyFrame[0].movBrazoIzq = 0.0;

		KeyFrame[1].posX = 0.0;
		KeyFrame[1].posY = 2.5;
		KeyFrame[1].posZ = -3.5;
		KeyFrame[1].rotRodIzq = 0.0;
		KeyFrame[1].rotRodDer = 0.0;
		KeyFrame[1].giroMonito = 0.0;
		KeyFrame[1].movBrazoDer = -70.0;
		KeyFrame[1].movBrazoIzq = 0.0;

		KeyFrame[2].posX = 0.0;
		KeyFrame[2].posY = 2.5;
		KeyFrame[2].posZ = -3.5;
		KeyFrame[2].rotRodIzq = 0.0;
		KeyFrame[2].rotRodDer = 0.0;
		KeyFrame[2].giroMonito = 0.0;
		KeyFrame[2].movBrazoDer = -70.0;
		KeyFrame[2].movBrazoIzq = 70.0;

		KeyFrame[3].posX = 0.0;
		KeyFrame[3].posY = 2.5;
		KeyFrame[3].posZ = -3.5;
		KeyFrame[3].rotRodIzq = 0.0;
		KeyFrame[3].rotRodDer = 0.0;
		KeyFrame[3].giroMonito = 0.0;
		KeyFrame[3].movBrazoDer = 200.0;
		KeyFrame[3].movBrazoIzq = -200.0;

		KeyFrame[4].posX = 0.0;
		KeyFrame[4].posY = 2.5;
		KeyFrame[4].posZ = -3.5;
		KeyFrame[4].rotRodIzq = 0.0;
		KeyFrame[4].rotRodDer = 0.0;
		KeyFrame[4].giroMonito = 0.0;
		KeyFrame[4].movBrazoDer = 90.0;
		KeyFrame[4].movBrazoIzq = -200.0;

		KeyFrame[5].posX = 0.0;
		KeyFrame[5].posY = 2.5;
		KeyFrame[5].posZ = -3.5;
		KeyFrame[5].rotRodIzq = 0.0;
		KeyFrame[5].rotRodDer = 0.0;
		KeyFrame[5].giroMonito = 0.0;
		KeyFrame[5].movBrazoDer = 120.0;
		KeyFrame[5].movBrazoIzq = -140;

		KeyFrame[6].posX = 0.0;
		KeyFrame[6].posY = 2.5;
		KeyFrame[6].posZ = -3.5;
		KeyFrame[6].rotRodIzq = 0.0;
		KeyFrame[6].rotRodDer = 0.0;
		KeyFrame[6].giroMonito = 0.0;
		KeyFrame[6].movBrazoDer = 120;
		KeyFrame[6].movBrazoIzq = -140;

		KeyFrame[7].posX = 0.0;
		KeyFrame[7].posY = 5.0;
		KeyFrame[7].posZ = -3.5;
		KeyFrame[7].rotRodIzq = 0.0;
		KeyFrame[7].rotRodDer = 0.0;
		KeyFrame[7].giroMonito = 0.0;
		KeyFrame[7].movBrazoDer = 120;
		KeyFrame[7].movBrazoIzq = -140;

		KeyFrame[8].posX = 0.0;
		KeyFrame[8].posY = 2.5;
		KeyFrame[8].posZ = -3.5;
		KeyFrame[8].rotRodIzq = 0.0;
		KeyFrame[8].rotRodDer = 0.0;
		KeyFrame[8].giroMonito = 0.0;
		KeyFrame[8].movBrazoDer = 0.0;
		KeyFrame[8].movBrazoIzq = 0.0;
		
		KeyFrame[9].posX = 0.0;
		 KeyFrame[9].posY = 1.0;
		KeyFrame[9].posZ = -3.5;
		KeyFrame[9].rotRodIzq =0.0;
		KeyFrame[9].rotRodDer = 0.0;
		KeyFrame[9].giroMonito = 0.0;
		KeyFrame[9].movBrazoDer = 0.0;
		KeyFrame[9].movBrazoIzq = 0.0;

	



		if (play == false && (FrameIndex>1))
		{

			posX = KeyFrame[0].posX;
			posY = KeyFrame[0].posY;
			posZ = KeyFrame[0].posZ;

			rotRodIzq = KeyFrame[0].rotRodIzq;
			giroMonito = KeyFrame[0].giroMonito;
			movBrazoDer = KeyFrame[0].movBrazoDer;
			movBrazoIzq = KeyFrame[0].movBrazoIzq;
			rotRodDer = KeyFrame[0].rotRodDer;
			play = true;
			playIndex = 0;
		}
		else
		{
			play = false;
		}
		break;






		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;



		case 'i':
		case 'I':
			objCamera.Position_Camera(50, 2.5f, 7, 100, 2.5f, 0, 0, 1, 0);
			break;
		case 't':
		case 'T':
			objCamera.Position_Camera(-50, 2.5f, 7, -100, 2.5f, 0, 0, 1, 0);
			break;
		case 'y':
		case 'Y':
			objCamera.Position_Camera(0, 2.5f, 7, 50, 2.5f, 0, 0, 1, 0);
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
		case 'R':		//

			KeyFrame[0].posX = 60;
			KeyFrame[0].posY = -2.5;
			KeyFrame[0].posZ = -25;
			KeyFrame[0].rotRodIzq = 0.0;
			KeyFrame[0].rotRodDer = 0.0;
			KeyFrame[0].giroMonito = 0.0;
			KeyFrame[0].movBrazoDer = 0.0;
			KeyFrame[0].movBrazoIzq = 0.0;


			KeyFrame[1].posX = 60.0;
			KeyFrame[1].posY = -2.5;
			KeyFrame[1].posZ = 10;
			KeyFrame[1].rotRodIzq = 0.0;
			KeyFrame[1].rotRodDer = 0.0;
			KeyFrame[1].giroMonito = 0.0;
			KeyFrame[1].movBrazoDer = 90.0;
			KeyFrame[1].movBrazoIzq = -270.0;

			KeyFrame[2].posX = -10.0;
			KeyFrame[2].posY = -2.5;
			KeyFrame[2].posZ = 10;
			KeyFrame[2].rotRodIzq = 0.0;
			KeyFrame[2].rotRodDer = 0.0;
			KeyFrame[2].giroMonito = 0.0;
			KeyFrame[2].movBrazoDer = 90.0;
			KeyFrame[2].movBrazoIzq = -270.0;

		

			KeyFrame[3].posX = -10;
			KeyFrame[3].posY = -2.5;
			KeyFrame[3].posZ = -15;
			KeyFrame[3].rotRodIzq = 0.0;
			KeyFrame[3].rotRodDer = 0.0;
			KeyFrame[3].giroMonito = 0.0;
			KeyFrame[3].movBrazoDer = 0.0;
			KeyFrame[3].movBrazoIzq = 0.0;






			if (play == false && (FrameIndex>1))
			{

				posX = KeyFrame[0].posX;
				posY = KeyFrame[0].posY;
				posZ = KeyFrame[0].posZ;

				rotRodIzq = KeyFrame[0].rotRodIzq;
				giroMonito = KeyFrame[0].giroMonito;
				movBrazoDer = KeyFrame[0].movBrazoDer;
				movBrazoIzq = KeyFrame[0].movBrazoIzq;
				rotRodDer = KeyFrame[0].rotRodDer;
				play = true;
				playIndex = 0;
			}
			else
			{
				play = false;
			}

	
		break;

		//case 'g':		//
		//	angulo3 += 2.5;
		//	break;

		//case 'G':		//
		//	angulo3 -= 2.5;

		//	break;
		//case 'f':		//
		//	angulo2 += 2.5;
		//	break;
		//case 'F':
		//	angulo2 -= 2.5;

		//	
		//	break;

		//




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



void menu(int id)
{
	switch (id)
	{
	case 1:
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
		break;


	}
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
