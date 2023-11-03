#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  string str;
  scanf("%d", &n);
  map<pair<int,int>,ll> mp1, mp2, mp3;
  int c[n], s[n];
  for (int i = 0; i < n; i++){
    cin >> str;
    int sum = 0;
    for (char cr: str)sum+=cr-'0';
    c[i]=str.length(), s[i]= sum;
    mp3[make_pair(str.length(),sum)]++;
    int sz = str.length(), csum = sum;
    for (char cr: str){
      csum-=2*(cr-'0'), sz-=2;
      mp1[make_pair(sz,csum)]++;
    }
    sz = str.length(), csum = sum;
    for (int i = str.length()-1; i>=0; i--)
    {
      char cr = str[i];
      csum-=2*(cr-'0'), sz-=2;
      mp2[make_pair(sz,csum)]++;
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++){
    auto p  = make_pair(c[i],s[i]);
    res+=mp1[p]+mp2[p]+mp3[p];
  }
  printf("%lld\n", res);
}