package main

import (
	"fmt"
)

func min ( a int, b int ) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	var y, b, r int
	fmt.Scanf ( "%d %d %d\n", &y, &b, &r )
	b--; r -= 2
	fmt.Println ( min ( min ( y, b ), r ) * 3 + 3 )
}