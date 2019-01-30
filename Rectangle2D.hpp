/**
* @file Runner.hpp
* @brief éläpå`èàóù
* @author Kanyanee
* @date 2019/1/21
*/
#pragma once
#include <DxLib.h>
struct Position
{
	int x = 0;
	int y = 0;
};
struct Scale
{
	int w = 0;
	int h = 0;
};
class Rectangle2D
{
	
public:
	Position pos;
	Scale    scale;
	void Rectangle_Init(const Position setPos, const Scale setScale)
	{
		pos = setPos;
		scale = setScale;
	}
	void Render(unsigned int color, const bool isFill)
	{
		DrawBox(pos.x, pos.y, scale.w + pos.x, scale.h + pos.y,color,isFill);
	}
};
