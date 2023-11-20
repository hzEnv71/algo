package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
var in *bufio.Scanner=bufio.NewScanner(os.Stdin)
 
func solve() {
	var n, m int
	var s string
	var S = make(map[[2]int]bool)

	in.Scan()
	n,_=strconv.Atoi(in.Text())
	in.Scan()
	m,_=strconv.Atoi(in.Text())
	in.Scan()
	s=in.Text()

	nxt := make([]int, n+1)
	lst := make([]int, n+1)
	for i := 0; i <= n; i++ {
		lst[i] = -1
		nxt[i] = n
	}
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			lst[i+1] = i
		} else {
			lst[i+1] = lst[i]
		}
	}
	for i := n - 1; i >= 0; i-- {
		if s[i] == '1' {
			nxt[i] = i
		} else {
			nxt[i] = nxt[i+1]
		}
	}
	for m > 0 {
		var l, r int
		in.Scan()
		l,_=strconv.Atoi(in.Text())
	    in.Scan()
	    r,_=strconv.Atoi(in.Text())
		l--
		l = nxt[l]
		r = lst[r]
		if l > r {
			l = -1
			r = -1
		}
		S[[2]int{l, r}] = true
		m--
	}

	fmt.Println(len(S))
}

func main() {
	in.Split(bufio.ScanWords)
	var t int
	in.Scan()
	t,_=strconv.Atoi(in.Text())
	for t > 0 {
		solve()
		t--
	}
}


