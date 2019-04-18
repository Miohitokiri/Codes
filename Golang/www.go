package main

import (
	"fmt"
)

var dis[100005] int

func Init ( n int ) {
	for i := 0 ; i < n ; i++ {
		dis[i] = i;
	}
}

func find ( n int ) int {
	if dis[n] == n {
		return n;
	}
	dis[n] = find ( dis[n] )
	return dis[n]
}

func Union ( a int, b int ) {
	dis[find ( a )] = find ( b )
}

func same ( a int, b int ) bool {
	return find ( a ) == find ( b )
}

func main() {
	var n, m, q, u, v int
	fmt.Scanf ( "%d %d %d\n", &n, &m, &q )
	Init ( n )
	for i := 0 ; i < m ; i++ {
		fmt.Scanf ( "%d %d\n", &u, &v );
		Union ( u, v );
	}

	for i := 0 ; i < q ; i++ {
		fmt.Scanf ( "%d %d\n", &u, &v )
		if same ( u, v ) {
			fmt.Println ( "Yes" )
		} else {
			fmt.Println ( "No" )
		}
	}
}