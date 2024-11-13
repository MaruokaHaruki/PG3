/*********************************************************************
 * \file   Rectangle.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   November 2024
 * \note   
 *********************************************************************/
#pragma once
#include "IShape.h"
#include <xstring>


 // 派生クラス Rectangle
class Rect : public IShape {
    ///--------------------------------------------------------------
	///						 メンバ関数
public:
    Rect(float width, float height) : width_(width), height_(height) {}

    // sizeの実装: 長方形の面積 = 幅 * 高さ
    float size() const override {
        return width_ * height_;
    }

    // Drawの実装
    void Draw() const override {
        printf("幅: %.2f 高さ: %.2f\n", width_, height_);
    }

    ///--------------------------------------------------------------
	///						 メンバ変数
private:
    float width_;
    float height_;
};

