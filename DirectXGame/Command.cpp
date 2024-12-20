#include "Command.h"
#include "Player.h"

// NOTE:インターフェイスの概念は、クラスのメンバ関数を純粋仮想関数にすることで、インターフェイスを実現する。
// このインターフェイスを継承したクラスは、必ずExecute関数を実装しなければならない。

///=============================================================================
///						右移動コマンド
void MoveRightCommand::Execute(Player* player) {
	// プレイヤーを右に移動
	player->MoveRight();
}

///=============================================================================
///						左移動コマンド
void MoveLeftCommand::Execute(Player* player) {
	// プレイヤーを左に移動
	player->MoveLeft();
}

ICommand::~ICommand() {
}
