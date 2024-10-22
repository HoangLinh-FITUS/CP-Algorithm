#pragma once
#include <vector>
#include <queue>

extern const int INF;
extern const int MOD;

class Segment_Tree {
private:
	const int ID_ROOT = 1;
	const int LIMIT_RANGE_L = 1;

	std::vector <int>  ST, lazy;
	int LIMIT_RANGE_R;

public:
	Segment_Tree() = default;
	Segment_Tree(int n) {
		ST.assign(4 * n + 1, 0);
		lazy.assign(4 * n + 1, 0);
		this->LIMIT_RANGE_R = n;
	}

private:
	void down(int id, int L, int R) {
		int val = lazy[id];
		if (val != 0) {
			ST[id] += (1ll * (R - L + 1) * val) % MOD;
			ST[id] %= MOD;
			if (L != R) {
				(lazy[id << 1] += val) %= MOD;
				(lazy[id << 1 | 1] += val) %= MOD;
			}
			lazy[id] = 0;
		}
	}

	void update(int u, int v, int val, int id, int L, int R) {
		down(id, L, R);
		if (v < L || R < u) return;
		if (u <= L && R <= v) {
			(lazy[id] += val) %= MOD;
			down(id, L, R);
			return;
		}
		int mid = (L + R) >> 1;
		update(u, v, val, id << 1, L, mid);
		update(u, v, val, id << 1 | 1, mid + 1, R);
		ST[id] = ST[id << 1 | 1] + ST[id << 1];
		ST[id] %= MOD;
	}

	int get(int u, int v, int id, int L, int R) {
		down(id, L, R);
		if (v < L || R < u) return 0;
		if (u <= L && R <= v) {
			return ST[id];
		}
		int mid = (L + R) >> 1;
		return (get(u, v, id << 1, L, mid) + get(u, v, id << 1 | 1, mid + 1, R)) % MOD;
	}

public:
	void update(int u, int v, int val) {
		update(u, v, val, ID_ROOT, LIMIT_RANGE_L, LIMIT_RANGE_R);
	}
	int get(int u, int v) {
		return get(u, v, ID_ROOT, LIMIT_RANGE_L, LIMIT_RANGE_R);
	}
};

void bfs(std::vector <int>& par, std::vector <int>& num_order,
	std::vector <std::pair<int, int>>& child_range, const std::vector <std::vector<int>>& graph) {

	int times = 1;
	num_order[1] = times;

	std::queue <int> Qe;

	Qe.push(1);
	while (!Qe.empty()) {
		int vex_u = Qe.front();
		Qe.pop();
		for (auto v : graph[vex_u]) {
			if (num_order[v] == 0) {
				num_order[v] = ++times;
				par[num_order[v]] = num_order[vex_u];
				child_range[num_order[vex_u]].first = std::min(child_range[num_order[vex_u]].first, num_order[v]);
				child_range[num_order[vex_u]].second = std::max(child_range[num_order[vex_u]].second, num_order[v]);
				Qe.push(v);
			}
		}
	}
}

std::vector <int> solve_of_problem(const Input& input) {
	std::vector <std::vector<int>> graph;
	graph.resize(input.n + 1);
	for (int i = 1; i < input.n; i++) {
		int u = input.u[i];
		int v = input.v[i];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// =====================

	std::vector <std::pair<int,int>> child_range(input.n + 1, {INF, -INF});
	std::vector <int> par(input.n + 1, 0), num_order(input.n + 1, 0);
	bfs(par, num_order, child_range, graph);

	// =======================

	Segment_Tree ST(input.n + 1);
	for (int i = 1; i <= input.n; i++) {
		int x = num_order[i];
		ST.update(x, x, input.a[i]);
	}
	
	std::vector <int> output;
	for (int i = 1; i <= input.q; i++) {
		int t = input.t[i];
		int x = input.x[i];

		// =====================
		x = num_order[x];
		int parent_x = par[x];
		int child_range_L = child_range[x].first;
		int child_range_R = child_range[x].second;

		if (t == 1) {
			int ax = ST.get(x, x);
			
			if (parent_x > 0) {
				ST.update(parent_x, parent_x, ax);
			}

			ST.update(child_range_L, child_range_R, ax);
		}
		else {
			int res = 0;
			if (parent_x > 0) {
				res += ST.get(parent_x, parent_x);
				res %= MOD;
			}
			res += ST.get(child_range_L, child_range_R);
			res %= MOD;
			output.push_back(res);
		}
	} 

	return output;
}