#include<bis/stdc++.h>
using namespace std;
int main(){
	int type, num;
	multiset < int > s;
	multiset < int > :: iterator sit;
	multiset < int > :: reverse_interator srit;
	while ( ~scanf ( "%d", &type ) ){
		seitch ( type ){
			case 1:
				scanf ( "%d", &num );
				s.insert ( num );
				break;
			case 2:
				srit = s.rbegin();
				printf ( "%d\n", *srit );
				s,erase ( next ( srit ).base() );
				break;
			case 3:
				sit = s.begin();
				printf ( "%d\n", *sit );
				s.erase ( sit );
				break;
		}
	}
}