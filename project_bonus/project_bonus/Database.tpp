#include "Database.hpp"

template <typename T>
Database<T>::Database() {}

template <typename T>
bool Database<T>::isEmpty() const {
    //use list method isEmpty
    return entries.isEmpty();
}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() const {
    //use list method getLength
    return entries.getLength();
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, T item) {
    //keys cannot be same, no duplicates
    if (key1 == key2) return false;
    if (contains(key1) || contains(key2)) return false;

    //Use struct of key1,key2, item
    Entry e{key1, key2, item};
    std::size_t pos = entries.getLength();

    //insert entry struct into entries list
    entries.insert(pos,e);
    //also insert into trees to track indexes of key1 & key2
    tree1.insert(key1, pos);
    tree2.insert(key2, pos);
    return true;
}

template <typename T>
bool Database<T>::remove(const std::string& key) {
    
    //Write value of index into p if key found
    std::size_t p;
    if (!findIndex(key, p)) return false;

    //get entry key values, then remove them from tree1 & tree2
    Entry orig = entries.getEntry(p);
    tree1.remove(orig.key1);
    tree2.remove(orig.key2);


    //instead of shifting every element down
    //move last item into position p, then remove tail
    std::size_t last = entries.getLength() - 1;
    if (p != last)
    {   
        //grab final entry
        Entry tail = entries.getEntry(last);
        //overwrite p with final entry
        entries.setEntry(p, tail);

        //new tail index is now "p"
        //update both trees, remove old mapping of "last", change to "p"
        tree1.remove(tail.key1);
        tree1.insert(tail.key1, p);
        tree2.remove(tail.key2);
        tree2.insert(tail.key2, p);
    }
    //now remove last slot, no pointer to it
    entries.remove(last);
    return true;
}

template <typename T>
void Database<T>::clear() {
    //clear entries list and destroy trees that hold key indexes
    //Uses BST destroy method to clear trees
    entries.clear();
    tree1.destroy();
    tree2.destroy();
}

template <typename T>
T Database<T>::getValue(const std::string& key) const {

    //idx to track when finding value
    std::size_t idx;

    //if index not found return empty object
    if (!findIndex(key, idx)) return T();

    //return data value of entry at index
    return entries.getEntry(idx).data;
}

template <typename T>
bool Database<T>::contains(const std::string& key) const {
    //use findIndex method to return true if index exists at key
    std::size_t idx;
    return findIndex(key, idx);
}

template <typename T>
inline bool Database<T>::findIndex(const std::string &key, std::size_t &index) const
{
    //use BST retrieve to check key & index in tree
    //try tree1, retrieve writes into index if if found, then check tree2, then not found...
    if (tree1.retrieve(key, index)) return true;
    if (tree2.retrieve(key, index)) return true;
    return false;
}
