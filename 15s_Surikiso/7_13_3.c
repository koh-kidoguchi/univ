#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.141592653589793238
#define N 80  //変数
#define L 1.0
#define j 1.0  //変数
#define u 100.0  
#define A 1.0
#define tstep 3000  //変数
#define k 1

int main(void) {

	double x[6*N+2],
		   f[6*N+2],
		   fn[6*N+2],
		   dx = (double) 1.0/N,
		   dt = 0.000001;
	double time = 1;

	double t = 0;
	int i,n;

	double _Complex c[80];
	for (i=0; i<80; i++) {
		c[i] = 0;
	}

	double _Complex tmp = cexp(I*2*PI/N);

	for(i=0; i<=6*N+1; i++) {
		x[i] = (double) dx*i;
	}

	//初期条件の設定
	for (i=0; i<=6*N+1; i++) {
		f[i] = A * cos(2*PI*j*x[i]/L);
	}	

	for (int i=2*N; i<3*N; i++){
		for (int m=0; m<N; m++) {
			c[i] += f[i] * cpow(tmp, i*m);
			t += dt;
		}
	}

	//ステップを進めていく
	for (n=0; n<tstep; n++) {

		for (i=1; i<=6*N; i++) {
			fn[i] = f[i] + (k / (dx*dx) * (f[i+1] - 2.0*f[i] + f[i-1]) - u / (2*dx) * (f[i+1] - f[i-1])) * dt;
		}
		fn[0] = f[2*N] + (k / (dx*dx) * (f[2*N+1] - 2.0*f[2*N] + f[2*N-1]) - u / (2*dx) * (f[2*N+1] - f[2*N-1])) * dt; //=fn[2L]

		for (i=0; i<=6*N+1; i++) {
			f[i] = fn[i];
		}
	}	

	//波の形を出力
	// for (i=2*N; i<4*N; i++) {
	// 	printf("%f %f\n", i*dx, fn[i]);
	// }

	//フーリエ変換したものを出力
	// for (int i=0; i<N; i++)
	// {
	// 	printf("%d %f\n", i, creal(c[i]));
	// }
	// printf("\n");
	
	for (int i=0; i<N; i++)
	{
		printf("%d %f\n", i, cimag(c[i]));
	}
	printf("\n");
	
}