#include "Triangle.h"

triangle::triangle(int _x, int _y, int _a, int _b, COLORREF _brush, COLORREF _pen) : Figure(_x, _y, _a, _b, _brush, _pen) {
	second.x = first.x; second.y = first.y + _a;
	third.x = first.x + _b; third.y = second.y;
}

void triangle::draw() const {
	std::cout << "\nТреугольник: ";
	Figure::draw();
	std::cout << ", " << second.x << " " << second.y;
	std::cout << ", " << third.x << " " << third.y;
	std::cout << "\nСтороны: " << a_side << ", " << b_side;

	if (first.x <= rt.left || first.y <= rt.top)
		throw border();

	HPEN pen = CreatePen(PS_SOLID, 4, outline);
	HBRUSH brush = CreateSolidBrush(background);

	SelectObject(hdc, pen); SelectObject(hdc, brush);

	POINT points[] = { { first.x, first.y }, { second.x, second.y }, { third.x, third.y } };
	Polygon(hdc, points, 3);

	DeleteObject(pen); DeleteObject(brush);
}

void triangle::hide() const {
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(241, 241, 241));
	HBRUSH brush = CreateSolidBrush(RGB(241, 241, 241));

	SelectObject(hdc, pen); SelectObject(hdc, brush);

	POINT points[] = { { first.x, first.y }, { second.x, second.y }, { third.x, third.y } };
	Polygon(hdc, points, 3);

	DeleteObject(pen); DeleteObject(brush);
}

void triangle::replace(int new_x, int new_y) {
	Figure::replace(new_x, new_y);
	second.x = first.x; second.y = first.y + a_side;
	third.x = first.x + b_side; third.y = second.y;
	this->draw();
	std::cout << "\nТреугольник перемещён";
}