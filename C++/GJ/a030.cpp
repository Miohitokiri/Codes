#include<iostream>
using namespace std;
int main(){
	long long a, b, ans = 0;
	cin >> a >> b;
	ans += a;
	cout << a;
	if ( a > b ){
		for ( long long i = a - 1; i >= b ; i-- ){
			cout << "+" << i;
			ans += i;
		}
	}
	else{
		for ( long long i = a + 1 ; i <= b ; i++ ){
			cout << "+" << i;
			ans += i;
		}
	}
	cout << "=" << ans << endl;
}