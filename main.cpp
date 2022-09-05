/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Integración de seguridad informática           *
 *              en redes y sistemas de software            *
 *                       Actividad 2                       *
 *                        05/09/2022                       *
 *                 Ricardo Núñez Alanís A01703259          *
 *           Olivia Araceli Morales Quezada A10707371      *
 *           Cristian Leilael Rico Espinosa A01707023      *
 ***********************************************************/

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

string key;
string texto_plano;

map<int,int> keyMap;

void obtenerLlave(){

	cout << "\n\n*****----------**********----------**********----------**********----------*****" << endl;	
	cout << "Ingrese la llave (maximo 16 caracteres): ";
  	cin >> key;

	cout << "Ingrese el texto a cifrar (maximo 100 caracteres): ";
	cin.ignore();
  	getline(cin,texto_plano);
	cout << "*****----------**********----------**********----------**********----------*****" << endl;	

}


void ordenPermuta()
{			
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
}

string encriptarMensaje(string msg)
{
	ordenPermuta(); 
	
	int row,col,j;
	string cipher = "";
	
	col = key.length();
	
	row = msg.length()/col;
	
	if (msg.length() % col)
		row += 1;

	char matrix[row][col];

	for (int i=0,k=0; i < row; i++)
	{
		for (int j=0; j<col; )
		{
			if(msg[k] == '\0')
			{
				matrix[i][j] = ' ';	
				j++;
			}
			
			if( isalpha(msg[k]) || msg[k]==' ')
			{
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
	{
		j=ii->second;
		
		for (int i=0; i<row; i++)
		{
			if( isalpha(matrix[i][j]) || matrix[i][j]==' ')
				cipher += matrix[i][j];
		}
	}

	return cipher;
}

string desencriptarMensaje(string cipher)
{
	int col = key.length();

	int row = cipher.length()/col;
	char cipherMat[row][col];

	for (int j=0,k=0; j<col; j++)
		for (int i=0; i<row; i++)
			cipherMat[i][j] = cipher[k++];

	int index = 0;
	for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
		ii->second = index++;

	char decCipher[row][col];
	map<int,int>::iterator ii=keyMap.begin();
	int k = 0;
	for (int l=0,j; key[l]!='\0'; k++)
	{
		j = keyMap[key[l++]];
		for (int i=0; i<row; i++)
		{
			decCipher[i][k]=cipherMat[i][j];
		}
	}

	string msg = "";
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(decCipher[i][j] != '_')
				msg += decCipher[i][j];
		}
	}
	return msg;
}



string encrypt_caesar(string cipher, int s)
{
    string result = "";
  
    for (int i=0;i<cipher.length();i++)
    {
        if (isupper(cipher[i]))
        {
            result += char(int(cipher[i]+s-65)%26 +65);
        }
        else if (cipher[i]==' ') {
            result += char(int(cipher[i]));
        }
  
        else{
            result += char(int(cipher[i]+s-97)%26 +97);
        }
    }
  
    return result;
}


string decrypt_caesar(string cipher, int s)
{
    string result = "";
  
    for (int i=0;i<cipher.length();i++)
    {
        if (isupper(cipher[i]))
        {
            result += char(int(cipher[i]-s-65)%26 +65);
        }
        else if (cipher[i]==' ') {
            result += char(int(cipher[i]));
        }
  
        else{
            result += char(int(cipher[i]-s-97)%26 +97);
        }
    }
  
    return result;
}


 void str2char(string s){
 
     int n = s.length();
 
     char char_array[n + 1];
 
     strcpy(char_array, s.c_str());
 
     for (int i = 0; i < n; i++)
         cout << char_array[i];
 
 }

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}


template<typename T>
void printElements(T &v)
{
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


int main(void)
{

	obtenerLlave();
	int s = 3;
	ordenPermuta();

	cout << "\n\n========================================= ENCRIPTADO =========================================" << endl;

	string cipher = encriptarMensaje(texto_plano);
	cout << "\tTranspuesta Encriptada: " << cipher << endl;
	
	string cipher2 = encrypt_caesar(cipher, s);
	cout << "\t\tCaesar Encriptado: " << cipher2 << endl;
	
	cout << "\t\t\tRotacion Encriptado: ";
	rotateArrayElements(cipher2, key.length());
	printElements(cipher2);

	string cipher3 = cipher2;
	
	int n = cipher3.length();
	int r = key.length();
	char char_cipher3[n + 1];
	strcpy(char_cipher3, cipher3.c_str());

	cout << "\t\t\t\tSuma: ";
	for (int i = 0; i < n; i++) {
    char_cipher3[i] = char_cipher3[i] + r;
    cout << char_cipher3[i];
	}

	string texto = convertToString(char_cipher3, n);

	cout << "\n\n\n\tString Encriptado Final: " << texto;

	cout << "\n\n========================================= DESENCRIPTADO =========================================";

	cout << "\n\tSuma Reverso: ";
	for (int i = 0; i < n; i++) {
    char_cipher3[i] = char_cipher3[i] - r;
    cout << char_cipher3[i];
	}

	string decipher = convertToString(char_cipher3, n);

	
	cout << "\n\t\tRotacion Desencriptado: ";
	rotateArrayElements(decipher, -key.length());
    printElements(decipher);
	string decipher2 = decipher;

	cout << "\t\t\tCaesar Desencriptado: " << decrypt_caesar(decipher2, s)<< endl;
	string decipher3 =  decrypt_caesar(decipher2, s);
	
	cout << "\t\t\t\tTranspuesta Desencriptada: " << desencriptarMensaje(decipher3) << endl;

	return 0;
}
