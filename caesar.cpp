#include <iostream>
using namespace std;
  
// This function receives text and shift and
// returns the encrypted text
string encrypt_caesar(string text, int s)
{
    string result = "";
  
    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
        {
            result += char(int(text[i]+s-65)%26 +65);
        }
        else if (text[i]==' ') {
            result += char(int(text[i]));
        }
  
    // Encrypt Lowercase letters
        else{
            result += char(int(text[i]+s-97)%26 +97);
        }
    }
  
    // Return the resulting string
    return result;
}


string decrypt_caesar(string text, int s)
{
    string result = "";
  
    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
        {
            result += char(int(text[i]-s-65)%26 +65);
        }
        else if (text[i]==' ') {
            result += char(int(text[i]));
        }
  
    // Encrypt Lowercase letters
        else{
            result += char(int(text[i]-s-97)%26 +97);
        }
    }
  
    // Return the resulting string
    return result;
}
  


  
// Driver program to test the above function
int main()
{
    string text="]_jl`kidhqa ]la_do ikk  kk]_iko[idok]_kk] lk ohi^inoj aq";
    int s = 4;
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << decrypt_caesar(text, s);
    return 0;
}