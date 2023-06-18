#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  string l, r;
  cin >> TC;
  while (TC--)
  {
    cin >> l >> r;
    int l_len = l.length(), r_len = r.length(), diff = l_len-r_len, res = 0, i =0, n = max(l_len, r_len);
    while (diff==0 && i<n && r[i]==l[i]) i++;
    if(diff>0) res += l[0]-'0';
    else if(diff<0) res += r[0]-'0';
    else if(i<n) res += abs(r[i]-l[i]);
    if(i<n) res += 9*(n-1-i);
    printf("%d\n", res);
  }   
}