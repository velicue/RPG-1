/*
 * ����DxLib��ʹ�õ�����
 * AUTH: Nettle
 * �в����Ŀ��Է��ʼ�����
 * Email: nettle256@gmail.com
 */

/*
 * �������Ե��޸�
 * 1. C/C++ -> ���� -> ���Ӱ���Ŀ¼: ���DxLibVCTest�ļ���
 * 2. C/C++ -> �������� -> ���п�: �޸�Ϊ���߳�(/MT)
 * 3. ������ -> ���� -> ���ӿ�Ŀ¼: ���DxLibVCTest�ļ���
 */

#include "DxLib.h"
#include <stdio.h>

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	// ���ô��ڱ���
	SetWindowText("DxLibSample") ;													
															
	// ���û�ͼ�����С��ɫ��
	// 640px * 480px 32ɫ
	// (0,0) -------> (640,0)
	//   |
	//   |
	//   |
	//   ��
	// (0,480)	
	SetGraphMode(640, 480, 32);

	// ���ô��ڴ�С
	// 640px * 480px
	SetWindowSize(640, 480);															
	
	// Windows���ڳ�ʼ��
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );				

	// ��ȡͼƬ-���·��
	int background = LoadGraph("background.png");
	int actor = LoadGraph("actor.png");

	// �����ƶ�����Ĳ����������� == �����ƶ��Ĳ��� ==
	int moveY = 0, dr = 0;

	// ScreenFlip ������Ļˢ���ٶȸı�ÿ֡��ʱ��
	// ClearDraScreen �����ǰһ�ε���Ļ����
	// CheckHitKey �жϰ����Ƿ���
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		
		// ��ȫ����ͼƬ
		// ��(0,0)������ͼƬbackground��͸��ΪTRUE
		// ��TRUE��ΪFALSE�ᵼ��ԭͼƬ͸���Ĳ��ֱ�Ϊ��ɫ
		DrawGraph(0, 0, background, TRUE);
		
		// ��ȫ����
		DrawGraph(0, 0, actor, TRUE);
		
		// ����ͼƬ�Ĳ���
		// ��(0,300)������actor.pngͼƬ��һ����
		// ����Ϊ���Ͻ�����(128,32)�������32px
		DrawRectGraph(0, 300, 128, 32, 32, 32, actor, TRUE, FALSE);
				
		// ����Ϊ���Ͻ�����(80,48)�������32px
		DrawRectGraph(50, 300, 80, 48, 32, 32, actor, TRUE, FALSE);
		
		int x, y, value;
		
		// ��ȡ������ꡣ(�Դ��ڶ���)
		GetMousePoint(&x, &y);
		
		// ��ȡ��갴����Ϣ
		value = GetMouseInput();

		char info[ 200 ];
		sprintf(info, "Mouse Point = (%d, %d); Input = %d", x, y, value);

		/// == ����info��Ϣ��ò�Ʋ��ܻ��С� ==
		// ��(0, 400)�����info��������ɫΪ0x0
		DrawString(0, 400, info, 0x0, 0);

		/// == �����ƶ���ͼƬ ==
		// ����moveY�ı��ƶ�����
		if (moveY == 256 - 32) dr = -1;
		if (moveY == 0) dr = 1;
		// �ı�Y����
		moveY += 2 * dr;
		// ����ͼƬ
		DrawRectGraph(256, moveY, 128, 32, 32, 32, actor, TRUE, FALSE);
	}


	// �ر�DxLib
	DxLib_End();
	return 0;
}

