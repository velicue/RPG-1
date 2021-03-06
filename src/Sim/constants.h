#ifndef _CONSTANTS_H
#define _CONSTANTS_H

// 窗口的大小
const int WinWidth = 800;
const int WinHeight = 600;

// 中心点的位置
const int Ox = WinWidth / 2;
const int Oy = WinHeight / 2;

// 颜色常量
const unsigned ColRed = 0xFF0000;
const unsigned ColWhite = 0xFF00FF;

// 每一帧计算的次数
const int CalRate = 1000;

// 一秒有60帧，另需除去每一帧计算的次数，这样做会使得模拟中一秒和现实中一秒相同
const double dt = 1.0 / 60 / CalRate;

// 引力系数，随便乱设的值
const double gra = 2000;

// 物体与墙壁的弹性系数，随便乱设的值，需要比引力系数大上一些
const double kfac1 = gra * 10000;

// 极小值
const double eps = 1e-10;

// 光速 : 为了使得空间稳定，位移尽量看起来连续，byw，其实光速的确可能就是做这个事情的
const double veloflight = 10000;

// 按键对物体产生的力的大小
const double PressPower = 15000;

// 地面摩擦系数
const double FrictionFactor = 100;

// 线段的宽度
const double WidthOfLine = 1;

const double DecRatio = 0.999;

const double JumpPower = 500;

const double AirResistanceFactor = 0;

#define sqr(x) ((x) * (x))

#endif