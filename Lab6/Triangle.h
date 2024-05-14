#pragma once
#include "Figure.h"

class triangle : public Figure {
public:
	triangle(int, int, int, int, COLORREF, COLORREF);
	void draw() const override;
	void hide() const override;
	void replace(int, int) override;
private:
	Point second, third;
};