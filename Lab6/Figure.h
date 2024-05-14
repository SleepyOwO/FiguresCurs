#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>
#include <windowsx.h>

const int NotUsed = system("color F0");

struct Point {
	int x, y;
};

class Figure{
public:
	Figure() {};
	Figure(int, int, int, int, COLORREF, COLORREF);
	virtual void draw() const;
	virtual void hide() const;
	virtual void replace(int, int);
	class border {};
	~Figure();
protected:
	Point first;
	int a_side, b_side;
	COLORREF background, outline;
	HWND hwnd;
	HDC hdc;
	RECT rt;
};