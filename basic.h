#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <float.h>
using namespace std;
/* ------- basic data structure ------*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/* ------ get length functions  -------*/
int getLength(ListNode* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

/* ------print functions  -------*/
template<typename T>
void print(const vector<T>& path){
	for(auto each:path)
		cout<<each<<" ";
	cout<<endl;
}

template<typename T>
void print(T x[],int l){
    for(int i=0;i<l;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

template<typename T>
void print(T x){
    cout<<x<<endl;
}

template<typename T>
void print(const vector<vector<T>> result){
    for(auto each:result){
        for(auto x:each){
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return;
}

void print(ListNode* head){
    if(!head){
        cout<<"list is empty"<<endl;
        return;
    }
    while(head){
        cout<<head->val<<'\t';
        head = head->next;
    }
    cout<<endl;
}

/* ------ get vector functions  -------*/
template<typename T>
vector<T> getVector(T x[],int len){
    vector<T> nums;
    for(int i=0;i<len;i++){
        nums.push_back(x[i]);
    }
    return nums;
}

vector<Point> getPointsVector(int x[],int len){
    vector<Point> result;
    for(int i=0;i<len;i+=2){
        Point tmp(x[i],x[i+1]);
        result.push_back(tmp);
    }
    return result;
}
template<typename T>
ListNode* getList(T x[],int l){
    ListNode* head = new ListNode(x[0]);
    ListNode* tmp = head;
    for(int i=1;i<l;i++){
        ListNode* z = new ListNode(x[i]);
        tmp->next = z;
        tmp = tmp->next;
    }
    return head;
}

template<typename T> 
vector<vector<T>> getMatrix(T x[], int rows, int cols){
    vector<vector<T>> matrix;
    int i = 0;
    vector<T> tmp;
    int count = 0;
    while(count<rows){
        tmp.push_back(x[(i++)+count*cols]);
        if(i == cols){
            i = 0;
            matrix.push_back(tmp);
            tmp.clear();
            count++;
        }
    }
    return matrix;
}




