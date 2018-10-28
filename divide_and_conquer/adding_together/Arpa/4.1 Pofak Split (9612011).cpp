#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 17;

long long ans(long long a, long long b){
	if(a > b)
		swap(a, b);
	if(a == 1)
		return b - 1;
	long long ret = b / a;
	return ret + ans(b % a, a);
}
int main(){
	ios::sync_with_stdio(0), cin.tie();
	long long a, b;
	cin >> a >> b;
	if(__gcd(a, b) != 1)
		cout << "impossible\n";
	else
		cout << ans(a, b) << '\n';
}