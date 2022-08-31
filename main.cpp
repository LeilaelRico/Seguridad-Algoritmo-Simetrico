/***********************************************************
 *                      ITESM Querétaro                    *
 *                          TC2038                         *
 *          Integración de seguridad informática           *
 *              en redes y sistemas de software            *
 *                       Actividad 2                       *
 *                        01/09/2022                       *
 *                 Ricardo Núñez Alanís A01703259          *
 *           Olivia Araceli Morales Quezada A10707371      *
 *           Cristian Leilael Rico Espinosa A01707023      *
 ***********************************************************/

// CPP program for illustrating
// Columnar Transposition Cipher

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// Llave a usar para transposición
string const key = "LAMB";
map<int,int> keyMap;

void ordenPermuta()
{			
	// Orden de permutación agragado al mapa
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
}

// Encripción
string encriptarMensaje(string msg)
{
	int row,col,j;
	string cipher = "";
	
	// Calcula la columna de la matriz
	col = key.length();
	
	// Calcula el renglón máximo de la matriz
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
				// Se añade el caracter '_'
				matrix[i][j] = '_';	
				j++;
			}
			
			if( isalpha(msg[k]) || msg[k]==' ')
			{
				// Se añade el espacio y alfabeto a la matriz
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
	{
		j=ii->second;
		
		// Obtención del texto cifrado de la columna de la matriz
		for (int i=0; i<row; i++)
		{
			if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
				cipher += matrix[i][j];
		}
	}

	return cipher;
}

// Desencriptar
string desencriptarMensaje(string cipher)
{
	// Calcula el renglón y columna para la matriz de cifrado
	int col = key.length();

	int row = cipher.length()/col;
	char cipherMat[row][col];

	// Añade caracter a la matriz
	for (int j=0,k=0; j<col; j++)
		for (int i=0; i<row; i++)
			cipherMat[i][j] = cipher[k++];

	// Actualiza el orden de la llave para desencriptar
	int index = 0;
	for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
		ii->second = index++;

	/* Arrange the matrix column wise according
	to permutation order by adding into new matrix */
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

	// Mensaje en  matriz
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

// Driver Program
int main(void)
{

	string clave;
	string msg;


	std::cout << "Ingrese el texto a cifrar: ";
  	std::getline (std::cin,msg);


	ordenPermuta();

	string cipher = encriptarMensaje(msg);
	cout << "\nEncrypted Message: " << cipher << endl;
	
	cout << "\nDecrypted Message: " << desencriptarMensaje(cipher) << endl;

	return 0;
}