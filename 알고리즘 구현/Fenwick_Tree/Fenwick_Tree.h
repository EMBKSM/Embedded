#ifndef Fenwick_Tree_H_
#define Fenwick_Tree_H_
#include <bits/stdc++.h>

class FenwickTree
{
public:
    FenwickTree(int change_array[], int size);

    int pointU_rangeQ(int i, int data, int left, int right);
    int pointQ_rangeU(int i, int data, int left, int right);
    int rangeU_rangeQ(int left, int right, int data);

    int point_query(int i);
    int range_query(int left, int right);

    void point_update(int i, int data);
    void range_update(int left, int right, int data);
private:
    int* fenwick_tree_data;
    int fenwick_tree_size;

    int sum(int i);
    void add(int i, int data);
};

#endif // !Fenwick_Tree_H_