#include <bits/stdc++.h>
using namespace std;

int HistoArea(vector<int> &A)
{
  stack<pair<int, int>> S;
  vector<int> help;
  int n = A.size();
  for (int i = 0; i < n; i++)
  {
    if (S.empty())
      help.push_back(1);
    else
    {

      while (!S.empty() && S.top().first >= A[i])
        S.pop();

      if (S.empty())
        help.push_back(i);

      else
        help.push_back(i - S.top().second);
    }
    S.push({A[i], i});
    // cout << help[i] << " ";
  }
  // cout << "\n";
  while (!S.empty())
    S.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    if (S.empty())
      help[i] = 0;
    else
    {
      while (!S.empty() && S.top().first >= A[i])
        S.pop();

      if (S.empty())
        help[i] += n - i;
      else
        help[i] += S.top().second - i - 1;
    }
    S.push({A[i], i});
  }

  // for (int i : help)
  //   cout << i << " ";

  // cout << "\n";

  int area = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    area = max(area, help[i] * A[i]);
  }
  return area;
  // return 0;
}

int main()
{
  vector<int> A = {1,1,1};
  cout << HistoArea(A);
}