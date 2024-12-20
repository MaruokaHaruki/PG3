#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Command.h"
#include "InputHandler.h"

/// ===追加=== ///
// NOTE:スマートポインタ。消滅するときにDeleteを自動で呼び出してくれる。
#include <memory>

/// ===自作=== ///
#include "Player.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	/// ===ワールドトランスフォーム=== ///
	WorldTransform WorldTransform_;

	/// ===ビュープロジェクション=== ///
	ViewProjection ViewProjection_;

	/// ===コマンド=== ///
	InputHandler *inputHandler_ = nullptr;
	ICommand *iCommand_ = nullptr;
	

	/// ===プレイヤー=== ///
	// 自キャラ
	std::unique_ptr<Player> player_ = nullptr;
	// テクスチャハンドル
	uint32_t playerTH_ = 0;
	// スプライト
	std::unique_ptr <Sprite> playerSprite_ = nullptr;
	// 3Dモデル
	std::unique_ptr <Model> playerModel_ = nullptr;

	/// ===ImGuiで値を入力する変数=== ///
	float inputFloat[3] = {0, 0, 0};

#ifdef _DEBUG
	/// ===デバックカメラ=== ///
	DebugCamera* debugCamera_ = nullptr;
#endif // DEBUG
};
