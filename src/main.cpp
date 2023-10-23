#include <iostream>
#include "ex_lin_list.h"
#include <math.h>

#include <time.h>
#include <fstream>
#include <string>

using namespace std;

void check(int* arr_1, int n_1, int arr_2, int n_2, int n_array);

int main(){
    class ex_lin_list A;

    int n;
    cout << "Write N:\n";
    cin >> n;
    cout << "Write N numbers to fill list:\n";
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        A.insert_val(i, a);
    }
    for (int i = 0; i < n; i++){
        cout << "Write index to del in list:\n";
        int a;
        cin >> a;
        A.del_val(a);
        A.write_out();
        cout << endl;
    }

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
