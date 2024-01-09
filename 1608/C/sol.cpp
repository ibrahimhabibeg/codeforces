#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    pair<int, int> a[n];
    int b[n];
    for (int i = 0; i < n; i++) scanf("%d", &x), a[i] = make_pair(-x, i);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a, a+n);
    int f = 0, mnw = b[a[0].second], mnp = b[a[0].second];
    char res[n+1];
    res[n] = '\0';
    for (int i = 0; i < n; i++) res[i] = '0';
    for (int i = 1; i < n; i++){
      mnp = min(mnp, b[a[i].second]);
      if(b[a[i].second]>mnw) f = i, mnw = min(mnp, mnw);
    } 
    for (int i = 0; i <= f; i++) res[a[i].second] = '1';
    printf("%s\n", res);
  }   
}