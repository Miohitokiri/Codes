#include<iostream>
using namespace std;
int main(){
	long long n, r, ans = 1;
	cin >> n >> r;
	for ( int i = n ; i > n - r ; i-- )
		ans *= i;
	cout << ans << endl;
}