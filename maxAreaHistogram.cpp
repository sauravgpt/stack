#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &A){
  for(int i:A)
    cout << i << " ";

  cout << "\n";
}

int HistoArea(vector<int> &A)
{
  int n = A.size();
  stack<pair<int,int>> S;
  vector<int> res;

  for(int i=0;i<n;i++){
    while(!S.empty() && S.top().first >= A[i])
      S.pop();

    if(S.empty())
      res.push_back(-1);
    else
      res.push_back(S.top().second);

    S.push({A[i], i});
  }

  // printArray(res);

  while(!S.empty())
    S.pop();

  for(int i=n-1; i>=0; i--){
    while(!S.empty() && S.top().first >= A[i])
      S.pop();

    if(!S.empty())
      res[i] = S.top().second - (res[i] + 1);
    else
      res[i] = n - (res[i] + 1);

    S.push({A[i], i});
  }

  // printArray(res);

  int mx = -1;

  for(int i=0; i<n; i++){
    mx= max(mx, A[i] * res[i]);
  }

  return mx;
}

int main()
{
  vector<int> A = {1,1,1};
  cout << HistoArea(A);
}