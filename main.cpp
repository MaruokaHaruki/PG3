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
#include "Math.h"

 ///=============================================================================
 ///						MAIN
int main() {
	SetConsoleOutputCP(65001);

	///--------------------------------------------------------------
	///						 変数宣言・初期化
	// クラステンプレートのインスタンス化
	// int 型に対するインスタンス
	Math<int> intMath;

	// float 型に対するインスタンス
	Math<float> floatMath;

	// double 型に対するインスタンス
	Math<double> doubleMath;



	///--------------------------------------------------------------
	///							処理
	int a = 5;
	int b = 10;

	float c = 5.5f;
	float d = 10.5f;

	double e = 5.55;
	double f = 10.55;

	printf("%d と %d だと %d　のほうが小さい\n", a, b, intMath.Min(a, b));
	printf("%.2f と %.2f だと %.2f　のほうが小さい\n", c, d, floatMath.Min(c, d));
	printf("%.2lf と %.2lf だと %.2lf　のほうが小さい\n", e, f, doubleMath.Min(e, f));

	return 0;
}