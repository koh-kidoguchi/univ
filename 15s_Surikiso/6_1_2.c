#include <stdio.h>
#include <math.h>
#include <complex.h>
#define PI 3.141592653589793238

double g2 (int i) {	
	if (0 <= i && i < 10) {
		return -1;
	} else if (i == 1) {
		return 0;
	} else if (i > 10) {
		return 1;
	}
}

int main(void) {
	double N = 20;
	double time = 1;
	double dlt = time / N;
	double t = 0;
	double n = 0;

	double _Complex G[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	double _Complex rev[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	double _Complex tmp = cexp(I*2*PI/N);

	for (int i=0; i<N; i++){
		for (int k=0; k<N; k++) {
			G[i] += g2(k) * cpow(tmp, i*k);
		}
	}

	for (int i=0; i<N; i++) {
		for (int k=1; k<N; k++)
		{
			rev[i] += (-pow(time/(2*PI*(k-N)), 2)) * G[k] * cpow(tmp, -i*k);
		}
		rev[i] /= N;
	}	

	//元の関数を出力
	// t = 0;
	// for (int i=0; i<N; i++) {
	// 	printf("%f %f\n", t, g2(i));
	// 	t += dlt;
	// }	

	//Gを出力
	// for (int i=0; i<N; i++)
	// {
	// 	printf("%d %f\n", i, creal(G[i]));
	// }
	// printf("\n");
	
	// for (int i=0; i<N; i++)
	// {
	// 	printf("%d %f\n", i, cimag(G[i]));
	// }
	// printf("\n");
	
    //f(=rev)を出力
	t = 0;
	for (int i=0; i<N; i++) {
		printf("%f %f\n", t, creal(rev[i]*2));
		t += dlt;
	}
}