#include "Complex.h"

void complex::draw() const {
	std::cout << "������� ������ ����������\n";
	trian->draw();
	trap->draw();
}

void complex::hide() const {
	trian->hide();
	trap->hide();
	std::cout << "������� ������ ������\n";
}

void complex::replace(int _x, int _y) {
	std::cout << "���������� ����������� ������";
}