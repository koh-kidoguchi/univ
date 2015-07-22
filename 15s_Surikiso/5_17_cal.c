#include <stdio.h>
#include <math.h>
#include <complex.h>
#define PI 3.141592

double f (double t) {
	double result = 10 * sin(2*PI*t) + 2 * sin(4*PI*t) + 4 * sin(8*PI*t);
	return result;
}

int cal(void) {

	double N = 20;
	double time = 1;
	double dlt = time / N;

	double t = 0;
	double i = 0;

	double _Complex c1 = 0;
	double _Complex c2 = 0;
	double _Complex c4 = 0;			

	double _Complex tmp = cexp(I*2*PI/N);

	for (i=0; i<N; i++){
		c1 += f(t) * cpow(tmp, i*1);
		c2 += f(t) * cpow(tmp, i*2);
		c4 += f(t) * cpow(tmp, i*4);
		t += dlt;
	}
}