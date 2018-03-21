// MST
#include<bits/stdc++.h>
using namespace std;\
struct gra{
	int have, a, b;
};
int main(){
	int n, t, a, b, c;
	cin >> n >> t;
	int data[n][n];
	gra kruskael[t];
	for ( int i = 0 ; i < t ; i++ ){
		cin >> a >> b >> c;
		data[a - 1][b - 1] = c;
		kruskael[i].a = a, kruskael[i].b = b, kruskael[i].have = c;
	}
}