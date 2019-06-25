package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf ( "%d", &n )
	ans := 1
	for i := 1 ; i <= n ; i++ {
		ans += i * 2
		ans += 2 * ( i - 2 )
	}

	fmt.Println ( ans )
}