#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e5 + 17;

template<typename T>
struct MOS{
	tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,tree_order_statistics_node_update> os;
	map<T, int> cnt;
	int size(){
		return os.size();
	}
	int order_of_key(const T &x){
		return os.order_of_key({x, 0});
	}
	void insert(const T &x){
		os.insert({x, cnt[x]++});
	}
	void erase(const T &x){
		os.erase({x, --cnt[x]});
	}
};

MOS<long long> s;
int n;
int main(){
	ios::sync_with_stdio(0), cin.tie();
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		ans += s.size() - s.order_of_key(x);
		s.insert(x);
	}
	cout << ans % 1000000007 << '\n';
}
