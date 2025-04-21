#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &k);
    int l[n+1], r[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    int cnt = 0, sum = 0, res = -1;
    for (int i = 1; i <= n; i++)
    {
      sum+=r[i]-l[i]+1, cnt+=l[i]==r[i];
      if(sum<k) continue;
      if(res==-1) res = 2*i + r[i] - sum + k - min(cnt, sum - k);
      else res = min(res, 2*i + r[i] - sum + k - min(cnt, sum - k));
    }
    printf("%d\n", res);
  }   
}