#pragma once
#include <DxLib.h>
#include "Rectangle2D.hpp"//四角形処理　
#include "input.hpp"//キー
#include "Base.hpp"//地面
#include "Rectangle_Collision.hpp"//当たり判定
#include "Enemy.hpp"

//プレイヤの位置
class Player
{
private:
	
	float jumpForce;
	float fallSpeed;
	float Gravity;
	
public:
	Rectangle2D playerRect;
	Base  base;
	Enemy enemy;
	//---------------
	//プレイヤ座標
	int x = 50;
	int y = 300;
	int w = 32;
	int h = 32;
	int colorBlue = 255;
	//-----------------
	void Init()
	{
		jumpForce = -8.0f; //ジャンプ力
		fallSpeed = 1.0f; //空中にいたら、落ちていく値
		playerRect.Rectangle_Init(Position{ x,y }, Scale{ w,h }); //プレイヤの座標を入力
		Gravity = 9.8f / 60 / 60; //重力
		base.Init();	//地面の初期化
	}
	void Update()
	{
		Input().Get().updateKey();
		float checkY = 0.0f;
		//スペースキーを押したら、ジャンプする
		if (Input().Get().getKeyFrame(KEY_INPUT_SPACE) >= 1 && 
			Box_Collision(Rectangle2D{ playerRect }, Rectangle2D{ base.baseRect }))
		{
			fallSpeed = jumpForce;
		}
		//プレイヤの
		playerRect.pos.y += static_cast<int>(fallSpeed);
		Prevent_Stuck(playerRect.pos.y,checkY);
		//地面と当たり判定がtrueなら、落下速度 0
		if (Box_Collision(Rectangle2D{ playerRect }, Rectangle2D{ base.baseRect }))
		{
 			fallSpeed = 0.0f;
		}
		else
		{//空中にいる間、重力で落ちていく
			fallSpeed += Gravity*80;
		}

		
	}
	//--------------------------------------------------------------------------
	//描画する処理
	void Draw()
	{
		
		playerRect.Render(GetColor(255, 0, colorBlue), true);
	}
	//--------------------------------------------------------------------------
	//めり込まない処理
	void Prevent_Stuck(float y,float cy)
	{
		//縦軸に対する移動
		while (cy != 0.0f) {
			float  preY = cy;
			if (cy >= 1.0f) { y += 1.0f;	cy -= 1.0f; }
			else if (cy <= -1.0f) { y -= 1.0f;	cy += 1.0f; }
			else { y += cy;	cy = 0.0f; }
			if (Box_Collision(Rectangle2D{ playerRect }, Rectangle2D{ base.baseRect })) {
				y = preY;		//移動をキャンセル
				break;
			}
		}
	}
};