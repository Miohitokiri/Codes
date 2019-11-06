package main

import (
	"fmt"
)

type pii struct{
	first int
	second int
}

func _plus ( a pii, b pii ) pii{
	a.first += b.first
	a.second += b.second
	return a
}

func main() {
	var n, x, y int
	var data, lib [1000]pii
	pt := make ( map[pii]int )
	fmt.Scanf ( "%d\n", &n )
	for i := 0 ; i < n ; i++ {
		fmt.Scanf ( "%d %d\n", &x, &y )
		data[i] = pii { x, y}
	}
	for i := 0 ; i < n ; i++ {
		fmt.Scanf ( "%d %d\n", &x, &y )
		lib[i] = pii { x, y }
	}

	for i := 0 ; i < n ; i++ {
		for j := 0 ; j < n ; j++ {
			pt[_plus ( data[i], lib[j] )]++
		}
	}

	for i, j := range pt {
		if ( j == n ){
			fmt.Println ( i.first, i.second )
			break;
		}
	}
        fmt.Println()
}