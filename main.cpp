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
// 必要なヘッダファイルをインクルード
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
// NOTE:regixとは正規表現のこと。
// 正規表現とは、文字列のパターンを記述するための記法のこと。
#include <regex>

/**
 * @brief txtファイルを読み込んでデータをパースして配列に格納する関数
 * 
 * @param fileName 読み込むファイルの名前
 * @return std::vector<std::string> パースされたデータの配列
 */
std::vector<std::string> readTxtFile(std::string fileName) {
	//========================================
	// ファイルを読み込む
	std::ifstream ifs(fileName);

	//========================================
	// ファイルが開けなかった場合の処理
	if(!ifs) {
		std::cerr << "Error: file not opened." << std::endl;
		exit(1);
	}

	//========================================
	// ファイルを読み込んでデータをパースして配列に格納
	std::string str;
	std::vector<std::string> vec;

	//========================================
	// ファイルを1行ずつ読み込む
	while (std::getline(ifs, str)) {
		// 文字列をカンマで分割する処理
		std::stringstream ss(str);
		std::string item;

		//========================================
		// カンマで分割して配列に格納
		while (std::getline(ss, item, ',')) {
			//プッシュバック
			vec.push_back(item);
		}
	}

	//========================================
	// ファイルを閉じる
	return vec;
}

/**
 * @brief 内部のデータを並び替える関数
 * 
 * @param vec 並び替えるデータの配列
 * @return std::vector<std::string> 並び替えられたデータの配列
 */
std::vector<std::string> sortData(std::vector<std::string> vec) {
	//========================================
	// 正規表現を使ってkとgの間の数字を取得
	std::regex re("k(\\d+)g(\\d+)@");

	//========================================
	// ラムダ式を使って並び替え
	std::sort(vec.begin(), vec.end(), [&](const std::string& a, const std::string& b) {
		//========================================
		// マッチした数字を取得
		std::smatch match_a, match_b;

		//========================================
		// マッチした数字を取得(前)
		std::regex_search(a, match_a, re);
		// マッチした数字を取得(後ろ)
		std::regex_search(b, match_b, re);

		//========================================
		// マッチした数字を取得
		std::string numA1 = match_a[1];
		std::string numB1 = match_b[1];
		std::string numA2 = match_a[2];
		std::string numB2 = match_b[2];

		//========================================
		// 数字を比較して並び替え
		if (numA1 != numB1) {
			return numA1 < numB1;
		} else {
			return numA2 < numB2;
		}
		});
	//========================================
	// 並び替えたデータを返す
	return vec;
}

 ///=============================================================================
 ///						MAIN
int main() {
	SetConsoleOutputCP(65001);

	///--------------------------------------------------------------
	///						 変数宣言・初期化
	//========================================
	// 学籍番号の格納配列
	std::vector<std::string> studentNumber;

	///--------------------------------------------------------------
	///							処理
	//========================================
	// ファイル読み込み
	studentNumber = readTxtFile("studentNumbers.txt");

	//========================================
	//並び替え前のデータの表示
	printf("並び替え前\n");
	// ファイル読み込み結果の表示Printfで
	for(int i = 0; i < studentNumber.size(); i++) {
		printf("%s\n", studentNumber[i].c_str());
	}

	//========================================
	// データの並び替え
	studentNumber = sortData(studentNumber);
	//ここからは並び替えたデータの表示
	printf("\n\n並び替え後\n");
	//並び替えたデータの表示
	for(int i = 0; i < studentNumber.size(); i++) {
		printf("%s\n", studentNumber[i].c_str());
	}

	return 0;
}