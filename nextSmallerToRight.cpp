/*
Next Smaller to Right
or
Next smaller to Right

A = [1, 3, 2, 4]
RES = [-1, 1, 1, 2] 
Brute-Force

for i in range(len(A)):
  for j in range(i+1, len(A)):
    if(A[i] > A[j])
      RES.push_back(A[j]);

i.e. O(n^2)

How to identify question is based on Stack
1. Given Array or List
2. Inner loop depends on Outer one (i.e. j depends on i)
    in Brute-Force then, their may Stack works efficiently
*/

// Efficient Solution

#include <bits/stdc++.h>
using namespace std;

// Efficient Solution

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &A)
{
  vector<int> RES;

  int n = A.size();
  stack<int> S;
  for (int i = n - 1; i >= 0; i--)
  {
    if (S.empty())
      RES.push_back(-1);
    else if (S.top() < A[i])
      RES.push_back(S.top());
    else
    {
      while (!S.empty() && S.top() >= A[i])
        S.pop();

      if (S.empty())
        RES.push_back(-1);
      else
        RES.push_back(S.top());
    }
    S.push(A[i]);
  }
  reverse(RES.begin(), RES.end());
  return RES;
}

int main()
{
  vector<int> A = {1, 3, 2, 4};
  vector<int> res = nextSmallerElement(A);

  for (int i : res)
    cout << i << " ";
}