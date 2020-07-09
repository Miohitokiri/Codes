/************************************/
/* Date		: 2020-07-09 13:48:37	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

// by. MiohitoKiri5474
#include"1A2B.h"

inline void init ( int n ){
	ans.clear(), input.clear(), lib.clear();
	ans.resize ( n ), input.resize ( n );
	for ( int i = 1 ; i <= 9 ; i++ )
		lib.pb ( i );
}

inline void setUpNumbers ( int n ){
	for ( int i = 0 ; i < n ; i++ ){
		int idx = rand() % lib.size();
		ans[i] = lib[idx];
		lib.erase ( lib.begin() + idx );
	}
}

inline void printAns ( void ){
	for ( auto i: ans )
		cout << i;
	cout << '\n';
}

inline void setUp ( void ){
	int n = 100;
	cout << "請輸入位數：";
	while ( true ){
		cin >> n;
		if ( n == 5474 || ( 0 < n && n <= 9 ) )
			break;
		cout << "錯誤，請重新輸入：";
	}
	if ( n == 5474 ){
		test();
		return;
	}
	init ( n );
	setUpNumbers ( n );
	guess ( n );
}

inline void test ( void ){
	string str;
	int n;
	cin >> n >> str;
	init ( n );
	for ( int i = 0 ; i < n ; i++ )
		ans[i] = int ( str[i] - '0' );
	guess ( n );
}

// A -> 都一樣
// B -> 數字一樣位置不同
inline void guess ( int n ){
	int cnt = 0, a, b;
	string str;
	while ( true ){
		a = b = 0;
		cnt++;
		str = "";
		cout << "請輸入數字： ";
		while ( true ){
			bool flag = true;
			cin >> str;
			if ( str == "quit" )
				return;
			string swp = str;
			sort ( swp.begin(), swp.end() );
			swp.erase ( unique ( swp.begin(), swp.end() ), swp.end() );
			for ( auto i: swp )
				if ( !( '1' <= i && i <= '9' ) ){
					flag = false;
					break;
				}
			if ( swp.size() == str.size() && str.size() == n && flag )
				break;
			str = swp;
			cout << "錯誤，請重新輸入：";
		}

		for ( int i = 0 ; i < n ; i++ )
			input[i] = str[i] - '0';

		// a
		for ( int i = 0 ; i < n ; i++ ){
			if ( input[i] == ans[i] ){
				a++;
				input[i] = -1;
			}
		}

		// b
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				input[j] == ans[i] ? b++ : b;

		if ( a == n ){
			cout << "恭喜答對，總共花了 " << cnt << "次\n";
			break;
		}

		cout << str << ": " << a << " A " << b << " B \n";
	}
}

int main(){
	srand ( clock() + time ( NULL ) );
	cout << "規則：\n\tＡ：數字一樣、位置也一樣\n\tＢ：數字一樣、位置不同\n";
	setUp();
}