#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  int n;
  string s;
  while (TC--)
  {
    cin >> n >> s;
    int p = 0 , mxP=0, mx=0;
    vector<int> cnt(26), cntP(26);
    for (int i = 0; i < n; i++)
    {
      cnt[s[i]-'a']++;
      mx = max(mx,cnt[s[i]-'a']);
    }
    if(n%2==1 || mx>n/2){
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n/2; i++)
    {
      if(s[i]==s[n-1-i]){
        p++;
        cntP[s[i]-'a']++;
        mxP = max(mxP,cntP[s[i]-'a']);
      }
    }
    cout << (p+1)/2 + max(0,mxP-(p+1)/2) << "\n";
  }   
}