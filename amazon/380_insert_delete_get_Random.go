package main

import (
    "math/rand"
    "time"
)

type RandomizedSet struct {
    nums       []int
    valToIndex map[int]int
}

func Constructor() RandomizedSet {
    return RandomizedSet{
        nums:       []int{},
        valToIndex: make(map[int]int),
    }
}

func (this *RandomizedSet) Insert(val int) bool {
    if _, exists := this.valToIndex[val]; exists {
        return false // Value already exists
    }
    this.valToIndex[val] = len(this.nums)
    this.nums = append(this.nums, val)
    return true
}

func (this *RandomizedSet) Remove(val int) bool {
    if _, exists := this.valToIndex[val]; !exists {
        return false // Value does not exist
    }
    index := this.valToIndex[val]
    lastElement := this.nums[len(this.nums)-1]

    this.nums[index] = lastElement                       // Replace the element to remove with the last element
    this.valToIndex[lastElement] = index                 // Update the index of the last element
    this.nums = this.nums[:len(this.nums)-1]             // Remove the last element
    delete(this.valToIndex, val)                         // Remove the value from the map

    return true
}

func (this *RandomizedSet) GetRandom() int {
    rand.Seed(time.Now().UnixNano())
    return this.nums[rand.Intn(len(this.nums))]
}

func main() {
    // Example usage
    obj := Constructor()
    param_1 := obj.Insert(1)
    param_2 := obj.Remove(2)
    param_3 := obj.GetRandom()

    // Print the results to verify
    println(param_1)
    println(param_2)
    println(param_3)
}
