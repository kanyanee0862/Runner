/**
* @file Runner.hpp
* @brief ゲーム処理　Runner ゲーム　四角形を使って、ジャンプしながら障害物をよけるゲーム 
* @author Kanyanee
* @date 2019/1/18
* 説：このゲームはゲームの設計やC++の勉強するために作った
*/
#include <DxLib.h>
#include "Player.hpp" //プレイヤのヘーダファイル
#include "Base.hpp" //地面のヘーダファイル
#include "Enemy.hpp" //敵のヘーダ
#include "Rectangle_Collision.hpp"
//-------------------------------------------------------------------
const int MAX_ENEMIES = 30;
int frameCnt = 0;
Player player; 
Base   base;
Enemy  enemy[MAX_ENEMIES];
//--------------------------------------------------------------------------
typedef std::mt19937 MyRND;  // the Mersenne Twister with a popular choice of parameters
uint32_t seed_val;           // populate somehow
MyRND rnd;                   // e.g. keep one global instance (per thread)
//-------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	
	Input().Get().updateKey();
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//ウィンドウモード変更と初期化と裏画面設定

	rnd.seed(seed_val);
	std::uniform_int_distribution<uint32_t> uint_dist10(8, 10); // range [8から10]
	//
	player.Init();//プレイヤの初期化
	//
	for (int i = 0; i < MAX_ENEMIES&&frameCnt <=30; ++i)
	{
		int x = static_cast<int>(640 + uint_dist10(rnd) * 10 * i);
		enemy[i].Init(x);
	}
	
	base.Init(); //地面の初期化
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面変更＆メッセージ処理＆画面消去
		
		//プレイヤの更新
		player.Update(); 
		frameCnt++;
		if (frameCnt >= 30)
		{
			frameCnt = 0;
		}
		//敵の更新
		for (int i = 0; i < MAX_ENEMIES; ++i)
		{
			enemy[i].Update();
			if (Box_Collision(Rectangle2D{ player.playerRect }, Rectangle2D{ enemy[i].enemyRect }))
			{
				enemy[i].Blue = 255;
			}
			else
			{
				enemy[i].Blue = 0;
			}
		}
		//敵の描画
		for (int i = 0; i < MAX_ENEMIES; ++i)
		{
			enemy[i].Render();
		}
		//プレイヤの描画
		player.Draw(); 
		
		//値面の描画
		base.Render(); 
	}
	DxLib_End();
	return 0;
}