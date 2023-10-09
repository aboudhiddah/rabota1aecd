#pragma once

#define BL_SIZE_DEFAULT 4
#define BL_SIZE_MIN 1

class block{
    public:
        int max_bl_size;
        int bl_end;
        int* bl;
        class block* next;

        block();
        block(int size_of_bl);
};
