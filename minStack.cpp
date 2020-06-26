#include <bits/stdc++.h>
using namespace std;

class MinStack
{
  stack<int> S;
  int minEle;

public:
  void Push(int n)
  {
    if (S.empty())
    {
      S.push(n);
      minEle = n;
    }
    else if (n < minEle)
    {
      S.push(2 * n - minEle);
      minEle = n;
    }
    else
      S.push(n);
  }

  void Pop()
  {
    if (S.top() < minEle)
      minEle = 2 * minEle - S.top();

    S.pop();
  }

  int GetMin()
  {
    return minEle;
  }

  int Top()
  {
    if (S.top() > minEle)
      return S.top();

    return minEle;
  }
};

int main()
{
  MinStack S;
  do
  {
    cout << "1. Push\t2. Pop\t3. Top\t4. Minimum Element\t0. Exit\n";
    cout << "Your choice: ";
    int ch;
    cin >> ch;
    int ele;
    switch (ch)
    {
    case 1:
      cout << "Element: ";
      cin >> ele;
      S.Push(ele);
      break;

    case 2:
      S.Pop();
      break;

    case 3:
      cout << S.Top() << "\n";
      break;

    case 4:
      cout << S.GetMin() << "\n";
      break;

    case 0:
      exit(1);

    default:
      cout << "Wrong choice\n";
      break;
    }

  } while (1);
}