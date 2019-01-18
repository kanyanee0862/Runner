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
class Reactangle2D
{
	
public:
	Position pos;
	Scale    scale;
	void Reactangle_Init(const Position setPos, const Scale setScale)
	{
		pos = setPos;
		scale = setScale;
	}
	void Render(unsigned int color, const bool isFill)
	{
		DrawBox(pos.x, pos.y, scale.w + pos.x, scale.h + pos.y,color,isFill);
	}
};
