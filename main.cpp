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
#include <vector>
#include <memory>
#include "IShape.h"
#include "Circle.h"
#include "Rect.h"

 ///=============================================================================
 ///						MAIN
int main() {
	SetConsoleOutputCP(65001);

	///--------------------------------------------------------------
	///						 変数宣言・初期化




	///--------------------------------------------------------------
	///							処理
        // Circle と Rectangle のインスタンスを生成
    IShape* circle = new Circle(5.0f);        // 半径5の円
    IShape* rectangle = new Rect(4.0f, 6.0f); // 幅4, 高さ6の長方形

    // 各インスタンスの size と Draw を呼び出し
    printf("Circle Area: %.2f\n", circle->size());
    circle->Draw();

    printf("Rectangle Area: %.2f\n", rectangle->size());
    rectangle->Draw();

    // メモリ解放
    delete circle;
    delete rectangle;

	return 0;
}