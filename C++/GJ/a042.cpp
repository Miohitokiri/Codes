#include<iostream>
using namespace std;
int main(){
	long long n, ans = 1;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		ans *= 13;
		ans %= 100;
	}
	ans /= 10;
	cout << ans << endl;
}