#include <stdio.h>
#define N 4

int main(void) {

    int i, j, k, n;
     
    // 拡大係数行列 M
    double M[N][N + 1] =
    {
        {1,  1,  1,  1, 10},
        {2,  1,  2,  1, 14},
        {1,  2,  3, -4, -2},
        {1, -1, -1,  1,  0}
    };
     
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
    for(k = 0; k < N; ++k){
        for(n = 0; n < N + 1; ++n){
            printf(" %f",M[k][n]);
        }
        printf("\n");
    }
}