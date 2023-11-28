#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//priority queue max lenght
#define MAX_LENGTH 6000

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

void min_heapify(min_heap* A, int i){
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if (l<=A->heap_size && A->my_queue[l]->key<A->my_queue[i]->key)
        smallest = l;
    if (r<=A->heap_size && A->my_queue[r]->key<A->my_queue[smallest]->key)
        smallest = r;
    if (smallest != i){
        //node swapping
        node* node_aux = A->my_queue[i];
        A->my_queue[i] = A->my_queue[smallest];
        A->my_queue[smallest] = node_aux;
        min_heapify(A, smallest);

        //pos swapping
        int aux = A->my_queue[i]->pos;
        A->my_queue[i]->pos = A->my_queue[smallest]->pos;
        A->my_queue[smallest]->pos = aux;
    }
}

node* minimum(min_heap A){
    if (A.heap_size < 1) //the min-heap is empty the result is not defined (i.e. we return MAX_INT)
        return NULL;
    else
        return A.my_queue[1];
}

node* extract_min(min_heap* A) {
    node* min = minimum(*A);
    if (min != NULL) {
        A->my_queue[1] = A->my_queue[A->heap_size];
        A->heap_size--;
        min_heapify(A, 1);
    }
    return min;
}

void decrease_key(min_heap* A, node* x, int k){
    if (k>x->key)
        printf("ERROR:, the new key is higher than the current key");
    else{
        x->key=k;
        int current_pos = x->pos;
        //move x "up" till min-heap condition holds
        while(current_pos>1 && A->my_queue[parent(current_pos)]->key > A->my_queue[current_pos]->key){
            //node swapping
            node* node_aux = A->my_queue[parent(current_pos)];
            A->my_queue[parent(current_pos)] = A->my_queue[current_pos];
            A->my_queue[current_pos] = node_aux;

            //pos swapping
            int int_aux = A->my_queue[parent(current_pos)]->pos;
            A->my_queue[parent(current_pos)]->pos = A->my_queue[current_pos]->pos;
            A->my_queue[current_pos]->pos = int_aux;

            current_pos = parent(current_pos);
        }
    }
}

int insert(min_heap* A, node* x){
    if (A->heap_size == MAX_LENGTH){
        printf("ERRORE: heap overflow");
        return 1;
    }
    else{
        A->heap_size++;
        int k = x->key;
        x->key = INT_MAX;
        A->my_queue[A->heap_size] = x;
        x->pos = A->heap_size;
        decrease_key(A, x, k);
    }
    return 0;
}