package insert_interval

import (
	"reflect"
	"testing"
)

func TestInsertExample1(t *testing.T) {
	intervals := [][]int{{1, 3}, {6, 9}}
	newInterval := []int{2, 5}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{1, 5}, {6, 9}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertExample2(t *testing.T) {
	intervals := [][]int{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}
	newInterval := []int{4, 8}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{1, 2}, {3, 10}, {12, 16}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertExample3(t *testing.T) {
	var intervals [][]int
	newInterval := []int{5, 7}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{5, 7}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertExample4(t *testing.T) {
	intervals := [][]int{{1, 5}}
	newInterval := []int{2, 3}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{1, 5}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertExample5(t *testing.T) {
	intervals := [][]int{{1, 5}}
	newInterval := []int{2, 7}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{1, 7}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertTest0(t *testing.T) {
	intervals := [][]int{{}}
	newInterval := []int{5, 7}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{5, 7}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestInsertTest1(t *testing.T) {
	intervals := [][]int{{1, 5}}
	newInterval := []int{6, 8}
	ans := insert(intervals, newInterval)
	rightAns := [][]int{{1, 5}, {6, 8}}
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
