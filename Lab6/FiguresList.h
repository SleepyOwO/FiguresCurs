#pragma once
#include <list>
#include <initializer_list>
#include "Figure.h"

using namespace std;

class figuresList {
public:
	void view();
	static void add_f(initializer_list<Figure*>);
	void delete_list();
private:
	static list<Figure*> list;
};