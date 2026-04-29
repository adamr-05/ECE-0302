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
    // TODO
    return false;
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
    if (tree1.retrieve(key, index)) return true;
    if (tree2.retrieve(key, index)) return true;
    return false;
}
