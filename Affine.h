#pragma once
#include"Vec2.h"
#include"Matrix3x3.h"

/// <summary>
/// 平行移動
/// </summary>
/// <param name="target">対象</param>
/// <param name="trans">移動距離</param>
/// <returns></returns>
Vec2 Translation(Vec2& target, Vec2 trans);
/// <summary>
/// 拡大縮小
/// </summary>
/// <param name="target">対象</param>
/// <param name="scale">拡縮率</param>
/// <returns></returns>
Vec2 Scaling(Vec2& target, Vec2 scale);
/// <summary>
/// 回転
/// </summary>
/// <param name="target">対象</param>
/// <param name="theta">theta度回転する(1度で)</param>
/// <returns></returns>
Vec2 Rotating(Vec2& target, float theta);
/// <summary>
/// アフィン変換
/// </summary>
/// <param name="target">対象</param>
/// <param name="target2origine">対象から変換原点までの距離</param>
/// <param name="scale">拡縮率</param>
/// <param name="theta">theta度回転する(1度で)</param>
/// <returns></returns>
Vec2 Affine(Vec2& target, Vec2 target2origine, Vec2 scale, float theta);
