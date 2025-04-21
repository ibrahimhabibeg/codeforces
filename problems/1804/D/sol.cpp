#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, m;
  string s;
  scanf("%d %d", &n, &m);
  int res_mn = 0 , res_mx = 0;
  while (n--)
  {
    cin >> s;
    int mx_11 = 0, len = 0, l = 0;
    for (char c: s){
      if(c=='1') len++, l++;
      else mx_11+=len/2, len = 0;  
    }
    mx_11 += len/2;
    mx_11 = min(mx_11, m/4);
    res_mn += l - mx_11, len = 1;
    int mx_not_11 = 0;
    for (int i = 1; i < m; i++){
      if(s[i]=='1' && s[i-1]=='1') mx_not_11 += len/2, len = 1;
      else len++;
    }
    mx_not_11 += len/2;
    mx_not_11 = min(mx_not_11, m/4);
    res_mx += l - m/4 + mx_not_11;
  }
  printf("%d %d", res_mn, res_mx);   
}