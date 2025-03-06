typedef struct {
    int k; 
    int size;
    int capacity;
    int* heap;
} KthLargest;
void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int kthLargestAdd(KthLargest* obj, int val);
void heapifyDown(int* heap, int size, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if(left < size && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < size && heap[right] < heap[smallest]){
        smallest = right;
    if(smallest != idx){
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}
}
void heapifyUp(int* heap, int idx){
    int parent = (idx - 1)/2;
    if(idx > 0 && heap[idx] < heap[parent]){
        swap(&heap[idx], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj -> k = k;
    obj -> size = 0;
    obj -> capacity = k;
    obj -> heap = (int*)malloc(sizeof(int) *k);
    for (int i = 0; i < numsSize; i++){
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        heapifyUp(obj->heap, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
