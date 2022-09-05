#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>

using namespace std;


void str2char(string s){
 
    int n = s.length();
 
    char char_array[n + 1];
 
    strcpy(char_array, s.c_str());
 
    for (int i = 0; i < n; i++)
        cout << char_array[i];
 
}

void RotArray(char a[], int n,  int k)
{
    char b[n];
    int i;
    
    
    //Moving each element by k positions
    for(i = 0; i < n; i++) {

        b[(i + k) % n] = a[i];
    }
     
     //Display Rotated Array
     
     for(i = 0; i < n; i++) {

        cout << b[i];
     }
}

int main() {

    cout << "Holo" << endl;
    
    string prueba;

    getline(cin, prueba);


    int n = prueba.length();
 
    char char_array[n + 1];
 
    strcpy(char_array, prueba.c_str());
    

    int m = sizeof(char_array);

    RotArray(char_array, m, 10);

}