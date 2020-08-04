class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        const auto it=mymap_.find(key);
        
        if(it==mymap_.end())
            return -1;
        if(it!=mymap_.end())
        {
            cache_.splice(cache_.begin(),cache_,it->second);
            return it->second->second;
        }
        return it->second->second;
        
    }
    
    void put(int key, int value) {
        const auto it=mymap_.find(key);
        if(it!=mymap_.end())
        {
            cache_.splice(cache_.begin(),cache_,it->second);
            it->second->second=value;
            return;
        }
        if(it==mymap_.end())
        {
            if(mymap_.size()==capacity_)
            {
                const auto node=cache_.back();
                mymap_.erase(node.first);
                cache_.pop_back();
            }
            cache_.emplace_front(make_pair(key,value));
            mymap_[key]=cache_.begin();
        }
        return;
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int,list<pair<int,int>>::iterator> mymap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//本题值得总结的很多
//1. 结构 hash_map+list
//  hash_map key存放正常的key value存放指向对应listnode中元素的指针
//  list    双向链表 表头表尾均可操作 表头代表最新元素
//          存放pair类型 key,value

//2. list数据结构
//      emplace_front就是表头插入
//      splice合并链表 d.slice(a,b,c) 把b链表中c指针所指向的部分移动到d链表中a指针所指向的位置

