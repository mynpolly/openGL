#ifndef TESTWINDOW_H_
#define TESTWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "Model.h"
#include "Texture.h"

class TestWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 1200;
	static constexpr int DEFAULT_HEIGHT = 600;
protected:
	Model _house {"house.txt"};
	Texture _tex{"house.png"};


	virtual void setup() override;
	virtual void render() override;

	double _angle = 0.0;

	virtual void update() override;

public:
	TestWindow(): Window(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}
	virtual ~TestWindow() = default;

};

#endif /* TESTWINDOW_H_ */
