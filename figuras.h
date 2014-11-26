//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "include/Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;


	void arquiPrincipal(GLuint frente, GLuint atras, GLuint lizq, GLuint lder, GLuint arriba);
	void arquiEdificioL(GLuint frente1, GLuint frenteder, GLuint frente2, GLuint atras, GLuint arriba);
	void arquiMuca(GLuint frente, GLuint atras, GLuint lizq, GLuint lder, GLuint arriba);
	void arquiCuartoArriba(GLuint frente, GLuint atras, GLuint lizq, GLuint lder, GLuint arriba);
	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);
	void prisma(float altura, float largo, float profundidad, GLuint text, GLuint XREP, GLuint YREP);							//Funcíon creacion movimiento
	//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void renderSphere( float cx, float cy, float cz, float r, int p, GLuint text );
	

	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

	void tecla (float altura, float largo, float profundidad, GLuint text);

};
