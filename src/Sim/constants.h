#ifndef _CONSTANTS_H
#define _CONSTANTS_H

const int WinWidth = 800;
const int WinHeight = 600;
const int Ox = (WinWidth / 2);
const int Oy = (WinHeight / 2);
const unsigned ColRed = 0xFF0000;

// 每一帧计算的次数
const int CalRate = 1000;

// 一秒有60帧，另需除去每一帧计算的次数，这样做会使得模拟中一秒和现实中一秒相同
const double dt = 1.0 / 60 / CalRate;

// 引力系数，随便乱设的值
const double gra = 300;

// 物体与墙壁的弹性系数，随便乱设的值，需要比引力系数大上一些
const double kfac1 = 1000;

// 速度递减系数，随便乱设的值
const double dec_ratio = 1;

// 极小值
const double eps = 1e-10;

// 光速 : 为了使得空间稳定，位移尽量看起来连续，byw，其实光速的确可能就是做这个事情的
const double veloflight = 10000;

#endif