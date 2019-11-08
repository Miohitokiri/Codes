package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	var n, t, idx int
	var data [105]int

	in := bufio.NewReader ( os.Stdin )

	fmt.Fscan ( in, &t )
	for t > 0 {
		t--
		fmt.Fscan ( in, &n )
		var used [105]bool
		for i := 0 ; i < n ; i++ {
			fmt.Fscan ( in, &data[i] )
		}

		tms := n - 1
		for i := 1 ; tms > 0 && i <= n ; i++ {
			for j := 0 ; j < n ; j++ {
				if data[j] == i {
					idx = j;
					break;
				}
			}

			if idx == i - 1{
				continue
			}

			for idx != i - 1 && !used[idx - 1] && tms > 0 && data[idx] < data[idx - 1] {
				tmp := data[idx]
				data[idx] = data[idx - 1]
				data[idx - 1] = tmp
				used[idx - 1] = true
				idx--
				tms--
			}
		}

		for i := 0 ; i < n ; i++ {
			fmt.Printf ( "%d ", data[i] )
		}

		fmt.Println()
	}
}

	// int t, n, idx, tms;
	// vi data;
	// cin >> t;
	// while ( t-- ){
	// 	cin >> n;
	// 	GETDATA ( data, n );
	// 	MEM ( used, 0 );
	// 	tms = n - 1;
	// 	for ( int i = 1 ; tms && i <= n ; ++i ){
	// 		REPP ( j, 0, n ){
	// 			if ( data[j] == i ){
	// 				idx = j;
	// 				break;
	// 			}
	// 		}

	// 		if ( idx == i - 1 )
	// 			continue;

	// 		while ( idx != i - 1 && !used[idx - 1] && tms && data[idx] < data[idx - 1] ){
	// 			swap ( data[idx], data[idx - 1] );
	// 			// cout << "\t" << idx << ' ' << idx - 1 << '\n';
	// 			used[idx - 1] = true;
	// 			--idx;
	// 			--tms;
	// 		}
	// 	}

	// 	PIO ( data );
	// 	// for ( int i = 0 ; i < n ; i++ ) // del
	// 		// cout << used[i] << ' '; // del
	// 	// cout << '\n'; // del
	// }