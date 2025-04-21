#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i]<= k) a[i] = 1;
    else a[i] = -1;
  }
  vector<int> lSum (n, 0);
  vector<int> rSum (n, 0);
  lSum[0] = a[0];
  rSum[n-1] = a[n-1];
  for(int i = 1; i < n; i++)
    lSum[i] = lSum[i-1] + a[i];
  for(int i = n-2; i >= 0; i--)
    rSum[i] = rSum[i+1] + a[i];
  int minAboveZero = n + 10;
  bool found = false;
  for(int i = 0; i < n; i++){
    if(lSum[i]>= minAboveZero){
      found = true;
      break;
    }
    if(lSum[i] >= 0) minAboveZero = min(minAboveZero, lSum[i]);
  }
  if(found){
    cout << "YES" << endl;
    return;
  }
  minAboveZero = n + 10;
  for(int i = n-1; i >= 0; i--){
    if(rSum[i] >= minAboveZero){
      found = true;
      break;
    }
    if(rSum[i] >= 0) minAboveZero = min(minAboveZero, rSum[i]);
  }
  if(found){
    cout << "YES" << endl;
    return;
  }
  int lFirst = -1;
  int rFirst = -1;
  for(int i = 0; i < n; i++){
    if(lSum[i] >= 0){
      lFirst = i;
      break;
    }
  }
  for(int i = n-1; i >= 0; i--){
    if(rSum[i] >= 0){
      rFirst = i;
      break;
    }
  }
  if(lFirst != -1 && rFirst != -1 && rFirst - lFirst > 1){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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