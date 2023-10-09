#pragma once

#include "block.h"

class ex_lin_list{
    private:
        int list_size;
        class block* first;

        class block* find_bl(int& index);
    public:
        ex_lin_list();
        ex_lin_list(int bl_size);
        int find_val(int index);
        void del_val(int index);
        void insert_val(int index, int val);
        void write_out();
        ~ex_lin_list();
};
