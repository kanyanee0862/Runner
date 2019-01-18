#pragma once
#include <DxLib.h>
#include "Reactangle2D.hpp"
#include "input.hpp"
//ƒvƒŒƒCƒ„‚ÌˆÊ’u
class Player
{
private:
	Reactangle2D Rect;
	float jumpForce;
	float Gravity;
	int Base;
	
public:
	void Init()
	{
		jumpForce = -5.0f;
		Gravity = 0.5f;
		Rect.Reactangle_Init(Position{ 100,300 }, Scale{ 32,32 });
		Base = 132;
	}
	void Update()
	{
		Input().Get().updateKey();
		Rect.pos.y += Gravity;
		if (Input().Get().getKeyFrame(KEY_INPUT_SPACE) >= 1)
		{
			if (Rect.pos.y = Base)
			{
				Rect.pos.y = jumpForce;
			}
			
		}
		if (Rect.pos.y >= Base)
		{
			Gravity = 0.0f;
			Rect.pos.y = Base;
		}
		else
		{
			Gravity = 0.5f;
		}
	}
	void Draw()
	{
		Rect.Render(GetColor(255, 0, 0), true);
	}
	
};