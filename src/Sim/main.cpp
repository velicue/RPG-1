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
		
	int n = 100;
	oCircle Cir[100];
	for (int i = 0; i < n; i++) {
		Cir[i].r = GetRand(50) + 50;
		Cir[i].position.x = GetRand(WinWidth - 2 * Cir[i].r) + Cir[i].r;
		Cir[i].position.y = GetRand(WinHeight - 2 * Cir[i].r) + Cir[i].r;
		Cir[i].velocity.x = GetRand(100) + 100;
		Cir[i].velocity.y = 0;
		Cir[i].color = GetRand(0xFFFFFF);
	}
	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		for (int t = 0; t < CalRate; t++) {
			for (int i = 0; i < n; i++) {
				// 计算合力
				vec alpha(0, gra);
				alpha += Cir[i].ElasticForceByFrame();
				// 计算速度
				Cir[i].velocity += alpha * dt;
				// 速度会以固定比例递减
				Cir[i].velocity *= dec_ratio;
				// 计算位移
				Cir[i].position += Cir[i].velocity * dt;
			}
		}
		//cout << gra * (WinHeight - r - y) + vy * vy / 2 + vx * vx / 2 << ax << ' ' << ay << ' ' << vx << ' ' << vy << ' ' << x << ' ' << y << endl;
		for (int i = 0; i < n; i++) Cir[i].Draw();
	}


	// 关闭DxLib
	DxLib_End();
	return 0;
}

