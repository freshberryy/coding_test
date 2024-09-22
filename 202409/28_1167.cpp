#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
int n, s, e, v, visited[100004], dist[100004], ret;
vector<edge> adj[100004];
void bfs(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = 1;
	while (q.size()) {
		int here = q.front();
		q.pop();
		for (edge there : adj[here]) {
			if (!visited[there.first]) {
				visited[there.first] = 1;
				q.push(there.first);
				dist[there.first] = dist[here] + there.second;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		while (true) {
			cin >> v;
			if (v == -1)break;
			cin >> e;
			adj[s].push_back(edge(v, e));
		}
	}
	bfs(1);
	int mx = 1;
	for (int i = 1; i <= n; i++) {
		if (dist[mx] < dist[i]) mx = i;
	}
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	bfs(mx);
	for (int i = 1; i <= n; i++) {
		ret = max(ret, dist[i]);
	}
	cout << ret;
}