#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b;
	map < int, long long > data;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> a >> b;
		data[a] = a * b;
	}
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> a >> b;
		if ( data[a] == b )
			cout << "Thr shopkeeper is honest." << endl;
		else
			cout << b - data[a] << endl;
	}
}