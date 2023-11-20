package main

import (
	_ "cmp"
	"container/heap"
	"container/list"
	"container/ring"
	_ "errors"
	. "fmt"
	_ "os"
	_ "runtime"
	_ "slices"
	"strings"
	"time"
	_ "unsafe"
)

type Item struct {
	name  string
	year  int
	index int
}

// var errs []error
type PriorityQueue []*Item

// Len implements heap.Interface.
func (pq PriorityQueue) Len() int {
	return len(pq)
}

// Less implements heap.Interface.
func (pq PriorityQueue) Less(i int, j int) bool {
	if pq[i].year == pq[j].year {
		return pq[i].name < pq[j].name
	}
	return pq[i].year < pq[j].year
}

// Pop implements heap.Interface.
func (pq *PriorityQueue) Pop() any {
	tmp := (*pq)[len(*pq)-1]
	*pq = (*pq)[0 : len(*pq)-1]
	tmp.index = -1
	return tmp
}

// Push implements heap.Interface.
func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	tmp := x.(*Item)
	tmp.index = n
	*pq = append(*pq, tmp)
}

// Swap implements heap.Interface.
func (pq PriorityQueue) Swap(i int, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PriorityQueue) update(item *Item, name string, year int) {
	item.name = name
	item.year = year
	heap.Fix(pq, item.index)
}

func main() {
	// str := []string{"sdf", "sf", "df", "sdhfjg"}

	// Println(str)
	// Process1(str)
	// Process2(str)
	// Println(NumCPU())

	// var m unsafe.Pointer
	// Println(unsafe.Sizeof(m))
	// var prints []func()
	// for _, v := range []int{1, 2, 3} {
	// 	v := v
	// 	prints = append(prints, func() { Println(v) })
	// }
	// for _, print := range prints {
	// 	print()
	// }
	// type Person struct {
	// 	Name string
	// 	Age  int
	// }
	// people := []Person{
	// 	{"Gopher", 13},
	// 	{"Dlice", 55},
	// 	{"Vera", 24},
	// 	{"Bob", 55},
	// }
	// firstOldest := slices.MaxFunc(people, func(a, b Person) int {
	// 	// return cmp.Compare(a.Age, b.Age)
	// 	return cmp.Compare(b.Name,a.Name)
	// })
	// s:=[]int{1,2,3,432}
	// tmp:=slices.Max(s)
	// Println(tmp,firstOldest.Name)
	// h:=&IntHeap{3,2,5,1}
	// heap.Init(h)
	// heap.Push(h, 4)
	// Printf("minimum: %d\n", (*h)[0])
	// for h.Len() > 0 {
	// 	Println(heap.Pop(h))
	// }
	// Println(h.Len())
	items := map[string]int{
		"banana": 6, "apple": 1, "pear": 4,
	}

	// Create a priority queue, put the items in it, and
	// establish the priority queue (heap) invariants.
	pq := make(PriorityQueue, len(items))
	i := 0
	for value, priority := range items {
		pq[i] = &Item{
			name:  value,
			year:  priority,
			index: i,
		}
		i++
	}
	heap.Init(&pq)

	// Insert a new item and then modify its priority.
	item := &Item{
		name: "orange",
		year: 1,
	}
	heap.Push(&pq, item)
	pq.update(item, item.name, 7)

	// Take the items out; they arrive in decreasing priority order.
	// for pq.Len() > 0 {
	// 	item := heap.Pop(&pq).(*Item)
	// 	Println(item.year, item.name)
	// }
	// Output:
	// 05:orange 04:pear 03:banana 02:apple
	heap.Remove(&pq, 3)
	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		Println(item.year, item.name)
	}

	// nums:=[]int{1,23,3,2}
	// l:=list.New()
	l := new(list.List).Init()
	l.PushBack(1)
	l.PushBack(2)
	// l.Remove(l.Back())
	l.PushFront(3)
	l.PushBack(4)
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.InsertAfter(5, l.Front())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.InsertBefore(6, l.Back())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.MoveToFront(l.Back())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.MoveToBack(l.Front())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.MoveBefore(l.Front(), l.Back())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	l.MoveAfter(l.Back(), l.Front())
	for e := l.Front(); e != nil; e = e.Next() {
		Print(e.Value)
	}
	Println()
	// r:=new(ring.Ring)
	r := ring.New(4)
	for i := 0; i < r.Len(); i++ {
		r.Value = i
		r = r.Next()
	}
	Println(r.Value)
	for j := 0; j < r.Len(); j++ {
		Println(r.Value, r.Value)
		r = r.Next()
	}
	Println(r.Value)
	r.Move(2) //偏移位置
	r.Do(func(p any) {
		Print(p.(int))
	})
	Println()
	s := ring.New(4)
	for i := 0; i < s.Len(); i++ {
		s.Value = i
		s = r.Next()
	}
	rs := r.Link(s)
	rs.Do(func(p any) {
		Print(p.(int))
	})
	Println("================")
	ss := "sdf"
	Println(strings.Clone(ss), strings.Compare(ss, ss+"c"), strings.Count(ss, "s"), strings.IndexFunc(ss, func(r rune) bool { return r == 'd' }), strings.Join([]string{"234", "234", "sdf", "sawe"}, ","), strings.Map(func(r rune) rune { return r + 1 }, "abcd"))
	n, _ := strings.NewReader(ss).Read([]byte{'a', 'a', 'c'})
	n = int(strings.NewReader(ss).Size())
	// err:=strings.NewReader(ss).UnreadByte()

	Println(n, strings.Repeat("as", 5), strings.Trim("  sdf sdf ", " "), strings.Split("asdfsfdfg", "f"), strings.ToUpper("sfds"), strings.TrimLeft("sdfs", "sdd"), strings.TrimPrefix("sdfs", "sdd"), strings.TrimSpace("   sdf dfg    "))

}

func Process1(tasks []string) {
	for _, task := range tasks {
		time.Sleep(1 * time.Second)
		tmp := task
		// 启动协程并发处理任务
		go func() {
			Printf("Worker start process task: %s\n", tmp)
		}()
	}
}
func Process2(tasks []string) {
	for _, task := range tasks {
		tmp := task
		// 启动协程并发处理任务
		go func(t string) {
			Printf("Worker start process task: %s\n", t)
		}(tmp)
	}
}
