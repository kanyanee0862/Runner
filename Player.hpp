#pragma once
#include <DxLib.h>
#include "Reactangle2D.hpp"//四角形処理　
#include "input.hpp"//キー
#include "Base.hpp"//地面
#include "Reactangle_Collision.hpp"//当たり判定

//プレイヤの位置
class Player
{
private:
	Reactangle2D Rect;
	float jumpForce;
	float fallSpeed;
	float Gravity;
	
public:
	Detect_Collide col;
	Base  base;
	void Init()
	{
		jumpForce = -8.0f;
		fallSpeed = 0.5f;
		Rect.Reactangle_Init(Position{ 50,300 }, Scale{ 32,32 });
		Gravity = 9.8f / 60 / 60;
		
	}
	void Update()
	{
		Input().Get().updateKey();
		
		if (Input().Get().getKeyFrame(KEY_INPUT_SPACE) >= 1 && col.Check_Square_Collide(Rect.pos.x, Rect.pos.y, Rect.scale.w, Rect.scale.h, base.x, base.y, base.w, base.h))//仮長すぎる
		{
			fallSpeed = jumpForce;
		}
		Rect.pos.y += static_cast<int>(fallSpeed);

		if (col.Check_Square_Collide(Rect.pos.x, Rect.pos.y, Rect.scale.w, Rect.scale.h, base.x, base.y, base.w, base.h))//仮長すぎる
		{
			fallSpeed = 0.0f;
		}
		else
		{
			fallSpeed += Gravity*80;
		}
	}
	void Draw()
	{
		
		Rect.Render(GetColor(255, 0, 0), true);
	}
	
};