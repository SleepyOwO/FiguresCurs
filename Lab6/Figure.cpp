#include "Figure.h"

Figure::Figure(int _x, int _y, int _a, int _b, COLORREF _back, COLORREF _out) : first{ _x, _y }, a_side(_a), b_side(_b), background(_back), outline(_out) {
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
};

Figure::~Figure() {
	ReleaseDC(hwnd, hdc);
}

void Figure::draw() const {
	std::cout << "\nКоординаты: " << first.x << " " << first.y;
}

void Figure::hide() const {
	std::cout << "Фигура скрыта";
}

void Figure::replace(int new_x, int new_y) {
	this->hide();
	first.x = new_x;
	first.y = new_y;
}
