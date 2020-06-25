/*
A: [100, 80, 60, 70, 60, 75, 85]
R: [1, 1, 1, 2, 1, 4, 6]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> &A)
{
  stack<pair<int, int>> S;
  int n = A.size();
  vector<int> res;

  for (int i = 0; i < n; i++)
  {

    while (!S.empty() && S.top().first <= A[i])
      S.pop();

    if (S.empty())
      res.push_back(i+1);
    else
      res.push_back(i - S.top().second);

    S.push({A[i], i});
  }
  return res;
}

int main()
{
  vector<int> A = {100, 80, 60, 70, 60, 75, 85};
  vector<int> res = StockSpan(A);

  for (int i : res)
    cout << i << " ";
}