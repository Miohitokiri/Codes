#include<iostream>
#include<vector>

using namespace std;

#define pb push_back

int main(){
	long long n, in, ans = 0, now = 0;
	cin >> n;
	vector < int > data;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		data.pb ( in );
	}

	sort ( data.begin(), data.end() );
	for ( int i = 0 ; i < n ; i++ ){
		ans += now;
		now += data[i];
	}

	cout << ans << "00\n";
}