/**
* @file Runner.hpp
* @brief “–‚½‚è”»’èŸ—˜@
* @author Kanyanee
* @date 2019/1/21
*/
#pragma once
#include <DxLib.h>
#include "Player.hpp"
#include "Base.hpp"
#include "Rectangle2D.hpp"


bool Box_Collision(Rectangle2D& Rect1,const Rectangle2D& Rect2)
{
	float preY = Rect1.pos.y;
	if (Rect1.pos.x + Rect1.scale.w > Rect2.pos.x &&
		Rect1.pos.y + Rect1.scale.h > Rect2.pos.y &&
		Rect2.pos.x + Rect2.scale.w > Rect1.pos.x &&
		Rect2.pos.y + Rect2.scale.h > Rect1.pos.y)
	{
		Rect1.pos.y = preY;
		return true;
	}
	return false;
}
