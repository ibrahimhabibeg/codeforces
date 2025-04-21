#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, c;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &c);
    int a[n], b[n];
    pair<int, int> L[n], R[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) L[i] = make_pair(a[i] + i + 1, i), R[i] = make_pair(a[i] + n - i, i);
    sort(L, L+n);
    sort(R, R+n);
    int cst = 0, l = 0, r = 0, leftTaken = 0, rightTaken = 0;
    vector<bool> taken(n);
    while (true){
      while (l<n&&taken[L[l].second]) l++;
      while (r<n&&taken[R[r].second]) r++;
      int mn = -1;
      bool isLeft = true;
      if(l<n && r<n && R[r].first<L[l].first) mn = R[r].first, isLeft = false;
      else if(l<n && r<n) mn = L[l].first;
      else if(l<n) mn = L[l].first;
      else if(r<n) mn = R[r].first, isLeft = false;
      if(mn==-1 || cst+mn>c)  break;
      cst+=mn;
      if(isLeft) taken[L[l].second] = true, l++, leftTaken++;
      else taken[R[r].second] = true, r++, rightTaken++;
    }
    if(leftTaken>0) {printf("%d\n", leftTaken + rightTaken); continue;}
    for (int i = 0; i < n; i++) b[R[i].second] = i;
    ll sum[n]; sum[0] = R[0].first;
    for (int i = 1; i < n; i++) sum [i] = R[i].first + sum[i-1];
    int res = 0;
    for (int i = 0; i < n; i++){
      if(sum[b[i]]+a[i]+i+1<=c){
        int j  = upper_bound(sum, sum + n, c-(a[i]+i+1)+R[b[i]].first) - sum;
        res = max(res, j);
      }else{
        int j  = upper_bound(sum, sum + n, c-(a[i]+i+1)) - sum;
        if(j>0 || a[i]+i+1<=c) res = max(res, j+1); 
      }
    }
    printf("%d\n", res);
  }   
}