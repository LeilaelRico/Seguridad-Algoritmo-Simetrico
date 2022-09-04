#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string original_s=s; // store the input string in a variable as original_s
        next_permutation(s.begin(),s.end());// do permutation and s will be changed if permutation occurs
        if(s==original_s)// if there is no permutation possible original and s will be same
            cout<<"no answer "<<endl;
        else
            cout<<s<<endl;// else print ans

        prev_permutation(s.begin(),s.end());// do permutation and s will be changed if permutation occurs
        if(s==original_s)// if there is no permutation possible original and s will be same
            cout<<s<<endl;
        else
            cout<<"no answer "<<endl;
    }

    
}