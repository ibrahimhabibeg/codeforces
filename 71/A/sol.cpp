#include <bits/stdc++.h>
using namespace std;
int main(){
  int  n;
  cin >> n;
  string word;
  while (n--)
  {
    cin >> word;
    if (word.length()<=10)
      cout << word << "\n";
    else
      cout<< word.at(0) << word.length()-2  << word.at(word.length()-1) << "\n";
  }
   
}