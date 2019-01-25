#pragma once
#include <DxLib.h>
#include <random>
#include "Rectangle2D.hpp"
class Enemy
{
private:
	
	
	
public:
	int x = 0;
	const int y = 418;
	int Blue =0;
	const int w1 = 32;
	const int h1 = 32;
	const int w2 = 44;
	const int h2 = 40;
	const int ENEMY_MAX = 30;
	
	Rectangle2D enemyRect;
	void Init(int Setx)
	{
		x = Setx;
		enemyRect.Rectangle_Init(Position{ x,y }, Scale{ w1,h1 });
	}
	void Update()
	{
		enemyRect.pos.x -=2 ;
	}
	void Render()
	{
		enemyRect.Render(GetColor(0, 255, Blue), true);
	}
	
};