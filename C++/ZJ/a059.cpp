#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long a,b,c;
	cin >> a;
	for ( int i = 0 ; i < a ; i++ ){
		cin >> b >> c;
		long long ans = 0;
		for ( int j = b ; j < c ; j++ )
			if ( sqrt ( j ) % 1 == 0 )
				ans += j;
		cout << "Case " << i++ << ": " << ans << endl;
	}
	return 0;
}