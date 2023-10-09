#pragma once

#include "ex_lin_list.h"
#include <iostream>

ex_lin_list::ex_lin_list(){
    first = new block();
    list_size = 0;
}

ex_lin_list::ex_lin_list(int bl_size){
    first = new block(bl_size);
    list_size = 0;
}

class block* ex_lin_list::find_bl(int& index){
    class block* current_bl = first;
    while (current_bl != nullptr){
        if (current_bl->bl_end > index)
            break;
        index -= current_bl->bl_end;
        current_bl = current_bl->next;
    }

    return current_bl;
};

int ex_lin_list::find_val(int index){
    if (index >= list_size || index < 0){
        std::cout << "find_val is out of list_size" << std::endl;
        return INT_MIN;
    }

    class block* current_bl = find_bl(index);
    return current_bl->bl[index];
}

void ex_lin_list::del_val(int index){
    if (index >= list_size || index < 0){
        std::cout << "del_val is out of list_size" << std::endl;
        return;
    }

    class block* current_bl = find_bl(index);
    for (int i = index; i + 1 < current_bl->bl_end; i++)
        current_bl->bl[i] = current_bl->bl[i + 1];
    current_bl->bl_end--;
}

void ex_lin_list::insert_val(int index, int val){
    if (index > list_size || index < 0){
        std::cout << "insert_val is out of list_size" << std::endl;
        return;
    }

    index--;
    class block* current_bl = find_bl(index);
    index++;

    if (index < current_bl->max_bl_size && index >= current_bl->bl_end){
        current_bl->bl[index] = val;
        current_bl->bl_end++;
        list_size++;
    }
    else{
        class block* new_bl = new block(current_bl->max_bl_size);
        new_bl->next = current_bl->next;
        current_bl->next = new_bl;

        for (int i = index; i < current_bl->bl_end; i++){
            new_bl->bl[new_bl->bl_end] = current_bl->bl[i];
            new_bl->bl_end++;
        }
        current_bl->bl_end -= new_bl->bl_end;

        if (index == current_bl->max_bl_size){
            new_bl->bl[0] = val;
            new_bl->bl_end++;
        }
        else {
            current_bl->bl[index] = val;
            current_bl->bl_end++;
        }
        list_size++;
    }
}

void ex_lin_list::write_out(){
    class block* current_bl = first;
    while (current_bl != nullptr){
        for (int i = 0; i < current_bl->bl_end; i++)
            std::cout << current_bl->bl[i] << " ";
        //std::cout << "| ";
        current_bl = current_bl->next;
    }
}

ex_lin_list::~ex_lin_list(){
    class block* current_bl = first;
    while (current_bl != nullptr){
        class block* mem = current_bl->next;
        delete current_bl;
        current_bl = mem;
    }
}
