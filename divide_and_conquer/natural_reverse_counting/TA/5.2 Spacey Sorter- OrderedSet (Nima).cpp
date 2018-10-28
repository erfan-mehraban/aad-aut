#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;


// GCC COMPILER ONLY

#define M 1000000007
template <typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
	ordered_set<int> oset;
	int n, a, ans = 0; 
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		oset.insert(a);
		ans = (ans + i - oset.order_of_key(a)) % M;
	}
	cout << ans << endl;
	return 0;
}