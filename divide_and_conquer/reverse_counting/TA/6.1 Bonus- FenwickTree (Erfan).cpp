#include <bits/stdc++.h>
#define pb emplace_back
#define sz(x) (int)x.size()
#define rep(i, n) for(int i = 0; i < ((int)(n)); i++)
using namespace std;

ostream& operator<<(ostream &os, const vector<int> &v) {
	for (auto &x: v)
		os << x << ' ';
	return os;
}

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> point;

const int maxn = 1e6 + 11;
const ll mod = 1e9 + 7;
ll a[maxn];
int n, fen[maxn];

void add(int x) {
	for (; x < maxn; x += x & -x)
		fen[x]++;
}

ll query(int x) {
	ll ret = 0;
	for (; x; x ^= x & -x)
		ret += fen[x];
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, n)
		cin >> a[i];
	vector<ll> v(a, a + n);
	sort(v.begin(), v.end());
	v.resize( unique(v.begin(), v.end()) - v.begin() );
	auto get = [&](ll x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; };
	ll ans = 0;
	for (int i = n - 1; ~i; i--) {
		ans = (ans + query(get(a[i]))) % mod;
		add(get(a[i]));
	}
	cout << ans << endl;
}
