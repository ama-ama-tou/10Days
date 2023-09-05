#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
/// <summary>
/// 2次元ベクトル
/// </summary>
struct Vec2 final {
    float x;
    float y;
    // コンストラクタ
    Vec2() : x(0), y(0) {}
    Vec2(float x, float y) : x(x), y(y) {}

    // ベクトルの長さを返す
    float length() const {
        return sqrtf(x * x + y * y);
    }

    // ベクトルの長さの2乗を返す（計算の最適化用）
    float lengthSquared() const {
        return x * x + y * y;
    }

    // ベクトルを正規化した結果を返す
    Vec2 normalize() const {
        float len = length();
        if (len != 0) {
            return Vec2(x / len, y / len);
        }
        return Vec2(0, 0);
    }

    // ベクトルの加算
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 operator+=(const Vec2& other){
        this->x += other.x;
        this->y += other.y;

        return ;
    }

    // ベクトルの減算
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }
    Vec2 operator-=(const Vec2& other) {
        this->x -= other.x;
        this->y -= other.y;
        return ;
    }

    Vec2 operator*(const Vec2& other) const {
        return Vec2(x * other.x, y * other.y);
    }

    // ベクトルのスカラー除算
    Vec2 operator/(float scalar) const {
        if (scalar != 0) {
            return Vec2(x / scalar, y / scalar);
        }
        return Vec2(0, 0);
    }
    operator int() const {
        return static_cast<int>(x);
    }
};

