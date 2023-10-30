#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>

//key & value
typedef int value;
typedef int key;

//avl tree
typedef struct node* avl;

//min-heap node
typedef struct node{
    value my_value;
    key my_key;
    avl left;
    avl right;
    int height;
    int bf;
} tree_node;

//AVL basic operations
void update(avl my_node);
const char* detect(avl tree_node);
avl balance(avl my_tree);
avl right_rotation(avl my_tree);
avl left_rotation(avl my_tree);
avl insert_avl(value my_value, key my_key, avl my_tree);
avl delete_avl(key my_key, avl my_tree);
avl find_min(avl my_tree);
void print_tree(avl my_tree);
void test_insert();
void test_delete();

//Priority queue insert/delete
avl pq_insert(value my_value, key my_key, avl my_tree);
avl pq_extract(avl my_tree);
value get_min(avl my_tree);


int main() {

    //test_insert();
    test_delete();
    return 0;
}

value get_min(avl my_tree){
    avl min = find_min(my_tree);
    return min->my_value;
}

avl pq_insert(value my_value, key my_key, avl my_tree){
    return insert_avl(my_value,my_key, my_tree);
}

avl pq_extract(avl my_tree){
    avl min = find_min(my_tree);
    return delete_avl(min->my_key, my_tree);
}

void test_delete(){
    int my_keys[8] = {12, 8, 16, 4, 9, 10, 13, 14};
    int my_values[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    avl my_tree = NULL;
    for (int i = 0; i < 8; i++)
        my_tree = pq_insert(my_values[i], my_keys[i], my_tree);
    value min;
    for (int i=0; i<4; i++){
        min = get_min(my_tree);
        printf("value with highest priority:%d \n", min);
        my_tree = pq_extract(my_tree);
        printf("TREE \n");
        print_tree(my_tree);
        printf("\n\n");
    }
}

void test_insert(){
    int my_keys[8] = {12, 8, 16, 4, 9, 10, 13, 14};
    int my_values[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    avl my_tree;
    printf("TEST INSERT\n********\n");
    my_tree = NULL;
    for (int i = 0; i < 8; i++) {
        my_tree = pq_insert(my_values[i], my_keys[i], my_tree);
        printf("Print tree:\n");
        print_tree(my_tree);
        printf("\n\n");
    }


}

//pre-order print
void print_tree(avl my_tree){
    if (my_tree != NULL){
        printf("key: %d, ", my_tree->my_key);
        print_tree(my_tree->left);
        print_tree(my_tree->right);
    }
}

avl find_min(avl my_tree){
    if (my_tree == NULL)
        return NULL;
    else if(my_tree->left == NULL)
        return my_tree;
    return find_min(my_tree->left);
}

void update(avl my_tree){
    int lh = -1;
    int rh = -1;
    if (my_tree->left != NULL)
        lh = my_tree->left->height;
    if (my_tree->right != NULL)
        rh = my_tree->right->height;
    //update node's height
    my_tree->height = 1 + (lh<rh ? rh:lh);
    //update balance factor
    my_tree->bf = rh-lh;
}

const char* detect(avl my_tree){
    if (my_tree->bf == -2){
        if (my_tree->left->bf < 0)
            return("left-left unbalance");
        else
            return("left-right unbalance");
    }
    else if(my_tree->bf == 2){
        if (my_tree->right->bf > 0)
            return "right-right unbalance";
        else
            return "right-left unbalance";
    }
    else
        return "balanced";
}

avl balance(avl my_tree){
    const char* res = detect(my_tree);
    if (strcmp(res, "left-left unbalance")==0)
        return right_rotation(my_tree);
    else if(strcmp(res, "left-right unbalance")==0) {
        my_tree->left = left_rotation(my_tree->left);
        return right_rotation(my_tree);
    }
    else if(strcmp(res, "right-right unbalance")==0)
        return left_rotation(my_tree);
    else if(strcmp(res, "right-left unbalance")==0){
        my_tree->right = right_rotation(my_tree->right);
        return left_rotation(my_tree);
    }
    //if the tree is balanced
    return my_tree;
}

avl right_rotation(avl my_tree){
    avl tmp = my_tree->left;
    my_tree->left = tmp->right;
    tmp->right = my_tree;

    //update the substree-root and afterwords the main tree-root
    update(my_tree);
    update(tmp);
    return tmp;
}

avl left_rotation(avl my_tree){
    avl tmp = my_tree->right;
    my_tree->right = tmp->left;
    tmp->left = my_tree;

    //update the substree-root and afterwords the main tree-root
    update(my_tree);
    update(tmp);
    return tmp;
}

avl insert_avl(value my_value, key my_key, avl my_tree){
    // Step 1
    if (my_tree == NULL) {
        my_tree = (avl) malloc(sizeof(tree_node));
        if (my_tree == NULL) {
            perror("Error allocating memory for node.");
            exit(EXIT_FAILURE);
        }
        my_tree->my_key = my_key;
        my_tree->my_value = my_value;
        my_tree->left = my_tree->right = NULL;
        my_tree->height = 0;
        my_tree->bf = 0;
        return my_tree;
    }
    // Step 4
    else if (my_key < my_tree->my_key) {
        my_tree->left = insert_avl(my_value, my_key, my_tree->left);
    }
    // Step 6
    else if (my_key > my_tree->my_key) {
        my_tree->right = insert_avl(my_value, my_key, my_tree->right);
    }
    // Otherwise, key already exists. For now, not handling duplicate keys.
    else {
        return my_tree; 
    }

    // Step 9
    update(my_tree);
    
    // Step 10
    return balance(my_tree);
}

avl delete_avl(key my_key, avl my_tree) {
    // Step 1
    if (my_tree == NULL) {
        return NULL;
    }
    // Step 3
    else if (my_key < my_tree->my_key) {
        my_tree->left = delete_avl(my_key, my_tree->left);
    }
    // Step 5
    else if (my_key > my_tree->my_key) {
        my_tree->right = delete_avl(my_key, my_tree->right);
    }
    // Step 7
    else {
        // Node with only one child or no child
        if (my_tree->left == NULL) {
            avl temp = my_tree->right;
            free(my_tree);
            return temp; // Step 10
        }
        else if (my_tree->right == NULL) {
            avl temp = my_tree->left;
            free(my_tree);
            return temp; // Step 12
        }
        // Node with two children
        // Get the inorder successor (smallest in the right subtree)
        avl temp = find_min(my_tree->right);
        // Copy the inorder successor's content to this node
        my_tree->my_key = temp->my_key;
        my_tree->my_value = temp->my_value;
        // Delete the inorder successor
        my_tree->right = delete_avl(temp->my_key, my_tree->right);
    }

    // Step 21
    update(my_tree);

    // Step 22
    return balance(my_tree);
}