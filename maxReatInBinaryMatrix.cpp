/* Maximum Rectangular Area in Binary Matrix
      0, 1, 1, 0
      1, 1, 1, 1
M =   1, 1, 1, 1
      1, 1, 0, 0

Ans = 8
*/

#include <bits/stdc++.h>
#include "MAH.h"
using namespace std;

int MAR(vector<vector<int>> &A)
{
  int n = A.size();
  int m = A[0].size();

  vector<int> vec;

  for (int j = 0; j < m; j++)
  {
    vec.push_back(A[0][j]);
  }

  int mx = MAH(vec);

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      if (A[i][j] == 0)
        vec[j] = 0;
      else
        vec[j] += A[i][j];

    mx = max(mx, MAH(vec));
  }

  return mx;
}

int main()
{

  int n = 4, m = 4;

  vector<vector<int>> V(n, vector<int>(m));

  V = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

  cout << MAR(V);
}