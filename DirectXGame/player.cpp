#include "Player.h"
#include "Input.h"
#include "SelfMath.h"

///=====================================================///
///初期化
///=====================================================///
void Player::Initialize(Model *model, uint32_t textureHandle, ViewProjection *viewProjection) {
	// NULLポインタチェック
	assert(model);
	// 引数で受け取ったデータをメンバ変数に記録する
	textureHandle_ = textureHandle;
	model_ = model;
	// ワールド変数の初期化
	worldTransform_.Initialize();
	// ビュープロジェクションをメンバ変数に記録
	viewProjection_ = viewProjection;
}


///=====================================================///
///更新処理
///=====================================================///
void Player::Update() {
	// ワールド変換行列を更新
	worldTransform_.matWorld_ = selfMath::GetInstance()->MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}


///=====================================================///
///描画処理
///=====================================================///
void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}

///=============================================================================
///						右移動
void Player::MoveRight() {
	// ワールド変換行列を右に移動
	worldTransform_.translation_.x += 0.1f;
}

///=============================================================================
///						左移動
void Player::MoveLeft() {
	// ワールド変換行列を左に移動
	worldTransform_.translation_.x -= 0.1f;
}
