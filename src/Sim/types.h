#include "constants.h"
#include "DxLib.h"
#include <math.h>
#include <vector>
using namespace std;

class vec {
public:
	double x, y;
	vec() { x = y = 0; }
	vec(double x_, double y_):x(x_), y(y_) {}
	vec operator * (double k) {
		return vec(x * k, y * k);
	}
	vec operator *= (double k) {
		x *= k;
		y *= k;
		return vec(x, y);
	}
	vec operator + (vec t) {
		return vec(x + t.x, y + t.y);
	}
	vec operator += (vec t) {
		x += t.x;
		y += t.y;
		return vec(x, y);
	}
};

class oLine {
public:
	int type, color; // 0 - horizontal 1 - vertical
	vec position;
	double length;
	oLine() {}
	oLine(double x, double y, double z, int type_, int color = ColRed):type(type_) {
		// 以左(下)端的点为position
		if (type == 1) {
			position = vec(x, min(y, z));
			length = abs(y - z);
		}	else
		{
			position = vec(min(x, y), z);
			length = abs(x - y);
		}
	}
	void Draw() {
		if (type == 0) DrawLine(position.x, position.y, position.x + length, position.y, color, 1);
	}
};

class obj {
public:
	double color;
	vec position, velocity;
	obj() { color = 0; }
	obj(double x_, double y_, double vx_, double vy_, double color_ = ColRed):position(x_, y_), velocity(vx_, vy_), color(color_) {}
	virtual void Draw() {}
	virtual vec ElasticForceByFrame() { return vec(0, 0); }
	virtual vec ElasticForceByLine(oLine l) { return vec(0, 0); }
	virtual vec ResistanceByAir() { return vec(0, 0); }
	virtual int CloseToGround() { return 0; }
	virtual int StandOnSth() { return 0; }
	virtual int StandOnLine(const oLine & l) { return 0; };
	virtual int StandOnLines(const vector<oLine> & ls) { return 0; };
};

class oCircle:public obj {
public:
	double r;
	oCircle() {
		r = 20;
		position.x = GetRand(WinWidth - 2 * r) + r;
		position.y = GetRand(WinHeight - 2 * r) + r;
		//velocity.x = GetRand(100) + 100;
		velocity.x = 0;
		velocity.y = 0;
		color = GetRand(0xFFFFFF);
	}
	oCircle(double x_, double y_, double r_, double vx_ = 0, double vy_ = 0):obj(x_, y_, vx_, vy_), r(r_) {}
	vec ElasticForceByFrame() {
		double ax = 0, ay = 0;
		// 上侧弹力
		if (position.y <= r) {
			ay += kfac1 * (r - position.y);
		}
		// 下侧弹力
		if (position.y >= WinHeight - r) {
			if (velocity.y > 0) ay -= kfac1 * (position.y - WinHeight + r);
			else ay = 0;
		}
		// 左侧弹力
		if (position.x <= r) {
			ax += kfac1 * (r - position.x);
		}
		// 右侧弹力
		if (position.x >= WinWidth - r) {
			ax -= kfac1 * (position.x - WinWidth + r);
		}
		return vec(ax, ay);
	}
	vec ElasticForceByLine(oLine l) {
		double ax = 0, ay = 0;
		if (l.type == 0) {
			if (position.x >= l.position.x && position.x <= l.position.x + l.length && position.y >= l.position.y - r && position.y <= l.position.y - r + WidthOfLine) {
				if (velocity.y > 0) ay -= kfac1 * (position.y - l.position.y + r);
			}
		}
		return vec(ax, ay);
	}
	void Draw() {
		DrawCircle((int) position.x, (int) position.y, r, color);
	}
	vec ResistanceByAir() { 
		return vec(velocity.x, velocity.y) * (- sqrt(sqr(velocity.x) + sqr(velocity.y)) * AirResistanceFactor); 
	}
	int CloseToGround() {
		return position.y + r > WinHeight - eps;
	}
	int StandOnSth() {
		return position.y + r > WinHeight - eps;
	}
	int StandOnLine(const oLine & l) {
		return position.x >= l.position.x && position.x <= l.position.x + l.length &&position.y >= l.position.y - r && position.y <= l.position.y - r + WidthOfLine;
	}
	int StandOnLines(const vector<oLine> & ls) {
		for (unsigned i = 0; i < ls.size(); i++) if (this->StandOnLine(ls[i])) return true;
		return false;
	}
};