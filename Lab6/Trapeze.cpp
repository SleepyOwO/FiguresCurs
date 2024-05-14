#include "Trapeze.h"

trapeze::trapeze(int _x, int _y, int _a, int _b, int _h, COLORREF _brush, COLORREF _pen) : Figure(_x, _y, _a, _b, _brush, _pen), height(_h) {
	second.x = first.x; second.y = first.y + _h;
	third.x = first.x + _b; third.y = second.y;
	fourth.x = first.x + _a; fourth.y = first.y;
};

void trapeze::draw() const {
	std::cout << "\nТрапеция: ";
	Figure::draw();
	std::cout << ", " << second.x << " " << second.y;
	std::cout << ", " << third.x << " " << third.y;
	std::cout << ", " << fourth.x << " " << fourth.y;
	std::cout << "\nОснования: " << a_side << ", " << b_side << "\nВысота: " << height << '\n';

	if (first.x <= rt.left || first.y <= rt.top)
		throw border();

	HPEN pen = CreatePen(PS_SOLID, 4, outline);
	HBRUSH brush = CreateSolidBrush(background);

	SelectObject(hdc, pen); SelectObject(hdc, brush);

	POINT points[] = { { first.x, first.y }, { second.x, second.y }, { third.x, third.y }, { fourth.x, fourth.y } };
	Polygon(hdc, points, 4);

	DeleteObject(pen); DeleteObject(brush);
}

void trapeze::hide() const {
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(241, 241, 241));
	HBRUSH brush = CreateSolidBrush(RGB(241, 241, 241));

	SelectObject(hdc, pen); SelectObject(hdc, brush);

	POINT points[] = { { first.x, first.y }, { second.x, second.y }, { third.x, third.y }, { fourth.x, fourth.y } };
	Polygon(hdc, points, 4);

	DeleteObject(pen); DeleteObject(brush);
}

void trapeze::replace(int new_x, int new_y) {
	Figure::replace(new_x, new_y);
	second.x = first.x; second.y = first.y + height;
	third.x = first.x + b_side; third.y = second.y;
	fourth.x = first.x + a_side; fourth.y = first.y;
	this->draw();
	std::cout << "\nТрапеция перемещена";
}