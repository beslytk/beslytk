#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node{
public:
    int key, value;
    Node* prev, *next;
    Node(int _key, int _val):key(_key), value(_val){
        prev = NULL;
        next = NULL;
    }

}; 

class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {
        leastUsed = new Node(0,0);
        mostUsed  = new Node(0,0);
        leastUsed->next = mostUsed;
        mostUsed->prev = leastUsed;
    }
    // insert a node to a doubly linked list
    // insert just before the mostUsed Node
    void insert(Node* node){
        node->prev = mostUsed->prev;
        node->next = mostUsed;
        mostUsed->prev->next = node;
        mostUsed->prev = node;
    }

    // remove the node from LL   
    void remove(Node* node){
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            
            remove(keyNodeMap[key]);
            insert(keyNodeMap[key]);

            return keyNodeMap[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {

        // if given key,value pair already present, remove it from LL
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            remove(keyNodeMap[key]);
        }
        // add to hashmap first
        keyNodeMap[key] = new Node(key, value);
        // inset the node to LL
        insert(keyNodeMap[key]); // insert before mostUsed Node
        
        //remove least used node if capacity exceded
        if(keyNodeMap.size() > capacity){
            Node* lru = leastUsed->next;
            remove(lru); // remove from LL
            // erase the entry from map
            keyNodeMap.erase(lru->key);
        }

    }
private:
    int capacity;
    unordered_map<int, Node*> keyNodeMap;
    Node* leastUsed, *mostUsed;    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    /**
     * @brief ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
                [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
              Output
                [null, null, null, 1, null, -1, null, -1, 3, 4]
     * 
     */
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);cout<<"[ null ";
    obj->put(1,1);cout<<", null ";
    obj->put(2,2);cout<<", null ";
    int param_1 = obj->get(1);cout<<param_1<<", ";
    obj->put(3,3);cout<<", null ";
    int param_2 = obj->get(2);cout<<param_2<<", ";
    obj->put(4,4);cout<<", null ";
    int param_3 = obj->get(1);cout<<param_3<<", ";
    int param_4 = obj->get(3);cout<<param_4<<", ";
    int param_5 = obj->get(4);cout<<param_5<<", ";
    cout<<"]";

    return 0;
}