/*********************************************************************
 * \file   InputHandler.cpp
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#include "InputHandler.h"
#include "Input.h"

///=============================================================================
///						インプットハンドラ
ICommand *InputHandler::HandleInput() {
	//========================================
	// キーボードの入力を処理D
	if(Input::GetInstance()->PushKey(DIK_D)) {
		return pressKeyD_;
	}
	//========================================
	// キーボードの入力を処理A
	if(Input::GetInstance()->PushKey(DIK_A)) {
		return pressKeyA_;
	}

	// 何も押されていない場合はnullptrを返す
	return nullptr;
}

///=============================================================================
///						右方向キーを押したときのコマンドを割り当てる
void InputHandler::AssignMoveRightCommand2PressKeyD() {
	ICommand *command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

///=============================================================================
///						左方向キーを押したときのコマンドを割り当てる
void InputHandler::AssignMoveLeftCommand2PressKeyA() {
	ICommand *command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}
