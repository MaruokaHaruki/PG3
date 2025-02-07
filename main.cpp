/*********************************************************************
 * \file   main.cpp
 * \brief
 *
 * \author Harukichimaru
 * \date   November 2024
 * \note
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <Windows.h>

///=============================================================================
///						CSVファイルを読み込む関数
/**
 * @brief CSVファイルを読み込み、2次元ベクターに格納する関数
 * @param filename 読み込むCSVファイルの名前
 * @param mapChips 読み込んだデータを格納する2次元ベクター
 */
void loadCSV(const std::string &filename, std::vector<std::vector<int>> &mapChips) {
	//========================================
	// ファイルを開く
	std::ifstream file(filename);
	if(!file.is_open()) {
		//========================================
		// ファイルが開けなかった場合のエラーメッセージ
		printf("ファイルを開くことができませんでした:( %s\n", filename.c_str());
		return;
	}
	//========================================
	// ファイルの内容を読み込む
	std::string line;
	while(std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;
		//========================================
		// 行をカンマで区切って各セルを読み込む
		while(std::getline(ss, cell, ',')) {
			//========================================
			// セルの値を整数に変換してベクターに追加
			row.push_back(std::stoi(cell));
		}
		//========================================
		// 行を2次元ベクターに追加
		mapChips.push_back(row);
	}
	//========================================
	// ファイルを閉じる
	file.close();
}
///=============================================================================
///						マップチップを表示する関数
void displayMapChips(const std::vector<std::vector<int>> &mapChips) {
	//========================================
	// マップチップを表示
	for(const auto &row : mapChips) {
		//========================================
		// 行の各セルを表示
		for(const auto &cell : row) {
			switch(cell) {
			case 0:
				printf("　"); // 全角スペース
				break;
			case 1:
				printf("地");
				break;
			case 2:
				printf("自");
				break;
			default:
				printf("?");
				break;
			}
		}
		printf("\n");
	}
}

 ///=============================================================================
 ///						MAIN
int main() {
	///--------------------------------------------------------------
	/// 					文字コード設定
	SetConsoleOutputCP(65001);
	///--------------------------------------------------------------
	///						変数宣言・初期化
	// マップチップの2次元配列
	std::vector<std::vector<int>> mapChips;
	///--------------------------------------------------------------
	///						処理
	//========================================
	// CSVファイルを読み込むスレッドを作成
	std::thread Thread1(loadCSV, "mapchip.csv", std::ref(mapChips));
	//========================================
	// スレッドの終了を待機
	Thread1.join();
	//========================================
	// マップチップを表示
	displayMapChips(mapChips);

	//========================================
	// プログラムの終了
	return 0;
}