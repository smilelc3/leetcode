package restore_ip_addresses

import (
	"reflect"
	"sort"
	"testing"
)

func TestRestoreIpAddressesExample1(t *testing.T) {
	s := "25525511135"
	ans := restoreIpAddresses(s)
	sort.Strings(ans)

	rightAns := []string{
		"255.255.11.135",
		"255.255.111.35"}
	sort.Strings(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRestoreIpAddressesExample2(t *testing.T) {
	s := "0000"
	ans := restoreIpAddresses(s)
	sort.Strings(ans)

	rightAns := []string{
		"0.0.0.0"}
	sort.Strings(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRestoreIpAddressesExample3(t *testing.T) {
	s := "1111"
	ans := restoreIpAddresses(s)
	sort.Strings(ans)

	rightAns := []string{
		"1.1.1.1"}
	sort.Strings(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRestoreIpAddressesExample4(t *testing.T) {
	s := "010010"
	ans := restoreIpAddresses(s)
	sort.Strings(ans)

	rightAns := []string{
		"0.10.0.10",
		"0.100.1.0"}
	sort.Strings(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestRestoreIpAddressesTest0(t *testing.T) {
	s := "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
	ans := restoreIpAddresses(s)
	sort.Strings(ans)

	var rightAns []string
	sort.Strings(rightAns)
	if !reflect.DeepEqual(ans, rightAns) {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsLegal8BitMyTest0(t *testing.T) {
	str := []rune("1113")
	ans := isLegal8Bit(str)
	rightAns := false
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}

func TestIsLegal8BitMyTest1(t *testing.T) {
	str := []rune("99")
	ans := isLegal8Bit(str)
	rightAns := true
	if ans != rightAns {
		t.Error("right ans = ", rightAns, ", current ans = ", ans)
	}
}
