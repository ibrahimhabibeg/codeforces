#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--)
  {
    string s;
    cin >> s;
    bool isEqual = "true";
    for (int i = 1; i < (int) s.size(); i++)
    {
      if(s[i]!=s[i-1]){
        isEqual = false;
        break;
      }
    }
    if(isEqual) cout << "-1\n";
    else cout << s.size() - 1 << "\n";
  }   
}