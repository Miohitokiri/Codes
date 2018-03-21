#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	unsigned long long ans = 1;
	cin >> a >> b;
	if ( a > b )
		swap ( a, b );
	for ( int i = a ; i <= b ; i++ )
		ans *= i;
	cout << ans << '\n';
}