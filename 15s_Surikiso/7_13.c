#include <stdio.h>
#include <math.h>

#define N 80  //変数
#define L 1.0
#define j 4.0
#define u 2.0  //変数
#define PI 3.1415926535897932384626
#define A 1.0
#define tstep 100  //変数
#define k 1

int main() {
	double  x[3*N+2],
			f[3*N+2],
			fn[3*N+2],
			dx = (double) 1.0/N,
			dt = 0.00001,
			min;
	int		i,
			n;

	
	for(i=0; i<=3*N+1; i++) {
		x[i] = (double) dx*i;
	}

	//初期条件の設定
	for (i=0; i<=3*N+1; i++) {
		f[i] = A * cos(2*PI*j*x[i]/L);
	}
	min = 1;

	//ステップを進めていく
	for (n=0; n<tstep; n++) {
		min += 1;

		for (i=1; i<=3*N; i++) {
			fn[i] = f[i] + (k / (dx*dx) * (f[i+1] - 2.0*f[i] + f[i-1]) - u / (2*dx) * (f[i+1] - f[i-1])) * dt;
		}
		fn[0] = f[2*N] + (k / (dx*dx) * (f[2*N+1] - 2.0*f[2*N] + f[2*N-1]) - u / (2*dx) * (f[2*N+1] - f[2*N-1])) * dt; //=fn[2L]

		for (i=0; i<=3*N+1; i++) {
			f[i] = fn[i];
		}


		for (i=0; i<=3*N+1; i++) {
			if (fn[i] < min) {
				min = fn[i];
			}

			if (fn[i] )
		}
		printf("%d %f\n", n, (double)i/N);
	}
}