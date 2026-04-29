#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <cstdlib>
#include <string>
#include "List.hpp"
#include "BinarySearchTree.hpp"

template <typename T>
class Database
{
public:
  Database();

  /** determine if the database is empty 
   * @return true if the database is empty, false otherwise */
  bool isEmpty() const;

  /** return current number of entries
   * @return number of entries in the database */
  std::size_t getNumberOfEntries() const;

  /** add a new entry to the database
   * each entry should have two unique keys
   * @param key1 first string key
   * @param key2 second string key
   * @param item value type T 
   * @return true if entry was added, false otherwise;
   * duplicate keys are not allowed 
   * @post entry is added to the database */
  bool add(std::string key1, std::string key2, T item);

  /** remove an entry from the database
   * @param key string key of the entry to remove
   * @return true if the entry existed in the database and was removed,
   * false if the entry was not found 
   * @post entry is removed from the database */
  bool remove(const std::string& key);

  /** remove all entries from the database 
   * @post database is empty */ 
  void clear();

  /** retrieve the value of the entry associated with the input key
   * @param key string key of the entry to retrieve
   * @return value type T */
  T getValue(const std::string& key) const;

  /** search for an entry with the specified key
   * @param key string key of the entry to find
   * @return true if an entry exists associated with the input key, 
   * false otherwise */ 
  bool contains(const std::string& key) const;

private:

  // TODO:
  
  //custom struct of entries holding key1 & key2, and template data
  struct Entry
  {
    std::string key1;
    std::string key2;
    T data;
  };

  List<Entry> entries;
  BinarySearchTree<std::string, std::size_t> tree1; // index for key1
  BinarySearchTree<std::string, std::size_t> tree2; // index for key2

  //helper function to search both trees
  bool findIndex(const std::string& key, std::size_t& index) const;

};

#include "Database.tpp"

#endif 
