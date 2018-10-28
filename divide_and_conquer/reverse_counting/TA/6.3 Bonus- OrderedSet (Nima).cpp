#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;

#define M 1000000007
// َUsing "less_equal" comparator
using ordered_set =  tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	// freopen("input.txt", "r", stdin);
	ordered_set oset;
	long long n, a, ans = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		oset.insert(a);
		ans = (ans + i - oset.order_of_key(a)) % M;
	}
	cout << ans << endl;
	return 0;
}