#include "constants.h"
#include "types.h"
#include "DxLib.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	
	SetWindowText("DxLibSample");						
	SetGraphMode(WinWidth, WinHeight, 32);
	SetWindowSize(WinWidth, WinHeight);

	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );				
		
	int n = 1;
	obj * ist[100];
	ist[0] = new oCircle();
	/*
	oCircle Cir[100];
	for (int i = 0; i < n; i++) {
		Cir[i].r = GetRand(50) + 50;
		Cir[i].position.x = GetRand(WinWidth - 2 * Cir[i].r) + Cir[i].r;
		Cir[i].position.y = GetRand(WinHeight - 2 * Cir[i].r) + Cir[i].r;
		Cir[i].velocity.x = GetRand(100) + 100;
		Cir[i].velocity.y = 0;
		Cir[i].color = GetRand(0xFFFFFF);
	}
	*/
	int ClickLeft = 0, ClickRight = 0, ClickUp = 0;
	int PressLeft = 0, PressRight = 0, PressUp = 0;
	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		// 检测各类按键
		ClickLeft = CheckHitKey(KEY_INPUT_LEFT);
		ClickRight = CheckHitKey(KEY_INPUT_RIGHT);
		ClickUp = (!PressUp) && CheckHitKey(KEY_INPUT_UP); PressUp = CheckHitKey(KEY_INPUT_UP);
		if (ClickUp) ist[0]->velocity.y -= 1000;
		for (int t = 0; t < CalRate; t++) {
			for (int i = 0; i < n; i++) {
				// 计算合力
				vec alpha(0, gra);
				alpha += ist[i]->ElasticForceByFrame();
				//alpha += ist[i]->ResistanceByAir();
				if (ist[i]->StandOnSth()) alpha += vec((ClickRight - ClickLeft) * PressPower, 0);
				//if (ist[i]->velocity.x > eps) alpha += vec(-FrictionFactor, 0);
				//if (ist[i]->velocity.x < -eps) alpha += vec(FrictionFactor, 0);
				// 计算速度
				ist[i]->velocity += alpha * dt;
				if (ist[i]->StandOnSth()) ist[i]->velocity.x *= DecRatio;
				// 计算位移
				ist[i]->position += ist[i]->velocity * dt;
			}
		}
		//cout << gra * (WinHeight - r - y) + vy * vy / 2 + vx * vx / 2 << ax << ' ' << ay << ' ' << vx << ' ' << vy << ' ' << x << ' ' << y << endl;
		for (int i = 0; i < n; i++) ist[i]->Draw();
	}


	// 关闭DxLib
	DxLib_End();
	return 0;
}

