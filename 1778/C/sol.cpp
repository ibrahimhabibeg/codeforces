#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
int n, k;
ll res;

void calcScore(int choosen){
  int l = 0, r = -1;
  ll score = 0;
  while (true)
  {
    l = r+1;
    while (l<n && a[l]!=b[l] && (choosen & (1<<(a[l]-'a'))) == 0) l++;
    if(l>=n) break;
    r = l+1;
    while (r<n && (a[r]==b[r] || (choosen & (1<<(a[r]-'a'))) != 0)) r++;
    score += ((r-l)*1LL*(r-l+1))/2;
  }
  res = max(res, score);
}

void backtrack(int start, int size, int choosen, vector<int> alpha)
{
  if (size == k){ calcScore(choosen); return;}
  for (int i = start; i <= (int)(alpha.size()) - (k - size); i++) backtrack(i+1, size+1, choosen|(1 << alpha[i]), alpha);
}

int main()
{
  int TC;
  cin >> TC;
  while (TC--)
  {
    res = 0;
    cin >> n >> k >> a >> b;
    int seen = 0;
    vector<int> alpha;
    for (char c : a) if ((seen & 1 << (c - 'a')) == 0) { alpha.push_back(c - 'a'); seen |= 1 << (c - 'a'); }
    k = min(k, (int) alpha.size());
    backtrack(0, 0, 0, alpha);
    cout << res << "\n";
  }
}