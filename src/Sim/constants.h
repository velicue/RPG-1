#ifndef _CONSTANTS_H
#define _CONSTANTS_H

// ���ڵĴ�С
const int WinWidth = 800;
const int WinHeight = 600;

// ���ĵ��λ��
const int Ox = WinWidth / 2;
const int Oy = WinHeight / 2;

// ��ɫ����
const unsigned ColRed = 0xFF0000;
const unsigned ColWhite = 0xFF00FF;

// ÿһ֡����Ĵ���
const int CalRate = 1000;

// һ����60֡�������ȥÿһ֡����Ĵ�������������ʹ��ģ����һ�����ʵ��һ����ͬ
const double dt = 1.0 / 60 / CalRate;

// ����ϵ������������ֵ
const double gra = 2000;

// ������ǽ�ڵĵ���ϵ������������ֵ����Ҫ������ϵ������һЩ
const double kfac1 = gra * 10000;

// ��Сֵ
const double eps = 1e-10;

// ���� : Ϊ��ʹ�ÿռ��ȶ���λ�ƾ���������������byw����ʵ���ٵ�ȷ���ܾ�������������
const double veloflight = 10000;

// ������������������Ĵ�С
const double PressPower = 15000;

// ����Ħ��ϵ��
const double FrictionFactor = 100;

// �߶εĿ��
const double WidthOfLine = 1;

const double DecRatio = 0.999;

const double JumpPower = 500;

const double AirResistanceFactor = 0;

#define sqr(x) ((x) * (x))

#endif