#include <iostream>
using namespace std;
typedef long long ll;
ll x, Q, S, bit, temp_total, total_num = 0;

ll f(ll XOR_sum,ll sum) {
	temp_total = 1;
	if ((sum - XOR_sum) & 1) {
		return 0;
	}
	x = (sum - XOR_sum) / 2;
	for (ll i = 0; i < 50; i++) {
		bit = (1LL << i);
		if (x & bit) {
			if (XOR_sum & bit) {
				temp_total = 0;
				break;
			}
		}
		else {
			if (XOR_sum & bit)
				temp_total *= 2LL;
		}
	}
	if (temp_total > 0 && x == 0) temp_total -= 2;
	total_num += temp_total;
}


int main() {
	cin >> Q;
	for(ll i=1;i<=Q;i++) {
		for(ll j=1;j<=i;j++) {
			f(j,i-j);
		}
	}
	cout << total_num/6;
}