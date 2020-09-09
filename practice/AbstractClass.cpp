/**
 * https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: protected Cache{
    public:
    LRUCache(int capacity) {
        cp = capacity;
        head = new Node(0,0);
        tail = head;
        while(--capacity)
        {
            Node* temp = new Node(0,0);
            temp->next = nullptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    virtual void set(int key, int val) override
    {
        if (mp.find(key) == mp.end())
        {
            Node* temp = new Node(key, val);
            Node * node = temp;
            temp->next = head;
            head->prev = temp;
            head = temp;
            temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            auto keyData = temp->key;
            delete temp;
            mp[key] = node;
            if (mp.size() > cp)
                mp.erase(keyData);

        }
        else
        {
            Node* node = mp[key];
            if (node != head)
            {
                swap(node, head);
            }
        }
    }
    virtual int get(int key)
    {
        if (mp.find(key)!= mp.end())
            return mp[key]->value;
        else 
            return -1;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
