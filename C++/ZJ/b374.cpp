#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long data[30000];
	for ( int i = 0 ; i < 30000 ; i++ )
		data[i] = 0;
	for ( int i = 0 ; i < n ; i++ ){
		long long stop;
		cin >> stop;
		stop--;
		data[stop]++;
	}
	long long max, ans;
	for ( int i = 0 ; i < 30000 ; i++ )
		if ( max < data[i] ){
			max = data[i];
			ans = i;
		}
	ans++;
	cout << ans << " " << data[ans - 1] << endl;
}