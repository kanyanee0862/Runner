#pragma once
#include <DxLib.h>
#include "Reactangle2D.hpp"
class Enemy
{
private:
	Reactangle2D Rect;
	
public:
	static int x;
	static int y;
	const int w1 = 32;
	const int h1 = 32;
	const int w2 = 44;
	const int h2 = 40;
	void Init()
	{
		x = 0;
		y = 0;
	}
	void Update()
	{
		for (int i = 0; i < 30; ++i) {
			x = 100 * i + GetRand(30);
		}
		y = 430;
	}
};