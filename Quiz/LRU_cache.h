#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
/*

Leetcode 146

Design and implement a data structure for Least Recently 
Used (LRU) cache. It should support the following operations: 
get and put.

get(key) - Get the value (will always be positive) of the 
key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is 
not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before 
inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4


//IDEA:

need to use a queue to keep tracking the usage.
each queue val need to have a flag/count to see if it's 
duplicated, if so, needs to be removed from tail.
need to use an O(1) lookup container to keep the values.
*/
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        if(capacity <= 0)
        	cout << "wrong cache size!" << endl;
        m_cap = capacity;
        m_lookup_val = new unordered_map<int, int>;
        m_usage_track = new unordered_map<int, int>;
        m_item_order = new queue<int>;
    
    int get(int key) {
    	auto val_pair = m_lookup_val->find(key);
    	if(val_pair == m_lookup_val->end())
    		return -1;
    	auto key_pair m_usage_track->find(key);
    	++key_pair->second;
    	m_item_order->push(key);
        return val_pair->second;
    }
    
    void put(int key, int value) {
    	if(m_lookup_val->find(key) != m_lookup_val->end())
    		return;
    	if(m_curr_num < m_cap)
    	{
    		m_item_order->push(key);
    		++m_curr_num; 
        	return;
    	}
    	else if(m_curr_num == m_cap)
    	{
    		int curr_top_key = m_item_order->pop();
    		auto key_pair = m_usage_track->find(curr_top_key);
    		while(key_pair->second != 1)
    		{
    			--key_pair->second;
    			curr_top_key =  m_item_order->pop();
    			key_pair = m_usage_track->find(curr_top_key);
    		}
    		m_lookup_val->erase(curr_top_key);
    		m_usage_track->erase(curr_top_key);
    		m_item_order->push(key);
    		
    	}
    	else
    	{
    		cout << "exceed max capacity! Error!!" << endl;
    	}
    	m_lookup_val->insert(make_pair(key, value));
    	m_usage_track->insert(key, 1);//item exist once
    }

private:
	unordered_map<int, int>*  m_lookup_val;
	unordered_map<int, int>*  m_usage_track;
	queue<int>* m_item_order;

	int m_cap;
	int m_curr_num;
};


#endif