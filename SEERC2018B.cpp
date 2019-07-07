#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  unsigned long long a, b, c, n;
  cin >> a >> b >> c >> n;
  unsigned long long nn = n >> 1;
  unsigned long long ans = 0;
  if (n & 1)
    ans = nn * (nn + 1);
  else
    ans = ((nn + 1) * nn / 2 - 1) * 2 + n - 2;
  if (a == b && b == c)
  {
    ans /= 2;
    if (ans % 3 == 0)
      ans = ans / 3 * n;
    else
      ans = n / 3 * ans;
  }
  else if (a == b || a == c || b == c)
  {
    ans /= 2;
    ans *= n;
  }
  else
    ans *= n;
  cout << ans << endl;
  return 0;
}
