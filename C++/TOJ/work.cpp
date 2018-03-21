#include<bits/stdc++.h>

using namespace std;

int main(){
	cout << "19 59" << '\n';
	srand ( clock() );
	for ( int i = 0 ; i < 59 ; i++ )
		cout << rand() % 19 + 1 << ' ' << rand() % 19 + 1 << ' ' << rand() % 100 + 1 << '\n';
}