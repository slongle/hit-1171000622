#include <bits/stdc++.h>

using namespace std;

struct SegmentTree
{
  int cnt[22];
  int tag[(1 << 22) + 5];
  void init()
  {
    memset(cnt, 0, sizeof(cnt));
    memset(tag, 0, sizeof(tag));
  }
  void update(int idx, int l, int r, int x, int dep)
  {
    if (l == r && l == x)
    {
      tag[idx] = tag[idx] ^ 1;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      update(idx << 1, l, mid, x, dep - 1);
    else
      update(idx << 1 | 1, mid + 1, r, x, dep - 1);
    if (tag[idx << 1] == tag[idx << 1 | 1])
    {
      if (tag[idx << 1] != -1)
      {
        cnt[dep]++;
      }
      tag[idx] = tag[idx << 1];
    }
    else
    {
      if (tag[idx] != -1)
      {
        cnt[dep]--;
      }
      tag[idx] = -1;
    }
  }
} T1, T2;

long long ans = 0;
long long bin[22];

int main()
{
  int n, q;
  scanf("%d%d", &n, &q);

  bin[0] = 1;
  for (int i = 1; i <= 20; i++)
  {
    bin[i] = bin[i - 1] << 1;
  }
  T1.init();
  T2.init();

  for (int i = 1; i <= n; i++)
  {
    T1.cnt[i] = bin[n - i];
    T2.cnt[i] = bin[n - i];
  }
  for (int i = 1; i <= q; i++)
  {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1)
    {
      T1.update(1, 1, 1 << n, x, n);
    }
    else
    {
      T2.update(1, 1, 1 << n, x, n);
    }
    long long cntt = 0;
    for (int i = 1; i <= n; i++)
    {
      cntt = cntt + 1LL * bin[n - i] * bin[n - i] - 1LL * T1.cnt[i] * T2.cnt[i];
    }
    ans = cntt * 4 + 1;
    printf("%lld\n", ans);
  }
  return 0;
}
