/*********************************************************************
 * \file   player.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#pragma once
#include <cassert>
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"


///=============================================================================
///						自キャラ
class Player {
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/**----------------------------------------------------------------------------
	 * \brief  MoveRight 
	 */
	void MoveRight();

	/**----------------------------------------------------------------------------
	 * \brief  MoveLeft 
	 */
	void MoveLeft();

private:
	/// ===ワールド変換データ=== ///
	WorldTransform worldTransform_;
	/// ===ビュープロジェクション=== ///
	ViewProjection* viewProjection_ = nullptr;

	/// ===モデル=== ///
	Model* model_ = nullptr;
	/// ===テクスチャハンドル=== ///
	uint32_t textureHandle_ = 0u;

};
