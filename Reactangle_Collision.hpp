#pragma once
#include <DxLib.h>
#include "Player.hpp"
#include "Base.hpp"
struct Square
{
	int x, y;
	int h, w;
	
	
};
class Detect_Collide
{
public:
	Square square1;
	Square square2;
	bool Check_Square_Collide(int x1, int y1,int w1,int h1,int x2,int y2,int w2,int h2)
	{
		square1 = {x1,y1,h1,w1};
		square2 = {x2,y2,h2,w2};
		int Right1 = x1 + w1;
		int Bottom1 = y1 + h1;
		int Right2 = x2 + w2;
		int Bottom2 = y2 + h2;
		if (Right1 >= square2.x)
		{
			Right1 = square2.x;
		}
		if (Bottom1 >= square2.y)
		{
			Bottom1 = square2.y;
			return true;
		}
		
		return false;
	}
	
};