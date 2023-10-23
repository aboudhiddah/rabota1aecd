#pragma once

#include "block.h"
#include <iostream>

block::block(){
    max_bl_size = BL_SIZE_DEFAULT;
    bl = new int[max_bl_size];
    next = nullptr;

    bl_end = 0;
}

block::block(int size_of_bl){
    if (size_of_bl >= BL_SIZE_MIN)
        max_bl_size = size_of_bl;
    else
        max_bl_size = BL_SIZE_MIN;
    bl = new int[max_bl_size];
    next = nullptr;

    bl_end = 0;
}
