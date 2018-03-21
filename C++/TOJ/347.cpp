#include<bits/stdc++.h>
using namespace std;
int main(){
	const char s = 'a' - 'A';
	int n;
	string data;
	cin >> n;
	for ( int times = 0 ; times < n ; times++ ){
		cin >> data;
		for ( int i = 0 ; i < data.size() ; i++ )
			if ( data[i] >= 'A' && data[i] <= 'Z' )
				data[i] += s;
		cout << data << endl;
	}
}