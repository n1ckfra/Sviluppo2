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
} node;

//min-heap definition
typedef struct my_heap {
    node* my_queue[MAX_LENGTH];
    int heap_size;
} min_heap;

//values with status
typedef struct value{
    const char* status;
    int value;
} my_value;


//min-heap operations
min_heap get_empty_hep();
min_heap build_min_heap(int* values, int* keys, int heap_size);
int parent(int i);
int left(int i);
int right(int i);
void print(min_heap A);
void min_heapify(min_heap* A, int i);

//min priority-queue operations
void insert(min_heap* A, node* x);
my_value minimum(min_heap A);
my_value extract_min(min_heap* A);
void decrease_key(min_heap* A, node* x, int k);



int main() {
    int heap_size = 6;
    int values[10] = {1, 2, 3, 4, 5, 6};
    int keys[10] = {10, 14, 19, 26, 31, 42};

    //min-heap building
    min_heap my_heap = build_min_heap(values, keys, heap_size);
    //print min-heap
    print(my_heap);


    //repeated extractions
    my_value min;
    for (int i=0; i<10; i++){
        min = extract_min(&my_heap);
        if (strcmp(min.status, "OK")==0){
            printf("Il valore con maggiore priorità nell'heap corrente è:%d\n", min.value);
            printf("Heap dopo l'estrazione:\n");
            print(my_heap);}
        else
            printf("Si è verificato un ERRORE\n");
        //print min-heap
    }

    return 0;
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
    min_heap my_heap;
    my_heap.heap_size=0;
    return my_heap;
}

min_heap build_min_heap(int* values, int* keys, int heap_size){
    min_heap my_heap;
    for (int i=0; i<heap_size; i++){
        node* my_node = (node *)malloc(sizeof(node));
        my_node->value=values[i];
        my_node->key = keys[i];
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
    /*
     * your code
     */
}

my_value minimum(min_heap A){
    /*
     * your code
     */
}

my_value extract_min(min_heap* A){
    /*
     * your code
     */
}

void decrease_key(min_heap* A, node* x, int k){
    /*
     * your code
     */
}

void insert(min_heap* A, node* x){
    /*
     * your code
     */
}