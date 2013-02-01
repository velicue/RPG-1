#include "constants.h"
#include "DxLib.h"

class vec {
public:
	double x, y;
	vec() {}
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

class obj {
public:
	double color;
	vec position, velocity;
	obj() {}
	obj(double x_, double y_, double vx_, double vy_, double color_ = ColRed):position(x_, y_), velocity(vx_, vy_), color(color_) {}
};

class oCircle:public obj {
public:
	double r;
	oCircle() {}
	oCircle(double x_, double y_, double r_, double vx_ = 0, double vy_ = 0):obj(x_, y_, vx_, vy_), r(r_) {}
	vec ElasticForceByFrame() {
		double ax = 0, ay = 0;
		// ÉÏ²àµ¯Á¦
		if (position.y <= r) {
			ay += kfac1 * (r - position.y);
		}
		// ÏÂ²àµ¯Á¦
		if (position.y >= WinHeight - r) {
			ay -= kfac1 * (position.y - WinHeight + r);
		}
		// ×ó²àµ¯Á¦
		if (position.x <= r) {
			ax += kfac1 * (r - position.x);
		}
		// ÓÒ²àµ¯Á¦
		if (position.x >= WinWidth - r) {
			ax -= kfac1 * (position.x - WinWidth + r);
		}
		return vec(ax, ay);
	}
	void Draw() {
		DrawCircle((int) position.x, (int) position.y, r, color);
	}
};