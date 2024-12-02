#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data; 
    struct Node* next; 
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;


LinkedList* creat_new_LinkedList();
void creat_new_node(LinkedList* list, int data);
Node* finding_node_new(int data, Node* a);
Node* finding_node(int data, Node* a);
void delete_node(int data, LinkedList* a);
Node* Node_index_data_finding(Node* a, int idx, int loc);
int Node_index_data(LinkedList* a, int idx);
void Node_index_delete(LinkedList* a, int idx);
int last_Node_data(LinkedList* a);
Node* last_Node_finding(Node* a);

LinkedList * creat_new_LinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = NULL;
    return list;
}

void creat_new_node(LinkedList * list,int data) {
    Node * new_node = (Node*)malloc(sizeof(Node));
    if (list->head->next == NULL) {
        list->head->next = new_node;
        new_node->data = data;
        new_node->next = NULL;
    }
    else {
        Node * finded_node = finding_node_new(data, list->head,list);
        new_node->next = finded_node->next;
        finded_node->next = new_node;
        new_node->data = data;
    }
}

Node* finding_node_new(int data, Node* a,LinkedList*b) {
    if (a->next == NULL) {
        if (data > a->data) {
            return a;
        }
        else {
            return b->head;
        }
    }
    if (data > a->data && data < a->next->data) {
        return a;
    }
    else {
        return finding_node_new(data, a->next,b);
    }
}

Node* finding_node(int data, Node* a, LinkedList *b) {
    if (a->next == NULL) {
        if (data > a->data) {
            return a;
        }
        else {
            return b->head;
        }
    }
    if (data == a->data) {
        return a;
    }
    else {
            return finding_node(data, a->next,b);
        
    }
}

void delete_node(int data, LinkedList* a) {
    Node * delete_node = finding_node(data, a->head->next,a);
    if (delete_node == NULL) {
        printf("Not found!!\n");
        return;
    }
    Node* left_node = finding_node_new(data - 1, a->head->next, a);
    left_node->next = delete_node->next;
    free(delete_node);
    return;
}

int Node_index_data(LinkedList* a, int idx) {
    Node* idx_node = Node_index_data_finding(a->head->next, idx, 0);
    if (idx_node == NULL) {
        return NULL;
    }
    return idx_node->data;
}

Node* Node_index_data_finding(Node* a, int idx, int loc) {
    if (a == NULL) {
        printf("OVERFLOW\n");
        return NULL;
    }
    if (idx == loc) {
        return a;
    }
    else {
        return Node_index_data_finding(a->next, idx , loc+1);
    }
}

void Node_index_delete(LinkedList* a, int idx) {
    Node* delete_node = Node_index_data_finding(a->head,idx,0);
    if (delete_node == NULL) {
        printf("Not found!!\n");
        return;
    }
    Node* left_node = Node_index_data_finding(a->head,idx-1,0); 
    left_node->next = delete_node->next;
    free(delete_node);
    return;
}

int last_Node_data(LinkedList* a) {
    return last_Node_finding(a->head)->data;
}

Node* last_Node_finding(Node* a) {
    if (a->next == NULL) {
        return a;
    }
    else {
        return last_Node_finding(a->next);
    }
}