#pragma once
#include <DxLib.h>
#include "Rectangle2D.hpp"

class Base
{
private:
	 
	 
public:
	Rectangle2D baseRect;
	const int x = 0;
	const int y = 450;
	const int w = 640;
	const int h = 30;
	void Init()
	{
		baseRect.Rectangle_Init(Position{ x,y }, Scale{ w,h });
	}
	//ínñ ÇêLÇ—ÇÈ
	void Render()
	{
		baseRect.Render(GetColor(229, 152, 102), true);
	}
};
