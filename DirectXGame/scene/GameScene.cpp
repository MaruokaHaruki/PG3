#include "GameScene.h"
#include "AxisIndicator.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete debugCamera_;
}


///=====================================================///
///初期化
///=====================================================///
void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	///----------------------------------------///
	/// その他
	///----------------------------------------///
	// スプライトの生成
	playerSprite_.reset(Sprite::Create(playerTH_, {100, 50}));
	// ワールドトランスフォームの初期化
	WorldTransform_.Initialize();
	// ビュープロジェクション
	ViewProjection_.Initialize();

	///--------------------------------------------------------------
	///						 Command
	inputHandler_ = new InputHandler();
	// 右移動コマンドを割り当て
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	// 左移動コマンドを割り当て
	inputHandler_->AssignMoveLeftCommand2PressKeyA();


	///-------------------------------------------///
	///Player変数
	///-------------------------------------------///
	// 自キャラの生成
	player_ = std::make_unique<Player>();
	// テクスチャ
	playerTH_ = TextureManager::Load("/uvChecker.png");
	// 3Dモデルの生成
	// NOTE:こういう場合はResetを使用する。リセットはすでに代入済みのアドレスがあればそれを開放し、入れ替えて代入する。
	playerModel_.reset(Model::Create());

	// ビュープロジェクションの初期化
	ViewProjection_.Initialize();
	// 自キャラの初期化
	player_->Initialize(playerModel_.get(), playerTH_, &ViewProjection_);






	// デバックカメラ
	debugCamera_ = new DebugCamera(WinApp::kWindowWidth, WinApp::kWindowHeight);
	// 軸方向表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	// 軸方向表示が参照するビュープロジェクションを指定する
	AxisIndicator::GetInstance()->SetTargetViewProjection(&debugCamera_->GetViewProjection());

	/// ライン描画が参照するビュープロジェクションを指定
	PrimitiveDrawer::GetInstance()->SetViewProjection(&ViewProjection_);
}


///=====================================================///
///更新処理
///=====================================================///
void GameScene::Update() {

	///----------------------------------------///
	/// デバックテキストの表示
	///----------------------------------------///
	// ウィンドウ作成
	ImGui::Begin("Debug1");
	ImGui::Text("Maruoka Haruki %d %d %d", 2050, 12, 31);
	// float3入力ボックス
	ImGui::InputFloat3("inputFloat3", inputFloat);
	// float3スライダー
	// スライダーのラベル、サイズ、範囲を設定
	// デモウィンドウの表示を有効化
	ImGui::ShowDemoWindow();
	ImGui::End();

	///-------------------------------------------///
	///コマンド
	///-------------------------------------------///
	iCommand_ = inputHandler_->HandleInput();

	// コマンドが存在する場合
	if(this->iCommand_) {
		// コマンドを実行
		iCommand_->Execute(player_.get());
	}


	///-------------------------------------------///
	///プレイヤー
	///-------------------------------------------///
	player_->Update(); 
	

	///----------------------------------------///
	/// デバックカメラ
	///----------------------------------------///
	debugCamera_->Update();
}


///=====================================================///
///描画処理
///=====================================================///
void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ↓ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	///-------------------------------------------///
	///プレイヤー
	///-------------------------------------------///
	player_->Draw();




	///
	/// ↑
	///

	///----------------------------------------///
	/// ラインを描画する
	///----------------------------------------///
	PrimitiveDrawer::GetInstance()->DrawLine3d({0, 0, 0}, {0, 10, 0}, {1.0f, 0.0f, 0.0f, 1.0f});

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ↓ここに前景スプライトの描画処理を追加できる
	/// </summary>



	///
	/// ↑
	///

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
