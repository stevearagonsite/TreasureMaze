#include "../../Headers/include/MapCell.h"
#include <iostream>

MapCell::MapCell()
{
    ID = '0';
}

MapCell::~MapCell()
{
}

bool MapCell::IsBlocked()
{
    if (ID == '1'){
        return true;
    }else{
        return false;
    }
}
