#include<iostream>
using namespace std;
long long h ( long long y ){
	long long ans;
	if ( y < 2 )
		ans = -1;
	else
		ans = 2 + h ( y - 1 ) - h ( y - 2 );
	return ans;
}
long long g ( long long z ){
	long long ans = 0;
	if ( z <= 2 )
		ans = z * z - 1;
	else
		ans = 2;
	return ans;
}
long long f ( long long x ){
	long long ans = 0;
	long long h_data = h ( x ),g_data = g ( x );
	if ( x > h_data ){
		x--;
		ans += f ( x );
		ans −= h_data;
	}
	else if ( x < h_data ){
		ans += f ( g_data );
		ans −= g_data;
	}
	else
		ans += 1;
	return ans;
}
int main(){
	long long x;
	while ( cin >> x ){
		long long ans = f ( x );
		cout << ans << endl;
	}
	return 0;
}