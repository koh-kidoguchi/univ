#include <stdio.h>
#include <math.h>

#define N 56
#define L 1.0
#define j 3.0
#define PI 3.1415926535897932384626
#define A 1.0
#define tstep 200

int main() {
	double  x[5*N+2],
			f[5*N+2],
			fn[5*N+2],
			dx = (double) 1.0/N,
			dt = 0.0001;
	int		i,
			n;

	//初期条件の設定
	for(i=0; i<=5*N+1; i++) {
		x[i] = (double) dx*i;
	}

	for (i=0; i<=5*N+1; i++) {
		f[i] = A * cos(2*PI*j*x[i]/L);
	}

	//ステップを進めていく
	for (n=0; n<tstep; n++) {

		for (i=1; i<=5*N; i++) {
			fn[i] = f[i] + dt / (dx*dx) * (f[i+1] - 2.0*f[i] + f[i-1]);
		}
		fn[0] = f[4*N] + dt / (dx*dx) * (f[4*N+1] - 2.0*f[4*N] + f[4*N-1]); //=fn[4L]

		for (i=0; i<=5*N+1; i++) {
			f[i] = fn[i];
		}
	}



	for (i=0; i<=N; i++) {
		printf("%f %f\n", x[i], fn[i]);
	}
}