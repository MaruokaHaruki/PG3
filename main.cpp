#include <iostream>
#include <list>
#include <cstring>
#include <Windows.h>

///=============================================================================
///						駅名と年代の構造体
struct Station {
    char name[20];
    int year;
};

///=============================================================================
///						名前のリストを表示する
void printStations(const std::list<Station>& stations, int year) {
	//リストの要素を順に表示する
    for(std::list<Station>::const_iterator it = stations.begin(); it != stations.end(); ++it) {
		//指定された年までの駅を表示する
        if(it->year <= year) {
			//駅名の表示
            printf("%s\n", it->name);
        }
    }
}

///=============================================================================
///						メイン
int main() {
	//日本語文字コードをUTF-8に設定
    SetConsoleOutputCP(65001);
	//駅名と年代のリスト
    std::list<Station> stations = {
    {"Shinagawa", 1970}, {"Osaki", 1970}, {"Gotanda", 1970}, {"Meguro", 1970}, {"Ebisu", 1970},
    {"Shibuya", 1970}, {"Harajuku", 1970}, {"Yoyogi", 1970}, {"Shinjuku", 1970}, {"Shin-Okubo", 1970},
    {"Takadanobaba", 1970}, {"Mejiro", 1970}, {"Ikebukuro", 1970}, {"Otsuka", 1970}, {"Sugamo", 1970},
    {"Komagome", 1970}, {"Tabata", 1970}, {"Nishi-Nippori", 1970}, {"Nippori", 1970}, {"Uguisudani", 1970},
    {"Ueno", 1970}, {"Okachimachi", 1970}, {"Akihabara", 1970}, {"Kanda", 1970}, {"Tokyo", 1970},
    {"Yurakucho", 1970}, {"Shimbashi", 1970}, {"Hamamatsucho", 1970}, {"Tamachi", 1970}, {"Takanawa Gateway", 2020}
    };

    printf("1970年の駅名:\n");
    printStations(stations, 1970);

    printf("\n2019年の駅名:\n");
    printStations(stations, 2019);

    printf("\n2022年の駅名:\n");
    printStations(stations, 2022);

    return 0;
}