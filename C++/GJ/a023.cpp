#include<iostream>
using namespace std;
int main(){
	long long n, ans = 1;
	cin >> n;
	while ( n != 1 ){
		ans++;
		if ( n % 2 == 0 )
			n /= 2;
		else{
			n *= 3;
			n++;
		}
	}
	cout << ans << endl;
}