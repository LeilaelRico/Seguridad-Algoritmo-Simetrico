#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

string key;
string texto_plano;

void obtenerLlave(){
	
	cout << "Ingrese la llave (maximo 16 caracteres): ";
  	cin >> key;

	cout << "Ingrese el texto a cifrar (maximo 100 caracteres): ";
	cin.ignore();
  	getline(cin,texto_plano);
}

template<typename T>
void printElements(T &v)
{
    cout << "Rotacion: ";
    for (const auto &item : v) {
        cout << item << "";
    }
    cout << endl;
}

template<typename T>
int rotateArrayElements(T &v, int dir)
{
    if (dir > 0) {
        rotate(v.rbegin(), v.rbegin() + dir, v.rend());
        return 0;
    } else if (dir < 0) {
        rotate(v.begin(), v.begin() + abs(dir), v.end());
        return 0;
    } else {
        return 1;
    }
}

int main()
{

    obtenerLlave();

    rotateArrayElements(texto_plano, key.length());
    /*array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rotateArrayElements(arr, 3);
    printElements(arr);

    rotateArrayElements(vec, -3);
    printElements(vec);*/

    printElements(texto_plano);

    rotateArrayElements(texto_plano, -key.length());

    printElements(texto_plano);


    exit(EXIT_SUCCESS);
}