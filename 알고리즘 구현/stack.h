#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
	int* data;
	int top;
	int max;
}Stack;

// ���ο� ���� �Ҵ�
Stack* newstack(int size);

// ������ ����ִ��� Ȯ��
int is_empty(Stack* arr);

// ������ �� �ִ��� Ȯ��
int is_full(Stack* arr);

// ���ÿ� ������ push
void push(Stack* arr, int data);

// ���ÿ� ������ pop
int pop(Stack* arr);

// ���� �����޸� �Ҵ� ����
void free_stack(Stack* arr);


//���ο� ���� �Ҵ�
Stack* newstack(int size) {
    Stack* arr = (Stack*)malloc(sizeof(Stack));
    arr->max = size;
    arr->top = -1;
    arr->data = (int*)malloc(sizeof(int) * size);
    return arr;
}

//���� ����
void free_stack(Stack* arr) {
    if (arr) {
        if (arr->data) {
            free(arr->data);
        }
        free(arr);
    }
}

//����ִ°�?
int is_empty(Stack* arr) {
    if (arr->top == -1) {
        return 1;
    }
    return 0;
}


//���ִ°�?
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

