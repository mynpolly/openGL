#include "TestWindow.h"

void TestWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(1.0f, 0.75f, 0.3f, 1.0f);

	glPointSize(16.0f);
	glLineWidth(16.0f);

	glMatrixMode(GL_PROJECTION);
	double ratio = double(width()) / double(height());
//	gluOrtho2D(-ratio, ratio, -1.0, 1.0);
	gluPerspective(45.0, ratio, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void TestWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(5.0, 5.0, 3.0, // откуда
	          0.0, 0.0, 1.0, // куда
	          0.0, 0.0, 1.0);// где верх

//	glTranslated(0.3, 0.0, 0.0);  // <-- умножение на матрицу п.переноса
//	glScaled(1.3, 0.25, 1.0);  // <-- умножение на матрицу масштабирования
	glRotated(_angle, 0.0, 0.0, 1.0);

	Texture::enable();
	_tex.use();

	_house.draw();
}

void TestWindow::update()
{
	_angle += 0.05;//скорость
	if (_angle >= 360.0) _angle -= 360.0;
}
