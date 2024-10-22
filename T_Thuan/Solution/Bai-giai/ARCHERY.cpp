#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Queries
{
	int t, x, y;
	Queries(){}
	Queries(int _t, int _x, int _y) : t(_t), x(_x), y(_y) {}
}Q[200001];

int n;
set<int> Seg[4000001];

bool intersect(int id1, int id2)
{
	return ((Q[id1].x - Q[id2].x) * (Q[id1].x - Q[id2].x) + (Q[id1].y - Q[id2].y) * (Q[id1].y - Q[id2].y) < Q[id2].y * Q[id2].y);
}

void upd(int node, int l, int r, int ll, int rr, int id, int c)
{
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		if (c == 1)
			Seg[node].insert(id);
		else
			Seg[node].erase(id);
		return;
	}
	int mi = (l + r)/2;
	upd(node * 2, l, mi, ll, rr, id, c);
	upd(node * 2 + 1 , mi + 1, r, ll, rr, id, c);
}

int query(int node, int l, int r, int pos, int id)
{
	int ans = -1;
	for (int c : Seg[node])
		if (intersect(id, c))	
		{
			ans = c;
			break;
		}
	if (l == r)
		return ans;
	int mi = (l + r)/2;
	int tmp = -1;
	if (pos <= mi)
		tmp = query(node * 2, l, mi, pos, id);
	else
		tmp = query(node * 2 + 1, mi + 1, r, pos, id);
	if (ans == -1) ans = tmp;
	return ans;			
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	// Compress the x value
	vector<int> val_x;
	for (int i = 1; i <= n; i++)
	{
		cin >> Q[i].t >> Q[i].x >> Q[i].y;
		if (Q[i].t == 1)
		{
			val_x.push_back(Q[i].x - Q[i].y);
			val_x.push_back(Q[i].x + Q[i].y);			
		}
		else
			val_x.push_back(Q[i].x);
	}	
	sort(val_x.begin(), val_x.end());
	for (int i = 1; i <= n; i++)
	{
		if (Q[i].t == 1)
		{
			int l = lower_bound(val_x.begin(), val_x.end(), Q[i].x - Q[i].y) - val_x.begin() + 1;
			int r = lower_bound(val_x.begin(), val_x.end(), Q[i].x + Q[i].y) - val_x.begin() + 1;
			upd(1, 1, val_x.size(), l, r, i, 1);
		}
		else
		{
			int pos = lower_bound(val_x.begin(), val_x.end(), Q[i].x) - val_x.begin() + 1;
			int id = query(1, 1, val_x.size(), pos, i);
			cout << id << '\n';
			if (id != -1)
			{
				int l = lower_bound(val_x.begin(), val_x.end(), Q[id].x - Q[id].y) - val_x.begin() + 1;
				int r = lower_bound(val_x.begin(), val_x.end(), Q[id].x + Q[id].y) - val_x.begin() + 1;
				upd(1, 1, val_x.size(), l, r, id, -1);	
			}
		}
	}
}