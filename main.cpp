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
#include "Instrument.h"
#include "Piano.h"
#include "Guitar.h"
#include <vector>



 ///=============================================================================
 ///						MAIN
int main() {
	SetConsoleOutputCP(65001);

	///--------------------------------------------------------------
	///						 変数宣言・初期化
	// 楽器のインスタンスをポリモーフィズムで管理
	std::vector<std::unique_ptr<Instrument>> instruments;
	instruments.push_back(std::make_unique<Piano>());
	instruments.push_back(std::make_unique<Guitar>());



	///--------------------------------------------------------------
	///							処理

	// 各楽器の音を鳴らす
	// Note:auto& instrument : instrumentsは範囲ベースfor文。正直、明示的にすべきではある。
	for(const auto& instrument : instruments) {
		instrument->playSound();
	}

	return 0;
}