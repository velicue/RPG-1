/*
 * 关于DxLib简单使用的例子
 * AUTH: Nettle
 * 有不懂的可以发邮件问我
 * Email: nettle256@gmail.com
 */

/*
 * 工程属性的修改
 * 1. C/C++ -> 常规 -> 附加包含目录: 添加DxLibVCTest文件夹
 * 2. C/C++ -> 代码生成 -> 运行库: 修改为多线程(/MT)
 * 3. 链接器 -> 常规 -> 附加库目录: 添加DxLibVCTest文件夹
 */

#include "DxLib.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	// 设置窗口标题
	SetWindowText("DxLibSample") ;													
															
	// 设置绘图区域大小，色彩
	// 640px * 480px 32色
	// (0,0) -------> (640,0)
	//   |
	//   |
	//   |
	//   ∨
	// (0,480)	
	SetGraphMode(640, 480, 32);

	// 设置窗口大小
	// 640px * 480px
	SetWindowSize(640, 480);															
	
	// Windows窗口初始化
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );				

	// 读取图片-相对路径
	int background = LoadGraph("background.png");
	int actor = LoadGraph("actor.png");

	// 绘制移动物体的参数，见下面 == 绘制移动的部分 ==
	int moveY = 0, dr = 0;

	// ScreenFlip 根据屏幕刷新速度改变每帧的时间
	// ClearDraScreen 清楚掉前一次的屏幕内容
	// CheckHitKey 判断按键是否按下
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		
		// 完全绘制图片
		// 在(0,0)处绘制图片background，透明为TRUE
		// 将TRUE改为FALSE会导致原图片透明的部分变为白色
		DrawGraph(0, 0, background, TRUE);
		
		// 完全绘制
		DrawGraph(0, 0, actor, TRUE);
		
		// 绘制图片的部分
		// 在(0,300)处绘制actor.png图片的一部分
		// 区域为左上角坐标(128,32)，长宽各32px
		DrawRectGraph(0, 300, 128, 32, 32, 32, actor, TRUE, FALSE);
				
		// 区域为左上角坐标(80,48)，长宽各32px
		DrawRectGraph(50, 300, 80, 48, 32, 32, actor, TRUE, FALSE);
		
		int x, y, value;
		
		// 获取鼠标坐标。(对窗口而言)
		GetMousePoint(&x, &y);
		
		// 获取鼠标按键信息
		value = GetMouseInput();

		char info[ 200 ];
		sprintf(info, "Mouse Point = (%d, %d); Input = %d", x, y, value);

		/// == 绘制info信息，貌似不能换行。 ==
		// 在(0, 400)出输出info，字体颜色为0x0
		DrawString(0, 400, info, 0x0, 0);

		/// == 绘制移动的图片 ==
		// 根据moveY改变移动方向
		if (moveY == 256 - 32) dr = -1;
		if (moveY == 0) dr = 1;
		// 改变Y坐标
		moveY += 2 * dr;
		// 绘制图片
		DrawRectGraph(256, moveY, 128, 32, 32, 32, actor, TRUE, FALSE);
	}


	// 关闭DxLib
	DxLib_End();
	return 0;
}

