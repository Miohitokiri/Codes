package main

import (
	"fmt"
)

func main() {
	var n int;
	cnt := 0
	fmt.Scanf ( "%d", &n )
	for n % 10 != n {
		cnt++
		n++
		for n % 10 == 0 {
			n /= 10
		}
	}

	cnt += 9;

	fmt.Println ( cnt )
}