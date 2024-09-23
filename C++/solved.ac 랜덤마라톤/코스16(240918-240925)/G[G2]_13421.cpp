#include<iostream>
#define X first
#define Y second
#define ll long long
using namespace std;
const ll MAX_VAL = 1e18;
pair<ll, ll> pos[4];
pair<ll, ll> point[4] = { {1,1},{-1,1},{-1,-1},{1,-1} };
pair<ll, ll> ans = { 0,MAX_VAL };
bool vst[4];
int seq[4];


ll cost(ll deg) {
	ll res = 0;
	for (int i = 0; i < 4; i++) {
		int type = seq[i];
		res += abs(pos[i].X - point[type].X * deg) + abs(pos[i].Y - point[type].Y * deg);
	}
	return res;
}

void back_tracking(ll dep, ll deg, ll& v) {
	if (dep == 4) {
		v = min(v, cost(deg));
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (vst[i]) continue;
		vst[i] = 1;
		seq[dep] = i;
		back_tracking(dep + 1, deg, v);
		vst[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 4; i++) cin >> pos[i].X >> pos[i].Y;
	for (int i = 0; i < 4; i++) {
		pos[i].X *= 2;
		pos[i].Y *= 2;
	}
	long long low = 1, high = 2 * 1e9;
	while (high - low > 3) {
		ll lmid = (low * 2 + high) / 3, rmid = (low + high * 2) / 3;
		ll lres = MAX_VAL, rres = MAX_VAL;
		back_tracking(0, lmid, lres);
		back_tracking(0, rmid, rres);
		if (lres < rres) {
			high = rmid;
			if (lres < ans.Y) {
				ans = { lmid,lres };
			}
			else if (lres == ans.Y) {
				ans = { max(ans.X,lmid),lres };
			}
		}
		else {
			low = lmid;
			if (rres < ans.Y) {
				ans = { rmid, rres };
			}
			else if (rres == ans.Y) {
				ans = { max(ans.X,rmid),rres };
			}
		}

	}
	for (ll i = low; i <= high; i++) {
		ll tmp = MAX_VAL;
		back_tracking(0, i, tmp);
		if (tmp < ans.Y) ans = { i,tmp };
		else if (tmp == ans.Y) ans = { max(ans.X,i),tmp };
	}
	cout << ans.X;
}