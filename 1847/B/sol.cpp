#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int all = a[0];
    for(int i=1; i<n; i++) all&=a[i];
    if(all!=0){
      printf("1\n");
      continue;
    }
    int c = 0, r = 0;
    for (int i = 0; i < n; i++){
      if(r==0) r=a[i];
      else r&=a[i];
      if(r==0) c++;
    }
    printf("%d\n", c);
  }   
}