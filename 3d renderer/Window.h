#pragma once
#include "typedefs.h"
class Window
{
public:
	Window(string title,
		int width,
		int height,
		int x,
		int y);
		
	//~Window();

private:
	string title;
	int width;
	int height;
	int x;
	int y;

public:
	void reShapeWindow(int width, int height);
	void createWindow();

};

