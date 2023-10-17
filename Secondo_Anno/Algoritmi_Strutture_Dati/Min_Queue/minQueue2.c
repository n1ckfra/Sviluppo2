#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>

//priority queue max lenght
#define MAX_LENGTH 1000

//min-heap node
typedef struct my_node{
    int key;
    int value;
    int pos;
} node;


//min-heap definition
typedef struct my_heap {
    node** my_queue;
    int heap_size;
} min_heap;


//min-heap operations
node* get_node(int key, int val, int pos);
min_heap get_empty_hep();
min_heap build_min_heap(int* values, int* keys, int heap_size);
int parent(int i);
int left(int i);
int right(int i);
void print(min_heap A);
void min_heapify(min_heap* A, int i);

//min priority-queue operations
int insert(min_heap* A, node* x);
node* minimum(min_heap A);
node* extract_min(min_heap* A);
void decrease_key(min_heap* A, node* x, int k);


int main() {

    int num_items = 6;
    int values[10] = {1, 2, 3, 4, 5, 6};
    int keys[10] = {26, 42, 19, 10, 31, 4};


    /*
    //min-heap building
    min_heap my_min_heap = build_min_heap(values, keys, heap_size);
    //print min-heap
    print(my_min_heap);


    //repeated extractions
    node* min;
    for (int i=0; i<10; i++){
        min = extract_min(&my_min_heap);
        if (min!=NULL){
            printf("The object with highest priority contains the value %d\n", min->value);
            printf("Heap after extraction:\n");
            print(my_min_heap);
        }
        else
            printf("ERROR: You can not extract from an empty heap\n");
        //print min-heap
    }
     */


    min_heap my_min_heap = get_empty_hep();
    node *new_node = get_node(keys[0], values[0], 0);
    int errore = insert(&my_min_heap, new_node);
    int i = 1;
    while (i < num_items && !errore) {
        print(my_min_heap);
        new_node = get_node(keys[i], values[i], 0);
        errore = insert(&my_min_heap, new_node);
        i++;
    }
    print(my_min_heap);

}

node* get_node(int key, int val, int pos){
    node* new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->value = val;
    new_node->pos = pos;
    return new_node;
}


int parent(int i){
    return (int)(i/2);
}

int left(int i){
    return 2*i;
}

int right(int i){
    return (2*i) + 1;
}

min_heap get_empty_hep(){
    min_heap my_min_heap;
    my_min_heap.my_queue = (node **)malloc(sizeof(node*)*MAX_LENGTH);
    my_min_heap.heap_size=0;
    return my_min_heap;
}

min_heap build_min_heap(int* values, int* keys, int heap_size){
    min_heap my_heap;
    my_heap.my_queue = (node **)malloc(sizeof(node*)*MAX_LENGTH);
    for (int i=0; i<heap_size; i++){
        node* my_node = (node *)malloc(sizeof(node));
        my_node->value=values[i];
        my_node->key = keys[i];
        my_node->pos = i + 1;
        my_heap.my_queue[i+1] = my_node;
    }
    my_heap.heap_size = heap_size;
    return my_heap;
}

void print(min_heap A){
    printf("\n min-heap size:%d \n mean-heap key & value:\n", A.heap_size);
    for (int i=1; i<A.heap_size+1; i++){
        printf("key: %d, value:%d\n",A.my_queue[i]->key, A.my_queue[i]->value);
    }
    printf("\n");
}

void min_heapify(min_heap* A, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l <= A->heap_size && A->my_queue[l]->key < A->my_queue[i]->key) {
        smallest = l;
    }

    if (r <= A->heap_size && A->my_queue[r]->key < A->my_queue[smallest]->key) {
        smallest = r;
    }

    if (smallest != i) {
        // Swap nodes
        node* temp = A->my_queue[i];
        A->my_queue[i] = A->my_queue[smallest];
        A->my_queue[smallest] = temp;

        // Update positions
        A->my_queue[i]->pos = i;
        A->my_queue[smallest]->pos = smallest;

        min_heapify(A, smallest);
    }
}

node* minimum(min_heap A) {
    if (A.heap_size < 1) {
        return NULL; // Error, the heap is empty
    }
    return A.my_queue[1]; // The heap root
}

node* extract_min(min_heap* A) {
    node* min = minimum(*A);
    if (min != NULL) {
        A->my_queue[1] = A->my_queue[A->heap_size];
        A->heap_size -= 1;
        min_heapify(A, 1);
    }
    return min;
}

void decrease_key(min_heap* A, node* x, int k) {
    if (k >= x->key) {
        printf("ERROR: The new key is higher than the current key\n");
    } else {
        x->key = k;
        int i = x->pos;
        while (i > 1 && A->my_queue[parent(i)]->key > A->my_queue[i]->key) {
            // Swap nodes
            node* temp = A->my_queue[i];
            A->my_queue[i] = A->my_queue[parent(i)];
            A->my_queue[parent(i)] = temp;

            // Update positions
            A->my_queue[i]->pos = i;
            A->my_queue[parent(i)]->pos = parent(i);

            i = parent(i);
        }
    }
}

int insert(min_heap* A, node* x) {
    if (A->heap_size == MAX_LENGTH) {
        // ERROR: Heap overflow
        return 1;
    } else {
        A->heap_size = A->heap_size + 1;
        int k = x->key;
        x->pos = A->heap_size;
        x->key = INT_MAX;
        A->my_queue[A->heap_size] = x;
        decrease_key(A, x, k);
    }
    return 0;
}