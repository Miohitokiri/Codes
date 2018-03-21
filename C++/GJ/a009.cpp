#include<iostream>
using namespace std;
int main(){
	long long n, ans = 0, stop = 0;
	cin >> n;
	ans += n;
	n /= 11;
	ans -= n;
	ans *= 100;
	cout << ans << endl;
}