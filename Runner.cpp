/**
* @file Runner.hpp
* @brief ゲーム処理　
* @author Kanyanee
* @date 2019/1/18
*/
#include <DxLib.h>
#include "Player.hpp"

Player player;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	int winSize_w = 480;
	int winSize_h = 270;

	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);//ウィンドウモード変更と初期化と裏画面設定
	
	player.Init();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面変更＆メッセージ処理＆画面消去
		player.Update();
		player.Draw();
	}
	DxLib_End();
	return 0;
}