package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func run(_r io.Reader, out io.Writer) {
	in := bufio.NewScanner(_r)
	in.Split(bufio.ScanWords)
	r := func() (x int) {
		in.Scan()
		for _, b := range in.Bytes() {
			x = x*10 + int(b&15)
		}
		return
	}
	n := r()

	g := make([][]int, n+1)
	for i := 1; i < n; i++ {
		x, y := r(), r()
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}
	ans, size := make([]int, n+1), make([]int, n+1)
	var dfs func(int, int, int)
	dfs = func(x, fa, depth int) {
		ans[1] += depth // depth 为 0 到 x 的距离
		size[x] = 1
		for _, y := range g[x] {
			if y != fa {
				dfs(y, x, depth+1)
				size[x] += size[y]
			}
		}
	}
	dfs(1, -1, 0)
	max, i := 0, -1
	var reroot func(int, int)
	reroot = func(x, fa int) {
		for _, y := range g[x] {
			if y != fa {
				ans[y] = ans[x] + len(g) - (size[y] << 1)
				reroot(y, x)
			}
			if ans[y] > max {
				max, i = ans[y], y
			}
		}
	}
	reroot(1, -1)
	fmt.Fprint(out, i)

}
func main() { run(os.Stdin, os.Stdout) }
