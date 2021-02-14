package built_in

type BoolStaComp struct {
	size int
	data []int8
}

// 构造函数
func NewBoolStaComp(size int) *BoolStaComp {
	return new(BoolStaComp).setSize(size)
}

func (receiver *BoolStaComp) setSize(size int) *BoolStaComp {
	if size <= 0 {
		panic("size must > 0")
	}
	receiver.size = size
	//int8sLength := size / 8
	int8sLength := size >> 3
	//if size % 8 != 0 {
	//	int8sLength++
	//}
	if size&0x7 != 0 {
		int8sLength++
	}
	receiver.data = make([]int8, int8sLength, int8sLength)
	return receiver
}

// 指定idx位状态，置true
func (receiver *BoolStaComp) SetState(idx int, state bool) {
	if state == true {
		receiver.SetStateTrue(idx)
	} else {
		receiver.SetStateFalse(idx)
	}
}

// 指定idx位状态，置true
func (receiver *BoolStaComp) SetStateTrue(idx int) {
	//receiver.data[idx/8] |= 1 << (idx % 8)
	receiver.data[idx>>3] |= 1 << (idx & 0x7)
}

// 指定idx位状态，置false
func (receiver *BoolStaComp) SetStateFalse(idx int) {
	//receiver.data[idx/8] &= ^(1 << (idx % 8))
	receiver.data[idx>>3] &= ^(1 << (idx & 0x7))
}

// 指定idx位状态，取反
func (receiver *BoolStaComp) ReverseState(idx int) {
	//receiver.data[idx/8] ^= 1 << (idx % 8)
	receiver.data[idx>>3] ^= 1 << (idx & 0x7)
}

// 获取idx位状态
func (receiver *BoolStaComp) GetState(idx int) bool {
	//return receiver.data[idx/8] >> (idx % 8) & 1 == 1
	return receiver.data[idx>>3]>>(idx&0x7)&1 == 1
}
