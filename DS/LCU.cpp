#include "basic.h"

class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int x,int y):key(x), value(y), next(NULL), prev(NULL){}
    Node():key(), value(), next(NULL), prev(NULL){}
};

class LRUCache{
    //每次读取的时候都从最前面开始查找，显示出来之后放在最开头
    //插入的时候，如果链表已满尾部的内容删除掉，如果不满，就放在最开头
public:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> check;
    LRUCache(int cap):capacity(cap), size(0), head(new Node()), tail(new Node()), check(unordered_map<int,Node*>()){
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if(check.find(key) != check.end()){
            Node* res = check[key];
            detach(res);
            insertFront(res);
            return res->value;
        }
        else{
            return -1;
        }
    }
    
    void set(int key, int value) {
        //如果没有找到这个key，插入
        if(check.find(key) == check.end()){
            //如果空间满了，选择删除最后的节点
            if(size == capacity){
                Node *tmp = tail->prev;
                detach(tmp);
                --size;
                check.erase(tmp->key);
            }
            Node* newnode = new Node();
            newnode->key = key;
            newnode->value = value;
            insertFront(newnode);
            ++size;
            check.insert({key,newnode});
        }
        //如果找到了，选择更新
        else{
            Node* tmp = check[key];
            tmp->value = value;
            detach(tmp);
            insertFront(tmp);
        }
    }
private:
    //把找到的节点从cache的list里面分离出去
    void detach(Node* x){
       x->next->prev = x->prev;
       x->prev->next = x->next;
       x->prev = NULL;
       x->next = NULL;
       return;
    }
    //把找到的节点放在cache的list的最前端
    void insertFront(Node* x){
       x->next = head->next;
       x->prev = head;
       head->next->prev = x;
       head->next = x;
       return;
    }
};

int main(){
	LRUCache x(1);
	x.set(2,1);
	print(x.get(2));
}