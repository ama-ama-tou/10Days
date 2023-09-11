#include "Matrix3x3.h"

/// <summary>
/// 行列同士の掛け算
/// </summary>
/// <param name="L">左辺</param>
/// <param name="R">右辺</param>
/// <returns></returns>
Matrix3x3 operator*(const Matrix3x3& L, const Matrix3x3& R) {

    Matrix3x3 result{ 0 };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.m[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                result.m[i][j] += L.m[i][k] * R.m[k][j];
            }
        }
    }
    return result;
}

/// <summary>
/// 自己代入版の乗算演算子
/// </summary>
/// <param name="L">左辺</param>
/// <param name="R">右辺</param>
/// <returns></returns>
Matrix3x3& operator*=(Matrix3x3& L, const Matrix3x3& R) {
    L = L * R;
    return L;
}