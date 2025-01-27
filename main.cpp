/*********************************************************************
 * \file   main.cpp
 * \brief  
 * 
 * \author Harukichimaru
 * \date   January 2025
 * \note   
 *********************************************************************/
#include <iostream>
#include <string>
#include <chrono>
#include <Windows.h>

///=============================================================================
///						メイン処理
int main() {
	// コンソールの出力コードページをUTF-8に設定
	SetConsoleOutputCP(65001);

	//========================================
	// 100000文字の初期化
	std::string a(100000, 'a');

	//========================================
	// コピーの時間計測開始
	std::chrono::high_resolution_clock::time_point start_copy = std::chrono::high_resolution_clock::now();
	// コピー
	std::string b = a;
	// コピーの時間計測終了
	std::chrono::high_resolution_clock::time_point end_copy = std::chrono::high_resolution_clock::now();
	// コピーにかかった時間を計算
	long long duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

	//========================================
	// 移動の時間計測開始
	std::chrono::high_resolution_clock::time_point start_move = std::chrono::high_resolution_clock::now();
	// 移動
	std::string c = std::move(a);
	// 移動の時間計測終了
	std::chrono::high_resolution_clock::time_point end_move = std::chrono::high_resolution_clock::now();
	// 移動にかかった時間を計算
	long long duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

	//========================================
	// 結果表示
	printf("コピーにかかった時間: %lld マイクロ秒\n", duration_copy);
	printf("移動にかかった時間: %lld マイクロ秒\n", duration_move);

	return 0;
}
