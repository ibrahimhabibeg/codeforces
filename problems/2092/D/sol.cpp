#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100 + 10;
int n, a[N], c[3];
string s;
map<char, int> mp;

void solve(){
  scanf("%d", &n);
  cin >> s;
  c[0] = c[1] = c[2] = 0;
  for (int i = 0; i < n; i++) {
    a[i] = mp[s[i]];
    c[a[i]]++;
  }
  if(max({c[0], c[1], c[2]})==n) {
    printf("-1\n");
    return;
  }
  printf("%d\n", 2*n);
  for (int i = n-2; i >= 0; i--) if(a[i]!=a[i+1]) {
    int j = i+1;
    while(c[a[i]]) {
      printf("%d\n", i+1);
      printf("%d\n", i+1);
      j+=2;
      c[a[i]]--;
    }
    while(c[a[i+1]]) {
      printf("%d\n", j-1+1);
      j++;
      printf("%d\n", j-1+1);
      j++;
      c[a[i+1]]--;
    }
  }
}

int main(){
  int TC;
  mp['T'] = 0; mp['I'] = 1; mp['L'] = 2;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}