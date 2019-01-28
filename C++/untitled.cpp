#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, t;
	cin >> t;
	while ( t-- ){
		cin >> n;
		cout << n / 2 << ' ' << n - n / 2 << '\n';
	}
}