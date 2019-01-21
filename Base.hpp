#pragma once
#include <DxLib.h>
#include "Reactangle2D.hpp"

class Base
{
private:
	 Reactangle2D Rect;
	 
public:
	const int x = 0;
	const int y = 450;
	const int w = 640;
	const int h = 30;
	void Init()
	{
		Rect.Reactangle_Init(Position{ x,y }, Scale{ w,h });
	}
	//ínñ ÇêLÇ—ÇÈ
	void Render()
	{
		Rect.Render(GetColor(229, 152, 102), true);
	}
};
