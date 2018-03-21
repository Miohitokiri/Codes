#include<bits/stdc++.h>
#include"special.h"

using namespace std;

int s[1048600];
int main(){
	int K = Init();
	int p = ( int ) pow ( 2, K );
	int t = 2;
	s[0] = 0, s[1] = 1;
	for ( int i = 2, j = 1 ; i < p ; i++, j-- ){
		s[i] = s[j] + t;
		if ( j == 0 )
			t = j = i + 1;
	}
	Answer ( s );
}