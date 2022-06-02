#pragma once
#include "DatDai.h"
class DatNongNghiep :
    public DatDai
{
    int HSD;
public:
    DatNongNghiep();
    void Nhap();
    void Xuat();
    int GetHSD();
};

