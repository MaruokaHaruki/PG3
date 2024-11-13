/*********************************************************************
 * \file   Guitar.h
 * \brief
 *
 * \author Harukichimaru
 * \date   November 2024
 * \note
 *********************************************************************/
#pragma once
#include "Instrument.h"
#include <stdio.h>

 ///=============================================================================
 /// 						クラス定義
class Guitar : public Instrument {
public:
	///--------------------------------------------------------------
	///						 メンバ関数
	void playSound() const override {
		printf("ギターの音だ！じゃじゃーん！\n");
	}
};

