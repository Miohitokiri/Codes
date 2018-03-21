#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		long long ans = 1;
		for ( int i = 1 ; i <= n ; i++ )
			ans *= i;
		cout << ans << endl;
	}
	return 0;
}