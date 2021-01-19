package permutations

import (
	"reflect"
	"testing"
)

func TestPermuteExample1(t *testing.T) {
	nums := []int{1, 2, 3}
	ans := permute(nums)
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

func TestPermuteExample2(t *testing.T) {
	nums := []int{0, 1}
	ans := permute(nums)
	if len(ans) != 2 {
		t.Error("len(ans)!=2, ans=", ans)
	} else {
		if !reflect.DeepEqual(ans[0], []int{0, 1}) {
			t.Error("ans[0]!=[0,1], ans[0]=", ans[0])
		}
		if !reflect.DeepEqual(ans[1], []int{1, 0}) {
			t.Error("ans[1]!=[1,0], ans[1]=", ans[1])
		}
	}
}
