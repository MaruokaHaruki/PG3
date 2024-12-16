/*********************************************************************
 * \file   main.cpp
 * \brief
 *
 * \author Harukichimaru
 * \date   November 2024
 * \note
 *********************************************************************/
#include <stdio.h>
#include <iostream>
#include <Windows.h>
//========================================
// 数学構造体関数
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Transform.h"

//========================================
// 数学関数
#include "AffineTransformations.h"
#include "MathFunc4x4.h"
#include "RenderingMatrices.h"

///=============================================================================
///						アクシス回転行列
Matrix4x4 MakeRotateAxisMatrix(const Vector3& axis, float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	float t = 1.0f - c;
	Vector3 n = Normalize(axis);
	Matrix4x4 m;
	m.m[0][0] = t * n.x * n.x + c;
	m.m[0][1] = t * n.x * n.y + s * n.z;
	m.m[0][2] = t * n.x * n.z - s * n.y;
	m.m[0][3] = 0.0f;
	m.m[1][0] = t * n.x * n.y - s * n.z;
	m.m[1][1] = t * n.y * n.y + c;
	m.m[1][2] = t * n.y * n.z + s * n.x;
	m.m[1][3] = 0.0f;
	m.m[2][0] = t * n.x * n.z + s * n.y;
	m.m[2][1] = t * n.y * n.z - s * n.x;
	m.m[2][2] = t * n.z * n.z + c;
	m.m[2][3] = 0.0f;
	m.m[3][0] = 0.0f;
	m.m[3][1] = 0.0f;
	m.m[3][2] = 0.0f;
	m.m[3][3] = 1.0f;
	return m;
}

///=============================================================================
///						マトリックス出力
void PrintMatrix(const Matrix4x4& m) {
	for(int i = 0; i < 4; i++) {
		// 行列の要素を出力
		//小数点以下3桁まで表示
		printf("%.3f %.3f %.3f %.3f\n", m.m[i][0], m.m[i][1], m.m[i][2], m.m[i][3]);
	}
}


 ///=============================================================================
 ///						MAIN
	int main() {
		SetConsoleOutputCP(65001);

		///--------------------------------------------------------------
		///						 変数宣言・初期化
		// ベクトル
		Vector3 axis = { 1.0f, 1.0f, 1.0f };
		axis = Normalize(axis);
		// 角度
		float angle = 0.44f;
		// 行列
		Matrix4x4 rotateMatrix = MakeRotateAxisMatrix(axis, angle);

		///--------------------------------------------------------------
		///							処理
		// 行列出力
		PrintMatrix(rotateMatrix);

		return 0;
	}