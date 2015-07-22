#include <stdio.h>
#include <math.h>
#include <complex.h>
#define PI 3.141592653589793238
#define L 1

double G(double κ, double dlt, double dlx, double k) {
	return 1 - (2*κ*dlt/pow(dlx,2))*(1-cos(k)*dlx)
}

int main(void) {
	double f = cos(2*PI*n*x/L);

	double dlx = 0.05;
	double dlt = 0.05;

	f = (dlt/pow(dlx, 2)) * (f(dlx*)
}
