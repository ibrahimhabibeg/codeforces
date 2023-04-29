#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, v;
  scanf("%d", &n);
  int a[n + 1], b[n + 1];
  for (int i = 0; i < n; i++){ scanf("%d", &v); a[v] = i; }
  for (int i = 0; i < n; i++){ scanf("%d", &v); b[v] = i; }
  ll mn1 = min(a[1], b[1]), mx1 = max(a[1], b[1]);
  ll res = 1 + mn1*(mn1+1)/2 + (n-mx1)*(n-mx1-1)/2 + (mx1-mn1-1)*(mx1-mn1)/2;
  int mnA = a[1], mxA = a[1], mnB = b[1], mxB = b[1];
  for (int i = 2; i <= n; i++)
  {
    if ((a[i] < mnA || a[i] > mxA) && (b[i] < mnB || b[i] > mxB))
    {
      ll mnL = max(a[i] < mnA ? a[i] + 1 : 0, b[i] < mnB ? b[i] + 1 : 0), mxL = min(mnA, mnB);
      ll mnR = max(mxA, mxB), mxR = min(a[i] < mnA ? n - 1 : a[i] - 1, b[i] < mnB ? n - 1 : b[i] - 1);
      if(mnL<=mxL && mnR<=mxR) res += (mxL-mnL+1)*(mxR-mnR+1);
    }
    mnA = min(mnA, a[i]), mxA = max(mxA, a[i]), mnB = min(mnB, b[i]), mxB = max(mxB, b[i]);
  }
  printf("%llu\n", res);
  
}