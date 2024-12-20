/*********************************************************************
 * \file   InputHandler.h
 * \brief
 *
 * \author Harukichimaru
 * \date   December 2024
 * \note
 *********************************************************************/
#pragma once
#include <Command.h>

///=============================================================================
///						インプットハンドラ
// NOTE: インプットハンドラは、キーボードやマウスなどの入力を処理するクラス。
class InputHandler {
public:

	/**----------------------------------------------------------------------------
	 * \brief  HandleInput
	 * \return
	 */
	ICommand *HandleInput();

	// NOTE:InputHandler内でキーの割り当てを(アサイン)を行う
	/**----------------------------------------------------------------------------
	 * \brief  AssignMoveLeftCommand
	 * \param  command
	 */
	void AssignMoveRightCommand2PressKeyD();

	/**----------------------------------------------------------------------------
	 * \brief  AssignMoveLeftCommand
	 * \param  command
	 */
	void AssignMoveLeftCommand2PressKeyA();

	///--------------------------------------------------------------
	///						 メンバ変数
private:
	/// ===右移動コマンド=== ///
	ICommand *pressKeyD_ = nullptr;
	/// ===左移動コマンド=== ///
	ICommand *pressKeyA_ = nullptr;

};

