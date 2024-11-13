/*********************************************************************
 * \file   Piano.h
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
 ///						 クラス定義
class Piano : public Instrument {
public:
    ///--------------------------------------------------------------
	///						 メンバ関数
    void playSound() const override {
        printf("ピアノの音だ！ぽろろん！\n");
    }
};
