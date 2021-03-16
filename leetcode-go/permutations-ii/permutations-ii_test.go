package permutations_ii

import (
	"reflect"
	"testing"
)

func TestPermuteExample1(t *testing.T) {
	nums := []int{1, 1, 2}
	ans := permuteUnique(nums)
	if len(ans) != 3 {
		t.Error("len(ans)!=3, ans=", ans)
	} else {
		if !reflect.DeepEqual(ans[0], []int{1, 1, 2}) {
			t.Error("ans[0]!=[1,1,2], ans[0]=", ans[0])
		}
		if !reflect.DeepEqual(ans[1], []int{1, 2, 1}) {
			t.Error("ans[1]!=[1,2,1], ans[1]=", ans[1])
		}
		if !reflect.DeepEqual(ans[2], []int{2, 1, 1}) {
			t.Error("ans[2]!=[2,1,1], ans[2]=", ans[2])
		}
	}
}

func TestPermuteExample2(t *testing.T) {
	nums := []int{1, 2, 3}
	ans := permuteUnique(nums)
	if len(ans) != 6 {
		t.Error("len(ans)!=6, ans=", ans)
	} else {
		if !reflect.DeepEqual(ans[0], []int{1, 2, 3}) {
			t.Error("ans[0]!=[1,2,3], ans[0]=", ans[0])
		}
		if !reflect.DeepEqual(ans[1], []int{1, 3, 2}) {
			t.Error("ans[1]!=[1,3,2], ans[1]=", ans[1])
		}
		if !reflect.DeepEqual(ans[2], []int{2, 1, 3}) {
			t.Error("ans[2]!=[2,1,3], ans[2]=", ans[2])
		}
		if !reflect.DeepEqual(ans[3], []int{2, 3, 1}) {
			t.Error("ans[3]!=[2,3,1], ans[3]=", ans[3])
		}
		if !reflect.DeepEqual(ans[4], []int{3, 1, 2}) {
			t.Error("ans[4]!=[3,1,2], ans[4]=", ans[4])
		}
		if !reflect.DeepEqual(ans[5], []int{3, 2, 1}) {
			t.Error("ans[5]!=[3,2,1], ans[5]=", ans[5])
		}
	}
}

func TestPermuteTest0(t *testing.T) {
	nums := []int{2, 2, 1, 1}
	ans := permuteUnique(nums)
	if len(ans) != 6 {
		t.Error("len(ans)!=6, ans=", ans)
	} else {
		if !reflect.DeepEqual(ans[0], []int{1, 1, 2, 2}) {
			t.Error("ans[0]!=[1,1,2,2], ans[0]=", ans[0])
		}
		if !reflect.DeepEqual(ans[1], []int{1, 2, 1, 2}) {
			t.Error("ans[1]!=[1,2,1,2], ans[1]=", ans[1])
		}
		if !reflect.DeepEqual(ans[2], []int{1, 2, 2, 1}) {
			t.Error("ans[2]!=[1,2,2,1], ans[2]=", ans[2])
		}
		if !reflect.DeepEqual(ans[3], []int{2, 1, 1, 2}) {
			t.Error("ans[3]!=[2,1,1,2], ans[3]=", ans[3])
		}
		if !reflect.DeepEqual(ans[4], []int{2, 1, 2, 1}) {
			t.Error("ans[4]!=[3,1,2], ans[4]=", ans[4])
		}
		if !reflect.DeepEqual(ans[5], []int{2, 2, 1, 1}) {
			t.Error("ans[5]!=[3,2,1], ans[5]=", ans[5])
		}
	}
}
