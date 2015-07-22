#include <stdio.h>

double lmd = 5;

double f(double a, double b) {
	return - lmd * a;
}

int main(void) {
	double dlt = 0.01;
	double x = 10;
	double t = 0;
	double k1, k2, k3, k4;

	int i;
	
	for (i=0; i<500; i++) {
		printf("%f %f\n", t, x);
		k1 = f(x, t);
		k2 = f(x + (dlt / 2) * k1, t + dlt / 2);
		k3 = f(x + (dlt / 2) * k2, t + dlt / 2);
		k4 = f(x + dlt * k3, t + dlt);
		x += (dlt / 6) * (k1 + 2*k2 + 2*k3 + k4);
		t += dlt;
	}

}
