#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n), p(n, -1);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i]==-1) a[i] = n + 1;
  }
  int mn = 1, mx = n, round = 1;
  while(mn<mx) {
    int count = 0;
    for(int i = 0; i < n; i++) if(a[i] == round) count++;
    // Remove count elements
    int rmn, rmx;
    if(round%2){
      rmx = mx;
      rmn = rmx - count + 1;
      mx = rmn - 1;
    } else {
      rmn = mn;
      rmx = rmn + count - 1;
      mn = rmx + 1;
    }
    if(round%2) {
      int i = 0;
      while(i<n && a[i]<=round) {
        if(a[i]==round) {
          p[i] = rmx;
          rmx--;
        }
        i++;
      }
      while(i<n) {
        if(a[i]==round) {
          p[i] = rmn;
          rmn++;
        }
        i++;
      }
    } else {
      int i = 0;
      while(i<n && a[i]<=round) {
        if(a[i]==round) {
          p[i] = rmn;
          rmn++;
        }
        i++;
      }
      while(i<n) {
        if(a[i]==round) {
          p[i] = rmx;
          rmx--;
        }
        i++;
      }
    }
    round++;
  }
  for (int i = 0; i < n; i++) if(p[i] == -1) p[i] = mn;
  for (int i = 0; i < n; i++) cout << p[i] << " ";
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC = 1;
  cin >> TC;
  while(TC--){
    solve();
  }
}