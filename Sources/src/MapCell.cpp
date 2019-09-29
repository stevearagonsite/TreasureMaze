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
    return false;
}
