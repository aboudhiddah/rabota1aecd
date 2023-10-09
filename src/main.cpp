#include <iostream>
#include "ex_lin_list.h"

#include <time.h>
#include <fstream>
#include <string>

using namespace std;

void check(int* arr_1, int n_1, int arr_2, int n_2, int n_array);

int main(){
    class ex_lin_list A;

    int N_TEST = 10000;


    std::ifstream in1;
    string s1 = "tests/fill" + to_string(N_TEST) + ".txt";
    in1.open(s1);
    for (int i = 0; i < N_TEST; i++){
        int a;
        in1 >> a;
        A.insert_val(i, a);
    }

    clock_t startTime, endTime;
    startTime = clock( );
//CODE TEST
//------------------------------------------------
//find test

    std::ifstream in2;
    string s2 = "tests/find" + to_string(N_TEST) + ".txt";
    in2.open(s2);
    for (int i = 0; i < N_TEST; i++) {
        int a;
        in2 >> a;
        A.find_val(a);
    }

//del test
/*
    std::ifstream in2;
    string s2 = "tests/find" + to_string(N_TEST) + ".txt";
    in2.open(s2);
    for (int i = 0; i < N_TEST / 5; i++) {
        int a;
        in2 >> a;
        A.del_val(a);
    }
*/
//insert test
/*
    std::ifstream in2;
    string s2 = "tests/find" + to_string(N_TEST) + ".txt";
    in2.open(s2);
    for (int i = 0; i < N_TEST; i++) {
        int a, b;
        in2 >> a >> b;
        A.insert_val(a, b);
    }
*/
//------------------------------------------------
    endTime = clock( );
    cout << (endTime - startTime);


//GENERATE TESTS
//------------------------------------------------
/*
    std::ofstream out10;
    string s10 = "tests/fill" + to_string(N_TEST) + ".txt";
    out10.open(s10);
    for (int i = 0; i < N_TEST; i++)
        out10 << rand()%1000 << " ";

    std::ofstream out11;
    string s11 = "tests/find" + to_string(N_TEST) + ".txt";
    out11.open(s11);
    for (int i = 0; i < N_TEST; i++)
        out11 << rand()%N_TEST << " ";

    std::ofstream out12;
    string s12 = "tests/del" + to_string(N_TEST) + ".txt";
    out12.open(s12);
    for (int i = 0; i < N_TEST / 5; i++)
        out12 << rand()%(N_TEST / 5) << " ";

    std::ofstream out13;
    string s13 = "tests/insert" + to_string(N_TEST) + ".txt";
    out13.open(s13);
    for (int i = 0; i < N_TEST; i++)
        out13 << rand()%N_TEST << " " << rand()%1000 << " ";
*/
//------------------------------------------------
}

void check(int* arr_1, int n_1, int* arr_2, int n_2, int n_array){
    ex_lin_list A;
    for (int i = 0; i < n_1; i++){
        A.insert_val(i, arr_1[i]);
        A.write_out();
        cout << endl;
    }
    for (int i = 0; i < n_2; i++){
        A.del_val(arr_2[i]);
        A.write_out();
        cout << endl;
    }
}
