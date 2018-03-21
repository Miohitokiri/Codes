#include<bits/stdc++.h>
using namespace std;
int main(){
	string data;
	vector < char > data2;
	long long ans;
	while ( true ){
		ans = 0;
		getline ( cin, data );
		memset ( data2, 0, sizeof ( data2 ) );
		for ( int i = 0 ; i < data.size() ; i++ ){
			if ( data[i] == '1' || data[i] == '2' || data[i] == '3' || data[i] == '4' || data[i] == '5' || data[i] == '6' || data[i] == '7' || data[i] == '8' || data[i] == '9' || data[i] == '0' ){
				i++;
			}
			if ( data[i] == ' ' ){
				ans += atol ( data2 );
				data2 = "";
			}
		}
		printf ( "%d\n", ans );
	}
}