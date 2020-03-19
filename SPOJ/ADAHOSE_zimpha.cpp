#include <cstdio>
#include <cassert>
#include <queue>
#include <vector>
#include <utility>

using pii = std::pair<int, int>;

constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int N = 1000 + 10, S = N * N;
constexpr int inf = 1e9;

int dis[S];
int A[N][N], n;

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

int scanint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

struct Compare {
    bool operator()(const pii &a, const pii &b) {
    	return a.first > b.first;
	};
};

int main() {
  n = scanint();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      A[i][j] = scanint();
      assert(0 <= A[i][j] && A[i][j] <= 1000);
    }
  }
  int s = n * n;
  for (int i = 0; i <= s; ++i) dis[i] = inf;
  std::priority_queue<pii, std::vector<pii>, Compare> pq;
  dis[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (dis[now.second] < now.first) continue;
    if (now.second == s) {
      for (int i = 0; i < n; ++i) {
        int cost = now.first + A[i][0];
        int next = i * n;
        if (dis[next] > cost) {
          dis[next] = cost;
          pq.emplace(cost, next);
        }
      }
    } else {
      int x = now.second / n, y = now.second % n;
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        int next = xx * n + yy;
        int cost = A[x][y] + A[xx][yy] + now.first;
        if (dis[next] > cost) {
          dis[next] = cost;
          pq.emplace(cost, next);
        }
      }
    }
  }
  int ret = inf;
  for (int i = 0; i < n; ++i) {
    ret = std::min(ret, dis[i * n + n - 1] + A[i][n - 1]);
  }
  printf("%d\n", ret);
  return 0;
}
