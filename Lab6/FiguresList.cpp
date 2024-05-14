#include "FiguresList.h"

list<Figure*> figuresList::list;

void figuresList::view() {
	if (list.empty()) {
		cout << "\nСписок пуст!";
	}
	while (!list.empty()) {
		list.front()->draw();
		cout << '\n';
		list.pop_front();
	}
}


void figuresList::add_f(initializer_list<Figure*> li) {
	for (auto i : li) {
		list.push_back(i);
	}
}

void figuresList::delete_list() {
	while (!list.empty()) {
		Figure* tmp = list.back();
		list.pop_back();
		delete tmp;
		tmp = nullptr;
	}
	cout << "Список удалён.";
}