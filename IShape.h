/*********************************************************************
 * \file   IShape.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   November 2024
 * \note   
 *********************************************************************/
#pragma once
class IShape {
public:
    // 純粋仮想関数 size と Draw
    virtual float size() const = 0;  // 面積を計算する関数
    virtual void Draw() const = 0;    // 描画を行う関数

    // 仮想デストラクタ
    virtual ~IShape() = default;
};

