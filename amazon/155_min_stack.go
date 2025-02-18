package main

type MinStack struct {
    stack []Element
}

type Element struct {
    value int
    min   int
}

func Constructor() MinStack {
    return MinStack{stack: []Element{}}
}

func (this *MinStack) Push(val int) {
    if len(this.stack) == 0 {
        this.stack = append(this.stack, Element{value: val, min: val})
    } else {
        currentMin := this.stack[len(this.stack)-1].min
        if val < currentMin {
            this.stack = append(this.stack, Element{value: val, min: val})
        } else {
            this.stack = append(this.stack, Element{value: val, min: currentMin})
        }
    }
}

func (this *MinStack) Pop() {
    this.stack = this.stack[:len(this.stack)-1]
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1].value
}

func (this *MinStack) GetMin() int {
    return this.stack[len(this.stack)-1].min
}

func main() {
    // Example usage
    obj := Constructor()
    obj.Push(-2)
    obj.Push(0)
    obj.Push(-3)
    println(obj.GetMin()) // Should return -3
    obj.Pop()
    println(obj.Top())    // Should return 0
    println(obj.GetMin()) // Should return -2
}
