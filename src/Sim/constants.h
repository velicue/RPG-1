#ifndef _CONSTANTS_H
#define _CONSTANTS_H

const int WinWidth = 800;
const int WinHeight = 600;
const int Ox = (WinWidth / 2);
const int Oy = (WinHeight / 2);
const unsigned ColRed = 0xFF0000;

// ÿһ֡����Ĵ���
const int CalRate = 1000;

// һ����60֡�������ȥÿһ֡����Ĵ�������������ʹ��ģ����һ�����ʵ��һ����ͬ
const double dt = 1.0 / 60 / CalRate;

// ����ϵ������������ֵ
const double gra = 3000;

// ������ǽ�ڵĵ���ϵ������������ֵ����Ҫ������ϵ������һЩ
const double kfac1 = gra * 100;

// ��Сֵ
const double eps = 1e-10;

// ���� : Ϊ��ʹ�ÿռ��ȶ���λ�ƾ���������������byw����ʵ���ٵ�ȷ���ܾ�������������
const double veloflight = 10000;

// ������������������Ĵ�С
const double PressPower = 3000;

// ����Ħ��ϵ��
const double FrictionFactor = 100;

const double DecRatio = 0.9999;

const double JumpPower = 1000;

const double AirResistanceFactor = 0;

#define sqr(x) ((x) * (x))

#endif