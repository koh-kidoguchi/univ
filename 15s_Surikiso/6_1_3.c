#include <stdio.h>
#define N 20

int main(void) {

    int i, j, k, n;
    double x = -0.475;
     
    // 拡大係数行列 M
    double M[N][N + 1];

    for (k = 0; k < N; k++) {

    	if (k == 0) { //1行目にセット
    		M[k][0] = 1;
    		for (n = 1; n < N; n++) {
    			M[k][n] = 0;
    		}
    	} else if (k == N-1) { //N+1行目にセット
    		M[k][N-1] = 1;
    		for (n = 0; n < N-1; n++) {
    			M[k][n] = 0;
    		}
    	} else {
    		for (n = 0; n < N; n++) {
	    		if (k == n) {
	    			M[k][n] = -2;
	    		} else if (k == n-1 || k == n+1) {
	    			M[k][n] = 1;
	    		} else {
	   			M[k][n] = 0;
	   			}
    		}
    	}
    }

    for (k = 0; k < N; k++) {
    	if (k < N/2.0) {
    		M[k][N] = -1;
    	} else {
    		M[k][N] = 1;
    	}
    }
     
    double pivot, mul;
     
    // 対角成分が1で正規化された階段行列を作る(前進消去)
    for (i = 0; i < N; ++i)
    {
        // 対角成分の選択、この値で行成分を正規化
        pivot = M[i][i];
        for (j = 0; j < N + 1; ++j)
        {
            M[i][j] = (1 / pivot) * M[i][j];
        }
     
        // 階段行列を作る為に、現在の行より下の行について
        // i列目の成分が0になるような基本変形をする
        for (k = i + 1; k < N; ++k)
        {
            mul = M[k][i];
            for (n = i; n < N + 1; ++n)
            {
                M[k][n] = M[k][n] -  mul * M[i][n];
            }
        }
    }
     
    // 下から上に向かって変数に代入して、独立した解の形にする(後進代入)
    // このとき一番下の行はすでに独立した解を得ている
    for (i = N - 1; i > 0; --i)
    {
        for (k = i - 1; k >= 0; --k)
        {
            mul = M[k][i];
            for (n = i; n < N + 1; ++n)
            {
                M[k][n] = M[k][n] - mul * M[i][n];
            }
        }
    }

    //行列を出力 
    // for (k = 0; k < N; ++k) {
    //     for(n = 0; n < N + 1; ++n){
    //         printf(" %f",M[k][n]);
    //     }
    //     printf("\n");
    // }

    for (k = 0; k < N; ++k) {
    	printf("%f %f\n", x+0.5, M[k][N]*(0.05)*(0.05));
    	x+=0.05;
    }
}
