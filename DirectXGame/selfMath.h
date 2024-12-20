#include "assert.h"
#include <Matrix4x4.h>
#include <Vector3.h>
#include <cmath>

#pragma once
class selfMath final {
private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	selfMath();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~selfMath();

	///
	/// 4x4の計算
	///

#pragma endregion

public:
	/// <summary>
	/// インスタンスアクセス用関数
	/// </summary>
	/// <returns></returns>
	static selfMath* GetInstance();

	///
	///utils
	///

	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	float Dot(const Vector3& v1, const Vector3& v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }



	/// <summary>
	/// ベクトルの大きさ（長さ）を計算する関数
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	float Magnitude(const Vector3& v) { return std::sqrt(Dot(v, v)); }


	/// <summary>
	/// ベクトルの向きの抽出
	/// </summary>
	/// <param name="v"></param>
	/// <param name="m"></param>
	/// <returns></returns>
	Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);


	/// <summary>
	/// ベクトルを正規化
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	Vector3 Normalize(const Vector3& v);

	///
	///end
	///


#pragma region 4x4の計算

	/// <summary>
	/// 行列の加法
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 行列の減算
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 行列の積
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// 逆行列を計算する関数
	/// </summary>
	/// <param name="matrix"></param>
	/// <returns></returns>
	Matrix4x4 Inverse(const Matrix4x4& matrix);

	/// <summary>
	/// 転置行列
	/// </summary>
	/// <param name="matrix"></param>
	/// <returns></returns>
	Matrix4x4 Transpose(const Matrix4x4& matrix);

	/// <summary>
	/// 単位行列の作成
	/// </summary>
	/// <returns></returns>
	Matrix4x4 Identity();


#pragma endregion

	///
	/// end
	///

	///
	/// 3次元アフィン行列
	///

#pragma region 3次元アフィン行列

	/// <summary>
	/// 平行移動行列を作成する関数
	/// </summary>
	/// <param name="translate"></param>
	/// <returns></returns>
	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	/// <summary>
	/// 拡大縮小行列を作成する関数
	/// </summary>
	/// <param name="scale"></param>
	/// <returns></returns>
	Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	/// <summary>
	/// x軸中心の回転行列を作成する関数
	/// </summary>
	/// <param name="angle"></param>
	/// <returns></returns>
	Matrix4x4 MakeRotateXMatrix(float radian);

	/// <summary>
	/// y軸中心の回転行列を作成する関数
	/// </summary>
	/// <param name="angle"></param>
	/// <returns></returns>
	Matrix4x4 MakeRotateYMatrix(float radian);

	/// <summary>
	/// // z軸中心の回転行列を作成する関数
	/// </summary>
	/// <param name="angle"></param>
	/// <returns></returns>
	Matrix4x4 MakeRotateZMatrix(float radian);

	/// <summary>
	/// 座標変換を行う関数
	/// </summary>
	/// <param name="vector"></param>
	/// <param name="matrix"></param>
	/// <returns></returns>
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

	/// <summary>
	/// //アフィン変換
	/// </summary>
	/// <param name="scale"></param>
	/// <param name="rotate"></param>
	/// <param name="translate"></param>
	/// <returns></returns>
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
};