package edit_distance

import (
	"testing"
)

func TestMinDistanceExample1(t *testing.T) {
	word1 := "horse"
	word2 := "ros"
	ans := minDistance(word1, word2)
	rightAns := 3
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinDistanceExample2(t *testing.T) {
	word1 := "intention"
	word2 := "execution"
	ans := minDistance(word1, word2)
	rightAns := 5
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestMinDistanceTest0(t *testing.T) {
	word1 := "zoologicoarchaeologist"
	word2 := "zoogeologist"
	ans := minDistance(word1, word2)
	rightAns := 10
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
