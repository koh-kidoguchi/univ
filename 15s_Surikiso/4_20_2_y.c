#include <stdio.h>

double lmd = 5;

double f_x(double c1, double c2, double x, double y, double t) {
	return c1 * (1 - x) * x - c2 * x * y;
}

double f_y(double c1, double c2, double x, double y, double t) {
	return c1 * (1 - y) * y - c2 * x * y;
}

int main(void) {
	double dlt = 0.01;
	double x = 0.6;
	double y = 0.4;
	double t = 0;
	double k1, k2, k3, k4;

	double a = 1;
	double b = 2;
	double c = 1;
	double d = 3;

	int i;
	
	for (i=0; i<100; i++) {
		printf("%f %f\n", t, y);
		k1 = f_y(c, d, x, y, t);
		k2 = f_y(c, d, x + (dlt / 2) * k1, y + (dlt / 2) * k1, t + dlt / 2);
		k3 = f_y(c, d, x + (dlt / 2) * k2, y + (dlt / 2) * k2, t + dlt / 2);
		k4 = f_y(c, d, x + dlt * k3, y + dlt * k3, t + dlt);
		x += (dlt / 6) * (k1 + 2*k2 + 2*k3 + k4);
		y += (dlt / 6) * (k1 + 2*k2 + 2*k3 + k4);
		t += dlt;
	}

}
