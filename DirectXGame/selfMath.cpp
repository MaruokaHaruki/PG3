#include "selfMath.h"

///-------------------------------///
// インスタンスアクセス用変数
///-------------------------------///
selfMath* selfMath::GetInstance() {
	static selfMath instance;

	return &instance;
}


///-------------------------------///
/// コンストラクタ
///-------------------------------///
selfMath::selfMath() {}

///-------------------------------///
/// デストラクタ
///-------------------------------///
selfMath::~selfMath() {}



///-------------------------------///
/// utils
///-------------------------------///

/// ===ベクトルの向きの抽出=== ///
Vector3 selfMath::TransformNormal(const Vector3& v, const Matrix4x4& m) { 
	Vector3 result{
	    v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],
	    v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],
	    v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2],
	};

	return result;
}

/// ===ベクトルを正規化=== ///
Vector3 selfMath::Normalize(const Vector3& v) { 
		float mag = Magnitude(v);
	if (mag != 0.0f) {
		return {v.x / mag, v.y / mag, v.z / mag};
	}
	// ゼロベクトルの場合はそのまま返す
	return v;
}


///-------------------------------///
/// 4x4の計算
///-------------------------------///
/// ===行列の加法=== ///
Matrix4x4 selfMath::Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	return result;
}

/// ===行列の減算=== ///
Matrix4x4 selfMath::Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
	}
	return result;
}

/// ===行列の積=== ///
Matrix4x4 selfMath::Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result;

	// 行列の各成分を直接計算して結果を求める
	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];

	return result;
}


/// ===逆行列を計算する関数=== ///
// 行列の余因子行列を計算するヘルパー関数
Matrix4x4 CofactorMatrix(const Matrix4x4& matrix);

// 余因子行列の計算に必要なサブ行列を計算するヘルパー関数
float Minor(const Matrix4x4& matrix, int row, int col);

Matrix4x4 selfMath::Inverse(const Matrix4x4& matrix) {

	// 行列式を計算
	float det = matrix.m[0][0] * (matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2] -
	                              matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2] - matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3]) -
	            matrix.m[0][1] * (matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2] -
	                              matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2] - matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3]) +
	            matrix.m[0][2] * (matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1] -
	                              matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3]) -
	            matrix.m[0][3] * (matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2] + matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1] -
	                              matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2]);

	Matrix4x4 cofactorMatrix = CofactorMatrix(matrix);
	Matrix4x4 adjugateMatrix;
	// 余因子行列の転置を求める
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			adjugateMatrix.m[i][j] = cofactorMatrix.m[j][i];
		}
	}

	Matrix4x4 inverseMatrix;
	// 逆行列を求める
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			inverseMatrix.m[i][j] = adjugateMatrix.m[i][j] / det;
		}
	}

	return inverseMatrix;
}

Matrix4x4 CofactorMatrix(const Matrix4x4& matrix) {
	Matrix4x4 cofactorMatrix;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float minor = Minor(matrix, i, j);
			// 余因子行列の符号付き小行列行列式
			cofactorMatrix.m[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor;
		}
	}
	return cofactorMatrix;
}

float Minor(const Matrix4x4& matrix, int row, int col) {
	float subMatrix[3][3];
	int subRow = 0;
	for (int i = 0; i < 4; i++) {
		if (i == row)
			continue;
		int subCol = 0;
		for (int j = 0; j < 4; j++) {
			if (j == col)
				continue;
			subMatrix[subRow][subCol] = matrix.m[i][j];
			subCol++;
		}
		subRow++;
	}

	return subMatrix[0][0] * (subMatrix[1][1] * subMatrix[2][2] - subMatrix[1][2] * subMatrix[2][1]) - subMatrix[0][1] * (subMatrix[1][0] * subMatrix[2][2] - subMatrix[1][2] * subMatrix[2][0]) +
	       subMatrix[0][2] * (subMatrix[1][0] * subMatrix[2][1] - subMatrix[1][1] * subMatrix[2][0]);
}

/// ===転置行列=== ///
Matrix4x4 selfMath::Transpose(const Matrix4x4& matrix) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = matrix.m[j][i];
		}
	}
	return result;
}

/// ===単位行列の作成=== ///
Matrix4x4 selfMath::Identity() {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i == j) {
				result.m[i][j] = 1.0f;
			} else {
				result.m[i][j] = 0.0f;
			}
		}
	}
	return result;
}

///-------------------------------///
/// 3次元アフィン行列
///-------------------------------///
/// ===平行移動行列を作成する関数=== ///
Matrix4x4 selfMath::MakeTranslateMatrix(const Vector3& translate) {
	// 単位行列を初期化
	Matrix4x4 result = Identity();

	// 平行移動成分をセット
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;
}

/// ===拡大縮小行列を作成する関数=== ///
Matrix4x4 selfMath::MakeScaleMatrix(const Vector3& scale) {
	// 単位行列を初期化
	Matrix4x4 result = Identity();

	// 拡大縮小成分をセット
	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;

	return result;
}

/// X軸回転行列(yz)
Matrix4x4 selfMath::MakeRotateXMatrix(float radian) {
	// 単位行列で初期化
	Matrix4x4 result = Identity();

	// 行列の計算
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = std::sin(radian);
	result.m[2][1] = -std::sin(radian);
	result.m[2][2] = std::cos(radian);

	return result;
}

/// Y軸回転行列(zx)
Matrix4x4 selfMath::MakeRotateYMatrix(float radian) {
	// 単位行列で初期化
	Matrix4x4 result = Identity();

	// 行列の計算
	result.m[0][0] = std::cos(radian);
	result.m[0][2] = -std::sin(radian);
	result.m[2][0] = std::sin(radian);
	result.m[2][2] = std::cos(radian);

	return result;
}

/// Z軸回転行列(xy)
Matrix4x4 selfMath::MakeRotateZMatrix(float radian) {
	// 単位行列で初期化
	Matrix4x4 result = Identity();

	// 行列の計算
	result.m[0][0] = std::cos(radian);
	result.m[0][1] = std::sin(radian);
	result.m[1][0] = -std::sin(radian);
	result.m[1][1] = std::cos(radian);

	return result;
}

/// ===座標変換を行う関数=== ///
Vector3 selfMath::Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector3 result;

	// 行列とベクトルの乗算
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + matrix.m[3][3];
	// この処理を忘れない！
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

/// ===アフィン変換=== ///
Matrix4x4 selfMath::MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	// 縮小拡大
	Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
	// 回転
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));
	// 並行移動
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
	// 合成
	Matrix4x4 result = Identity();
	result = Multiply(scaleMatrix, rotateXYZMatrix);
	result = Multiply(result, translateMatrix);

	return result;
}
#include "selfMath.h"
