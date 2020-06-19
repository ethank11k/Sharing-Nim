#include <iostream>
using namespace std;
typedef long long ll;
ll sum, XOR_sum, x, bit, total_num = 1;
	
long long f() {
	if ((sum - XOR_sum) & 1) {
		cout << 0;
		return 0;
	}
	x = (sum - XOR_sum) / 2;
	for (ll i = 0; i < 50; i++) {
		bit = (1LL << i);
		if (x & bit) {
			if (XOR_sum & bit) {
				total_num = 0;
				break;
			}
		}
		else {
			if (XOR_sum & bit)
				total_num *= 2LL;
		}
	}
	if (total_num > 0 && x == 0) total_num -= 2;
	cout << total_num/2;
}
	
int main() {
	cin >> sum >> XOR_sum;
	f();
}