#include<iostream>
#include<cmath>
using namespace std;
int main(){
	string s;
	while ( cin >> s ){
		long long a, b, ans =0;
		cin >> a >> b;
		if ( s == "mul" )
			ans = a * b;
		else
			ans = pow ( a, b);
		cout << ans << '\n';
	}
}