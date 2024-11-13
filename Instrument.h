/*********************************************************************
 * \file   Instrument.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   November 2024
 * \note   
 *********************************************************************/
#pragma once
#include <stdio.h>

 ///=============================================================================
 ///						クラス定義
class Instrument {
public:
    ///--------------------------------------------------------------
	///						 メンバ関数
	
    ///--------------------------------------------------------------
	///						 音を鳴らす
    virtual void playSound() {
        printf("ギターの音だ！じゃじゃーん！\n");

    };
    virtual ~Instrument() = default;
};

