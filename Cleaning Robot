# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# include <queue>
# include <vector>
using namespace std;

int const MAX = 25;
int w, h;
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char grid[MAX][MAX];
int dirtIndx;
int dirtX[11];
int dirtY[11];
int arr[11];
int dist[MAX][MAX][MAX][MAX];
int const INF = 62500;

inline bool ok(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

int solve(int xx, int yy, int gx, int gy) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int> > q;
	visited[xx][yy] = true;
	q.push(make_pair(make_pair(xx, yy), 0));
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int cost = q.front().second;
		q.pop();
		if (curx == gx && cury == gy)
			return cost;
		for (int i = 0; i < 4; ++i) {
			int nx = dx[i] + curx;
			int ny = dy[i] + cury;
			if (ok(nx, ny) && grid[nx][ny] != 'x') {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), cost + 1));
				}
			}
		}
	}
	return INF;
}

int main() {
	freopen("in.text","r",stdin);
	while (scanf("%d%d", &w, &h)) {
		if (w == 0 && h == 0)
			break;
		int sx, sy;
		dirtIndx = 0;
		for (int i = 0; i < h; ++i) {
			scanf("%s", grid[i]);
			for (int j = 0; j < w; ++j)
				if (grid[i][j] == 'o') {
					sx = i;
					sy = j;
				} else if (grid[i][j] == '*') {
					dirtX[dirtIndx] = i;
					dirtY[dirtIndx] = j;
					++dirtIndx;
				}
		}
		for (int i = 0; i < MAX; ++i)
			for (int j = 0; j < MAX; ++j)
				for (int k = 0; k < MAX; ++k)
					for (int l = 0; l < MAX; ++l)
						dist[i][j][k][l] = INF;
		for (int i = 0; i < dirtIndx; ++i)
			dist[sx][sy][dirtX[i]][dirtY[i]] = solve(sx, sy, dirtX[i], dirtY[i]);
		for (int i = 0; i < dirtIndx; ++i)
			for (int j = i; j < dirtIndx; ++j) {
				int xx = dirtX[i];
				int yy = dirtY[i];
				int gx = dirtX[j];
				int gy = dirtY[j];
				dist[xx][yy][gx][gy] = solve(xx, yy, gx, gy);
				dist[gx][gy][xx][yy] = dist[xx][yy][gx][gy];
			}
		for (int i = 0; i < dirtIndx; ++i) arr[i] = i;
		int res = INF;
		do {
			int sum = 0;
			sum += dist[sx][sy][dirtX[arr[0]]][dirtY[arr[0]]];
			for (int i = 1; i < dirtIndx; ++i) {
				int dd = arr[i - 1];
				int gd = arr[i];
				sum += dist[dirtX[dd]][dirtY[dd]][dirtX[gd]][dirtY[gd]];
			}
			res = min(res, sum);
		} while (next_permutation(arr, arr + dirtIndx));
		res >= INF ? puts("-1") : printf("%d\n", res);
	}
	return 0;
}
