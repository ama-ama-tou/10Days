#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
/// <summary>
/// 2�����x�N�g��
/// </summary>
struct Vec2 final {
    float x;
    float y;
    // �R���X�g���N�^
    Vec2() : x(0), y(0) {}
    Vec2(float x, float y) : x(x), y(y) {}

    // �x�N�g���̒�����Ԃ�
    float length() const {
        return sqrtf(x * x + y * y);
    }

    // �x�N�g���̒�����2���Ԃ��i�v�Z�̍œK���p�j
    float lengthSquared() const {
        return x * x + y * y;
    }

    // �x�N�g���𐳋K���������ʂ�Ԃ�
    Vec2 normalize() const {
        float len = length();
        if (len != 0) {
            return Vec2(x / len, y / len);
        }
        return Vec2(0, 0);
    }

    // �x�N�g���̉��Z
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 operator+=(const Vec2& other){
        this->x += other.x;
        this->y += other.y;

    }

    // �x�N�g���̌��Z
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }
    Vec2 operator-=(const Vec2& other) {
        this->x -= other.x;
        this->y -= other.y;
     
    }

    Vec2 operator*(const Vec2& other) const {
        return Vec2(x * other.x, y * other.y);
    }

    // �x�N�g���̃X�J���[���Z
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

