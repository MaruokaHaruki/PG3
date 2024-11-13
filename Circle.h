/*********************************************************************
 * \file   Circle.h
 * \brief
 * 
 * \author Harukichimaru
 * \date   November 2024
 * \note   
 *********************************************************************/
#pragma once
 //M_PIのため
#define _USE_MATH_DEFINES
#include <math.h>
#include "IShape.h"
#include <xstring>

class Circle : public IShape {
    ///--------------------------------------------------------------
	///						 メンバ関数
public:
    Circle(float radius) : radius_(radius) {}

    // sizeの実装: 円の面積 = π * 半径^2
    float size() const override {
        return static_cast<float>(M_PI) * radius_ * radius_;
    }

    // Drawの実装
    void Draw() const override {
        printf("半径: %.2f\n", radius_);
    }

    ///--------------------------------------------------------------
    ///						 メンバ変数
private:
    float radius_;
};
