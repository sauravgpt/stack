#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> &A){
  int n = A.size();
  vector<int> LMAX(n), RMAX(n);

  LMAX[0] = A[0];
  RMAX[n-1] = A[n-1];

  for(int i=1; i<n; i++)
    LMAX[i] = max(LMAX[i-1], A[i]);

  for(int i=n-2; i>=0; i--)
    RMAX[i] = max(RMAX[i+1], A[i]);

  int res = 0;
  for(int i=0; i<n; i++)
    res += min(LMAX[i], RMAX[i]) - A[i];

  return res;
}

int main()
{
  vector<int> V = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << rainWater(V);
}