#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
	int* data;
	int top;
	int max;
}Stack;

// 새로운 스택 할당
Stack* newstack(int size);

// 스택이 비어있는지 확인
int is_empty(Stack* arr);

// 스택이 차 있는지 확인
int is_full(Stack* arr);

// 스택에 데이터 push
void push(Stack* arr, int data);

// 스택에 데이터 pop
int pop(Stack* arr);

// 스택 동적메모리 할당 해제
void free_stack(Stack* arr);


//새로운 스택 할당
Stack* newstack(int size) {
    Stack* arr = (Stack*)malloc(sizeof(Stack));
    arr->max = size;
    arr->top = -1;
    arr->data = (int*)malloc(sizeof(int) * size);
    return arr;
}

//스택 해제
void free_stack(Stack* arr) {
    if (arr) {
        if (arr->data) {
            free(arr->data);
        }
        free(arr);
    }
}

//비어있는가?
int is_empty(Stack* arr) {
    if (arr->top == -1) {
        return 1;
    }
    return 0;
}


//차있는가?
int is_full(Stack* arr) {
    if (arr->top == (arr->max) - 1) {
        return 1;
    }
    return 0;
}

//push
void push(Stack* arr, int data) {
    if (is_full(arr)) {
        printf("stack is FULL!");
        return;
    }
    arr->top++;
    arr->data[arr->top] = data;
}

//pop
int pop(Stack* arr) {
    if (is_empty(arr)) {
        printf("stack is empty!");
        return 0;
    }
    int value = arr->data[arr->top];
    arr->top--;
    return value;
}

