#pragma once
#include "Figure.h"

class trapeze : public Figure {
public:
	trapeze(int, int, int, int, int, COLORREF, COLORREF);
	void draw() const override;
	void hide() const override;
	void replace(int, int) override;
private:
	int height;
	Point second, third, fourth;
};