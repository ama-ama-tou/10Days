#pragma once
#include"Vec2.h"
#include"Matrix3x3.h"

/// <summary>
/// •½sˆÚ“®
/// </summary>
/// <param name="target">‘ÎÛ</param>
/// <param name="trans">ˆÚ“®‹——£</param>
/// <returns></returns>
Vec2 Translation(Vec2& target, Vec2 trans);
/// <summary>
/// Šg‘åk¬
/// </summary>
/// <param name="target">‘ÎÛ</param>
/// <param name="scale">Šgk—¦</param>
/// <returns></returns>
Vec2 Scaling(Vec2& target, Vec2 scale);
/// <summary>
/// ‰ñ“]
/// </summary>
/// <param name="target">‘ÎÛ</param>
/// <param name="theta">theta“x‰ñ“]‚·‚é(1“x‚Å)</param>
/// <returns></returns>
Vec2 Rotating(Vec2& target, float theta);
/// <summary>
/// ƒAƒtƒBƒ“•ÏŠ·
/// </summary>
/// <param name="target">‘ÎÛ</param>
/// <param name="target2origine">‘ÎÛ‚©‚ç•ÏŠ·Œ´“_‚Ü‚Å‚Ì‹——£</param>
/// <param name="scale">Šgk—¦</param>
/// <param name="theta">theta“x‰ñ“]‚·‚é(1“x‚Å)</param>
/// <returns></returns>
Vec2 Affine(Vec2& target, Vec2 target2origine, Vec2 scale, float theta);
