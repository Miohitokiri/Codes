#include<iostream>
#include<string>
using namespace std;
int main(){
	string a, ans = "|____", stop;
	cin >> a;
	if ( a != "1" ){
		for ( int i = a.size() - 1 ; stop.size() < 4 ; i-- )
			stop += a[i];
		long long data = 4;
		data -= stop.size();
		for ( int i = 0 ; i < data ; i++ )
			ans += "_";
		for ( int i = stop.size() - 1 ; i >= 0 ; i-- )
			ans += stop[i];
		cout << ans << "|\n";
	}
	else
		cout << "|_______1|\n";
}