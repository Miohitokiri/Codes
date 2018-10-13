#include<iostream>
#include<vector>
#include<cmath>

#define pb push_back

using namespace std;

inline int change ( string a ){
	int res = 0;
	for ( int i = 0 ; i < a.size() ; i++ ){
		res *= 10;
		res += ( int ) ( a[i] - '0' );
	}

	return res;
}

int main(){
	string a, b, swp = "";
	vector < int > A, B;
	cin >> a >> b;
	int n = a.size() % 5;
	for ( int i = 0 ; i < n ; i++ ){
		swp += a[i];
	}
	if ( n )
		A.pb ( change ( swp ) );
	swp = "";
	for ( int i = n ; i < a.size() ; i++ ){
		swp += a[i];
		if ( swp.size() == 5 ){
			A.pb ( change ( swp ) );
			swp = "";
		}
	}
	reverse ( A.begin(), A.end() );

	swp = "";
	n = b.size() % 5;
	for ( int i = 0 ; i < n ; i++ ){
		swp += b[i];
	}
	if ( n )
		B.pb ( change ( swp ) );
	swp = "";
	for ( int i = n ; i < b.size() ; i++ ){
		swp += b[i];
		if ( swp.size() == 5 ){
			B.pb ( change ( swp ) );
			swp = "";
		}
	}
	if ( swp != "" )
		B.pb ( change ( swp ) );
	reverse ( B.begin(), B.end() );
	if ( A.size() < B.size() )
		swap ( A, B );

	for ( int i = 0 ; i < B.size() ; i++ )
		A[i] += B[i];
	for ( int i = 0 ; i < A.size() - 1 ; i++ ){
		if ( A[i] >= 100000 ){
			A[i + 1] += A[i] / 100000;
			A[i] %= 100000;
		}
	}

	reverse ( A.begin(), A.end() );
	cout << A[0];
	for ( int i = 1 ; i < A.size() ; i++ ){
		if ( A[i] == 0 ){
			cout << "00000";
			continue;
		}
		double stp = log10 ( A[i] );
		int swp = log10 ( A[i] );
		int start = 5 - swp - ( stp != swp );
		for ( int j = 0 ; j < start ; j++ )
			cout << 0;
		cout << A[i];
	}
	cout << '\n';
}