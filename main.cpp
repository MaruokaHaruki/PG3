#include <stdio.h>
#include <Windows.h>

///===================================================================///
/// 							main.cpp
///===================================================================///
///----------------------------------------------------///
/// 					関数の宣言
///----------------------------------------------------///
///====================再帰的な時給を計算する関数====================///
/// NOTE:n時間目の時給を計算する (1時間目は100円、それ以降は「前の時給*2-50円」)
int RecursiveHourlyPay(int n) {
	if (n == 1) {
		return 100; // 最初の1時間目は100円
	} else {
		return RecursiveHourlyPay(n - 1) * 2 - 50; // それ以降は前の時給*2-50円
	}
}

///====================n時間分の通常の時給の総額を計算する関数====================///
int NormalHourlyPay(int n, int hourlyPay) {
	return n * hourlyPay;
}

///====================n時間分の再帰的な時給の総額を計算する関数====================///
int TotalRecursive(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += RecursiveHourlyPay(i);
	}
	return total;
}

///----------------------------------------------------///
/// 				変数の宣言・初期化
///----------------------------------------------------///



///----------------------------------------------------///
///							処理
///----------------------------------------------------///
int main() {
	///====================utf-8に指定====================///
	SetConsoleOutputCP(65001);

	// 働く時間数を入力
	int hours;
	printf("働く時間を入力してください: ");
	scanf_s("%d", &hours);

	// 通常の時給
	int normalHourlyPay = 1072;
	// 通常の時給での総額を計算
	int normalTotal = NormalHourlyPay(hours, normalHourlyPay);
	// 再帰的な時給での総額を計算
	int recursiveTotal = TotalRecursive(hours);

	// 結果を表示
	printf("通常の時給体系で %d 時間働くと: %d 円\n", hours, normalTotal);
	printf("再帰的な時給体系で %d 時間働くと: %d 円\n", hours, recursiveTotal);

	// どちらが得かを判定
	if (normalTotal > recursiveTotal) {
		printf("通常の時給体系の方が得です。\n");
	} else {
		printf("再帰的な時給体系の方が得です。\n");
	}

	return 0;
}
