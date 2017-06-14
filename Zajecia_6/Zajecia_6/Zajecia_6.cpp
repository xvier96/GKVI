//Robert Kastelik
//n=7
//cube
#include "stdafx.h"
#include <GL/glut.h>
#include <cstdlib>
#include "materials.h"


// stałe do obsługi menu podręcznego

enum
{
	BRASS,                // mosiądz
	BRONZE,               // brąz
	POLISHED_BRONZE,      // polerowany brąz
	CHROME,               // chrom
	COPPER,               // miedź
	POLISHED_COPPER,      // polerowana miedź
	GOLD,                 // złoto
	POLISHED_GOLD,        // polerowane złoto
	PEWTER,               // grafit (cyna z ołowiem)
	SILVER,               // srebro
	POLISHED_SILVER,      // polerowane srebro
	EMERALD,              // szmaragd
	JADE,                 // jadeit
	OBSIDIAN,             // obsydian
	PEARL,                // perła
	RUBY,                 // rubin
	TURQUOISE,            // turkus
	BLACK_PLASTIC,        // czarny plastik
	BLACK_RUBBER,         // czarna guma


	SOLID,
	WIRE,

	FULL_WINDOW,       // aspekt obrazu - całe okno
	ASPECT_1_1,        // aspekt obrazu 1:1
	EXIT               // wyjście
};

// aspekt obrazu

int _type = WIRE;

int aspect = FULL_WINDOW;

// rozmiary bryły obcinania


const GLdouble left = -10.0;
const GLdouble right = 10.0;
const GLdouble bottom = -10.0;
const GLdouble top = 10.0;
const GLdouble near_ = 50.0;
const GLdouble far_ = 70.0;

// współczynnik skalowania

GLfloat scale = 1.0;

// kąty obrotu

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;

// przesunięcie

GLfloat translatex = 0.0;
GLfloat translatey = 0.0;

// wskaŸnik naciśnięcia lewego przycisku myszki

int button_state = GLUT_UP;

// poło¿enie kursora myszki

int button_x, button_y;

// funkcja rysująca blok 3x3

// funkcja rysująca blok 2x2

