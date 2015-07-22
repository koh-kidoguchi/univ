#include <stdio.h>

double lmd = 5;

double f_x(double x) {
	return -lmd * x;
}

int main(void) {
	double dlt = 0.01;
	double x = 2;
	double t = 0;
	double k1, k2, k3, k4;	

	int i;
	
	for (i=0; i<100; i++) {
		printf("%f %f\n", t, x);
		k1 = f_x(x);
		k2 = f_x(x + k1*dlt/2);
		k3 = f_x(x + k2*dlt/2);
		k4 = f_x(x + k3 * dlt);

		x += (dlt / 6) * (k1 + 2*k2 + 2*k3 + k4);
		t += dlt;
	}

}