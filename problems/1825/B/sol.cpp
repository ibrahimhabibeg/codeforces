#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, v;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    if(n>m) swap(n,m);
    int sm1, sm2;
    scanf("%d %d", &sm1, &sm2);
    if(sm1 > sm2) swap(sm1, sm2);
    int lg1 = sm2, lg2 = sm1;
    for (int i = 0; i < n*m - 2; i++)
    {
      scanf("%d", &v);
      if(v>lg1) {lg2 = lg1; lg1 = v;}
      else lg2 = max(lg2, v);
      if(v<sm1){sm2 = sm1; sm1 = v;}
      else sm2 = min(sm2, v);
    }
    ll res = max(lg1 * 1ll * (n*m-1) - sm1 * 1LL * (m*n - n) - sm2 * 1LL * (n-1), -sm1 * 1ll * (n*m-1) + lg1 * 1LL * (m*n - n) + lg2 * 1LL * (n-1));
    cout << res << "\n";
  }   
}