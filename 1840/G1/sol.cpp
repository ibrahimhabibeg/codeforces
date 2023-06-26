#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  vector<int> a(1e6+5, -1);
  int p, TC = 1, c = 1;
  scanf("%d", &p);
  while (TC<1000&& a[p]==-1){
    a[p] = TC;
    printf("+ 1\n");
    fflush(stdout);
    scanf("%d", &p);
    TC++;
  }
  if(a[p]!=-1) {printf("! %d\n", TC-1); fflush(stdout); return 0;}
  while (a[p]==-1){
    a[p] = TC+c-1;
    printf("+ 1000\n");
    fflush(stdout);
    scanf("%d", &p);
    c++;
  }
  printf("! %d\n", 1000*c-a[p]);
  fflush(stdout);
}