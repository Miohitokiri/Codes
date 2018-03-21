#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n,a;
	while ( cin >> n ){
		long long ans = 0;
		for ( int i = 0 ; i < n ; i++ ){
			cin >> a;
			ans += a;
		}
		ans /= a;
		if ( round ( n ) >= 59 ){
			cout << "no";
		}
		else{
			cout << "yes";
		}
		cout << endl;
	}
	return 0;
}
