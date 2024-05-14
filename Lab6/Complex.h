#pragma once
#include <iostream>
#include "Triangle.h"
#include "Trapeze.h"

class complex : public Figure{
public:
	complex(triangle* _trian, trapeze* _trap) : trian(_trian), trap(_trap) {}
	void draw() const override;
	void hide() const override;
	void replace(int, int) override;
private:
	triangle* trian;
	trapeze* trap;
};