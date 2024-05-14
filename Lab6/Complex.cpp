#include "Complex.h"

void complex::draw() const {
	std::cout << "Сложная фигура нарисована\n";
	trian->draw();
	trap->draw();
}

void complex::hide() const {
	trian->hide();
	trap->hide();
	std::cout << "Сложная фигура скрыта\n";
}

void complex::replace(int _x, int _y) {
	std::cout << "невозможно переместить фигуру";
}