void Cube2x2()
{
	glTranslatef(-1.0, 0.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(0.0, 1.0, 0.0);
}

// funkcja rysująca blok 3x3

void Cube3x3()
{
	glTranslatef(-2.0, 0.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireOctahedron();
}

// funkcja rysująca blok 4x4

void Cube4x4()
{
	glTranslatef(-2.0, 0.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, -2.0, 0.0);
	Cube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	Cube2x2();
	glTranslatef(0.0, 2.0, 0.0);
}

void Cube5x5()
{
	glTranslatef(-2.0, 0.0, 0.0);
	Cube3x3();
	glTranslatef(2.0, -3.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(-1.0, 2.0, 0.0);
	Cube2x2();
	glTranslatef(0.0, -3.0, 0.0);
}


// funkcja rysująca piramidę z sześcianów

void WirePyramid()
{

	// szósty poziom 1x1
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glutWireOctahedron();
	glPopMatrix();

	// piąty poziom 2x2
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.0);

	Cube2x2();

	glPopMatrix();

	// czwarty poziom 3x3
	glPushMatrix();
	glTranslatef(0.0, 0.0, -2.0);

	Cube3x3();

	glPopMatrix();

	//4
	glPushMatrix();
	glTranslatef(0.0, 0.0, -3.0);

	Cube4x4();

	glPopMatrix();

	//5
	glPushMatrix();
	glTranslatef(0.0, 0.0, -4.0);

	Cube5x5();

	glPopMatrix();

	//6

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);

	glTranslatef(-3.0, 0.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	Cube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	Cube3x3();

	glPopMatrix();

	//7
	glPushMatrix();
	glTranslatef(0.0, 0.0, -6.0);

	glTranslatef(-1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutWireOctahedron();

	glTranslatef(1.0, 2.0, 0.0);
	Cube2x2();
	glTranslatef(-2.0, 2.0, 0.0);
	Cube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	Cube2x2();

	glTranslatef(2.0, -4.0, 0.0);
	Cube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, -2.0, 0.0);
	Cube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	Cube2x2();

	glTranslatef(2.0, 3.0, 0.0);
	Cube3x3();
	glTranslatef(-8.0, 0.0, 0.0);
	Cube3x3();

	glPopMatrix();

	//8
	glPushMatrix();
	glTranslatef(0.0, 0.0, -7.0);

	glTranslatef(-4.0, 0.0, 0.0);
	Cube4x4();
	glTranslatef(4.0, 4.0, 0.0);
	Cube4x4();
	glTranslatef(4.0, -4.0, 0.0);
	Cube4x4();
	glTranslatef(-4.0, -4.0, 0.0);
	Cube4x4();

	glPopMatrix();

	//9x9
	glPushMatrix();
	glTranslatef(0.0, 0.0, -8.0);

	Cube3x3();
	glTranslatef(-6.0, 0.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	Cube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	Cube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	Cube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	Cube3x3();
	glTranslatef(-3.0, 3.0, 0.0);
	Cube3x3();

	glPopMatrix();

	//10
	glPushMatrix();
	glTranslatef(0.0, 0.0, -9.0);

	glTranslatef(-5.0, 0.0, 0.0);
	Cube5x5();
	glTranslatef(5.0, 5.0, 0.0);
	Cube5x5();
	glTranslatef(5.0, -5.0, 0.0);
	Cube5x5();
	glTranslatef(-5.0, -5.0, 0.0);
	Cube5x5();

	glPopMatrix();
}


//solid piramid

void SolidCube2x2()
{
	glTranslatef(-1.0, 0.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(0.0, 1.0, 0.0);
}

// funkcja rysująca blok 3x3

void SolidCube3x3()
{
	glTranslatef(-2.0, 0.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutSolidOctahedron();
}

// funkcja rysująca blok 4x4

void SolidCube4x4()
{
	glTranslatef(-2.0, 0.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, -2.0, 0.0);
	SolidCube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	SolidCube2x2();
	glTranslatef(0.0, 2.0, 0.0);
}

void SolidCube5x5()
{
	glTranslatef(-2.0, 0.0, 0.0);
	SolidCube3x3();
	glTranslatef(2.0, -3.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, -1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(-1.0, 2.0, 0.0);
	SolidCube2x2();
	glTranslatef(0.0, -3.0, 0.0);
}


// funkcja rysująca piramidę z sześcianów

void SolidPyramid()
{

	// szósty poziom 1x1
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidOctahedron();
	glPopMatrix();

	// piąty poziom 2x2
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.0);

	SolidCube2x2();

	glPopMatrix();

	// czwarty poziom 3x3
	glPushMatrix();
	glTranslatef(0.0, 0.0, -2.0);

	SolidCube3x3();

	glPopMatrix();

	//4
	glPushMatrix();
	glTranslatef(0.0, 0.0, -3.0);

	SolidCube4x4();

	glPopMatrix();

	//5
	glPushMatrix();
	glTranslatef(0.0, 0.0, -4.0);

	SolidCube5x5();

	glPopMatrix();

	//6

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);

	glTranslatef(-3.0, 0.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	SolidCube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	SolidCube3x3();

	glPopMatrix();

	//7
	glPushMatrix();
	glTranslatef(0.0, 0.0, -6.0);

	glTranslatef(-1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, 1.0, 0.0);
	glutSolidOctahedron();
	glTranslatef(1.0, -1.0, 0.0);
	glutSolidOctahedron();

	glTranslatef(1.0, 2.0, 0.0);
	SolidCube2x2();
	glTranslatef(-2.0, 2.0, 0.0);
	SolidCube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	SolidCube2x2();

	glTranslatef(2.0, -4.0, 0.0);
	SolidCube2x2();
	glTranslatef(-2.0, -2.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, -2.0, 0.0);
	SolidCube2x2();
	glTranslatef(2.0, 2.0, 0.0);
	SolidCube2x2();

	glTranslatef(2.0, 3.0, 0.0);
	SolidCube3x3();
	glTranslatef(-8.0, 0.0, 0.0);
	SolidCube3x3();

	glPopMatrix();

	//8
	glPushMatrix();
	glTranslatef(0.0, 0.0, -7.0);

	glTranslatef(-4.0, 0.0, 0.0);
	SolidCube4x4();
	glTranslatef(4.0, 4.0, 0.0);
	SolidCube4x4();
	glTranslatef(4.0, -4.0, 0.0);
	SolidCube4x4();
	glTranslatef(-4.0, -4.0, 0.0);
	SolidCube4x4();

	glPopMatrix();

	//9x9
	glPushMatrix();
	glTranslatef(0.0, 0.0, -8.0);

	SolidCube3x3();
	glTranslatef(-6.0, 0.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, 3.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	SolidCube3x3();
	glTranslatef(3.0, -3.0, 0.0);
	SolidCube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	SolidCube3x3();
	glTranslatef(-3.0, -3.0, 0.0);
	SolidCube3x3();
	glTranslatef(-3.0, 3.0, 0.0);
	SolidCube3x3();

	glPopMatrix();

	//10
	glPushMatrix();
	glTranslatef(0.0, 0.0, -9.0);

	glTranslatef(-5.0, 0.0, 0.0);
	SolidCube5x5();
	glTranslatef(5.0, 5.0, 0.0);
	SolidCube5x5();
	glTranslatef(5.0, -5.0, 0.0);
	SolidCube5x5();
	glTranslatef(-5.0, -5.0, 0.0);
	SolidCube5x5();

	glPopMatrix();
}



GLfloat light_position[4] =
{
	0.0,0.0,100.0,0.0
};


// funkcja generująca scenę 3D

void Display()
{
	// kolor tła - zawartość bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru
	glClear(GL_COLOR_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesunięcie układu współrzędnych obiektu do środka bryły odcinania
	glTranslatef(0, 0, -(near_ + far_) / 2);

	// przesunięcie obiektu - ruch myszką
	glTranslatef(translatex, translatey, 0.0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scale, scale, scale);

	// obroty obiektu - klawisze kursora
	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);


	/////////////////////////////////////////////////////////////////////////////

	glEnable(GL_LIGHTING);

	// włączenie światła GL_LIGHT0 z parametrami domyślnymi
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	////////////////////////////////////////////////////////////////////////////////////
	// kolor krawędzi obiektu
	glColor3f(1.0, 1.0, 1.0);

	// rysowanie piramidy
	switch (_type)
	{
	case WIRE:
		WirePyramid();
		break;
	case SOLID:

		SolidPyramid();
		break;
	default:
		break;
	}

	// skierowanie poleceń do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

// zmiana wielkości okna

void Reshape(int width, int height)
{
	// obszar renderingu - całe okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bryły obcinania
	if (aspect == ASPECT_1_1)
	{
		// wysokość okna większa od wysokości okna
		if (width < height && width > 0)
			glFrustum(left, right, bottom*height / width, top*height / width, near_, far_);
		else

			// szerokość okna większa lub równa wysokości okna
			if (width >= height && height > 0)
				glFrustum(left*width / height, right*width / height, bottom, top, near_, far_);
	}
	else
		glFrustum(left, right, bottom, top, near_, far_);

	// generowanie sceny 3D
	Display();
}

// obsługa klawiatury

void Keyboard(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scale += 0.1;
	else

		// klawisz -
		if (key == '-' && scale > 0.1)
			scale -= 0.1;

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotatey -= 1;
		break;

		// kursor w górę
	case GLUT_KEY_UP:
		rotatex -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotatey += 1;
		break;

		// kursor w dół
	case GLUT_KEY_DOWN:
		rotatex += 1;
		break;
	}

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa przycisków myszki

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiętanie stanu lewego przycisku myszki
		button_state = state;

		// zapamiętanie poło¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

// obsługa ruchu kursora myszki

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		translatex += 1.1 *(right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
		button_x = x;
		translatey += 1.1 *(top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
		button_y = y;
		glutPostRedisplay();
	}
}

// obsługa menu podręcznego

void Menu(int value)
{
	switch (value)
	{

		// materiał - mosiądz
	case BRASS:
		glMaterialfv(GL_FRONT, GL_AMBIENT, BrassAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, BrassDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, BrassSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, BrassShininess);
		Display();
		break;

		// materiał - brąz
	case BRONZE:
		glMaterialfv(GL_FRONT, GL_AMBIENT, BronzeAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, BronzeDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, BronzeSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, BronzeShininess);
		Display();
		break;

		// materiał - polerowany brąz
	case POLISHED_BRONZE:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PolishedBronzeAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PolishedBronzeDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PolishedBronzeSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PolishedBronzeShininess);
		Display();
		break;

		// materiał - chrom
	case CHROME:
		glMaterialfv(GL_FRONT, GL_AMBIENT, ChromeAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, ChromeDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ChromeSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, ChromeShininess);
		Display();
		break;

		// materiał - miedź
	case COPPER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, CopperAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, CopperDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, CopperSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, CopperShininess);
		Display();
		break;

		// materiał - polerowana miedź
	case POLISHED_COPPER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PolishedCopperAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PolishedCopperDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PolishedCopperSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PolishedCopperShininess);
		Display();
		break;

		// materiał - złoto
	case GOLD:
		glMaterialfv(GL_FRONT, GL_AMBIENT, GoldAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, GoldDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, GoldSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, GoldShininess);
		Display();
		break;

		// materiał - polerowane złoto
	case POLISHED_GOLD:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PolishedGoldAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PolishedGoldDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PolishedGoldSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PolishedGoldShininess);
		Display();
		break;

		// materiał - grafit (cyna z ołowiem)
	case PEWTER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PewterAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PewterDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PewterSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PewterShininess);
		Display();
		break;

		// materiał - srebro
	case SILVER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, SilverAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SilverDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, SilverSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, SilverShininess);
		Display();
		break;

		// materiał - polerowane srebro
	case POLISHED_SILVER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PolishedSilverAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PolishedSilverDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PolishedSilverSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PolishedSilverShininess);
		Display();
		break;

		// materiał - szmaragd
	case EMERALD:
		glMaterialfv(GL_FRONT, GL_AMBIENT, EmeraldAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, EmeraldDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, EmeraldSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, EmeraldShininess);
		Display();
		break;

		// materiał - jadeit
	case JADE:
		glMaterialfv(GL_FRONT, GL_AMBIENT, JadeAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, JadeDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, JadeSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, JadeShininess);
		Display();
		break;

		// materiał - obsydian
	case OBSIDIAN:
		glMaterialfv(GL_FRONT, GL_AMBIENT, ObsidianAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, ObsidianDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ObsidianSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, ObsidianShininess);
		Display();
		break;

		// materiał - perła
	case PEARL:
		glMaterialfv(GL_FRONT, GL_AMBIENT, PearlAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, PearlDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, PearlSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, PearlShininess);
		Display();
		break;

		// metariał - rubin
	case RUBY:
		glMaterialfv(GL_FRONT, GL_AMBIENT, RubyAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, RubyDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, RubySpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, RubyShininess);
		Display();
		break;

		// materiał - turkus
	case TURQUOISE:
		glMaterialfv(GL_FRONT, GL_AMBIENT, TurquoiseAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, TurquoiseDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, TurquoiseSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, TurquoiseShininess);
		Display();
		break;

		// materiał - czarny plastik
	case BLACK_PLASTIC:
		glMaterialfv(GL_FRONT, GL_AMBIENT, BlackPlasticAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, BlackPlasticDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, BlackPlasticSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, BlackPlasticShininess);
		Display();
		break;

		// materiał - czarna guma
	case BLACK_RUBBER:
		glMaterialfv(GL_FRONT, GL_AMBIENT, BlackRubberAmbient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, BlackRubberDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, BlackRubberSpecular);
		glMaterialf(GL_FRONT, GL_SHININESS, BlackRubberShininess);
		Display();
		break;

	case WIRE:
		_type = WIRE;
		Display();
		glutDisplayFunc(Display);
		break;
	case SOLID:
		_type = SOLID;
		Display();
		glutDisplayFunc(Display);
		break;
		// obszar renderingu - całe okno
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjście
	case EXIT:
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// rozmiary głównego okna programu
	glutInitWindowSize(400, 400);

	// utworzenie głównego okna programu
	glutCreateWindow("Stos modelowania");

	// dołączenie funkcji generującej scenę 3D
	glutDisplayFunc(Display);

	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);

	// dołączenie funkcji obsługi klawiatury
	glutKeyboardFunc(Keyboard);

	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys);

	// obsługa przycisków myszki
	glutMouseFunc(MouseButton);

	// obsługa ruchu kursora myszki
	glutMotionFunc(MouseMotion);



	int MenuType = glutCreateMenu(Menu);

	glutAddMenuEntry("Wire", WIRE);
	glutAddMenuEntry("Solid", SOLID);

	int MenuMaterial = glutCreateMenu(Menu);

	glutAddMenuEntry("Mosiadz", BRASS);
	glutAddMenuEntry("Braz", BRONZE);
	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedz", COPPER);
	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
	glutAddMenuEntry("Zloto", GOLD);
	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z olowiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Perla", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);

	// utworzenie podmenu - aspekt obrazu
	int MenuAspect = glutCreateMenu(Menu);
#ifdef WIN32

	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
#else

	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu główne
	glutCreateMenu(Menu);
	glutAddSubMenu("Typ", MenuType);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
	glutAddSubMenu("Material", MenuMaterial);

#ifdef WIN32

	glutAddMenuEntry("Wyjście", EXIT);
#else

	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	// określenie przycisku myszki obsługującego menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// wprowadzenie programu do obsługi pętli komunikatów
	glutMainLoop();
	return 0;
}