#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, a;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    vector<int> mx(k+1, -1), mn(k+1, n);
    for (int i = 0; i < n; i++) 
    scanf("%d", &a), mn[a] = min(mn[a], i), mx[a] = max(mx[a], i);
    int mn2 = mn[k], mx2 = mx[k];
    for (int i = k-1; i >0; i--){
      mn2 = min(mn2, mn[i]), mx2 = max(mx2, mx[i]);
      if(mn[i]<n) mn[i] = mn2;
      if(mx[i]>-1) mx[i] = mx2;
    }
    
    for (int i = 1; i <= k; i++) 
    printf("%d ", 2*max(0, mx[i]-mn[i]+1));
    printf("\n");
  }   
}