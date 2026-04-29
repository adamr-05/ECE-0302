#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "Database.hpp"


// struct used just for testing
struct TestEntry {
    std::string title;
    std::string author;
    int pubYear;
};
// TestEntry operators
bool operator==(const TestEntry& e1, const TestEntry& e2) {
    return (e1.title == e2.title) && (e1.author == e2.author) && (e1.pubYear == e2.pubYear);
};
std::ostream& operator<<(std::ostream& os, const TestEntry& t)
{
    os << "Title: " << t.title << ", Author: " << t.author << ", Year: " << t.pubYear;
    return os;
}


/* Provided test cases */
TEST_CASE("Test Add and Contains", "[add]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    REQUIRE(testdb.isEmpty());
    REQUIRE(testdb.add("key1", "key2", e1));
    REQUIRE_FALSE(testdb.isEmpty());
    REQUIRE(testdb.contains("key1"));
    REQUIRE(testdb.contains("key2"));
}


TEST_CASE("Test getValue", "[retrieve]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);
    
    REQUIRE(testdb.getValue("key1") == e1);
    REQUIRE(testdb.getValue("key2") == e1);
}


TEST_CASE("Test Remove", "[remove]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);
    
    testdb.remove("key1");
    REQUIRE(!testdb.contains("key1"));
    REQUIRE(!testdb.contains("key2"));

    testdb.add("key1", "key2", e1);
    
    testdb.remove("key2");
    REQUIRE(!testdb.contains("key1"));
    REQUIRE(!testdb.contains("key2"));

    REQUIRE(testdb.isEmpty());
}


TEST_CASE("Test Copy", "[copy]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);

    Database<std::string> testdb_copy(testdb);

    testdb.clear();

    REQUIRE(testdb_copy.getValue("key1") == e1);
    REQUIRE(testdb_copy.getValue("key2") == e1); 
    
    Database<std::string> testdb2;

    testdb2.add("key1", "key2", e1);

    Database<std::string> testdb2_copy;

    testdb2_copy = testdb2;

    testdb2.clear();

    REQUIRE(testdb2_copy.getValue("key1") == e1);
    REQUIRE(testdb2_copy.getValue("key2") == e1); 
}


TEST_CASE("TestEntry Type", "[entry type]") {
    Database<TestEntry> testdb;

    TestEntry e1;
    std::string isbn1 = "000-0-00-000000-1";
    std::string catalog_id1 = "0000001";
    e1.title = "The Winds of Winter";
    e1.author = "George R. R. Martin";
    e1.pubYear = 2051;

    testdb.add(isbn1, catalog_id1, e1);

    TestEntry e2;

    std::string isbn2 = "000-0-00-000000-2";
    std::string catalog_id2 = "0000002";
    e2.title = "A Dream of Spring";
    e2.author = "George R. R. Martin";
    e2.pubYear = 2052;

    testdb.add(isbn2, catalog_id2, e2);

    // TODO
    // both keys should retrieve the correct entry
    REQUIRE(testdb.getValue(isbn1) == e1);
    REQUIRE(testdb.getValue(catalog_id1) == e1);
    REQUIRE(testdb.getValue(isbn2) == e2);
    REQUIRE(testdb.getValue(catalog_id2) == e2);

    // removin' e1 by catalog id should kill both o' its keys but leave e2 alone
    REQUIRE(testdb.remove(catalog_id1));
    REQUIRE_FALSE(testdb.contains(isbn1));
    REQUIRE_FALSE(testdb.contains(catalog_id1));
    REQUIRE(testdb.getValue(isbn2) == e2);
    REQUIRE(testdb.getValue(catalog_id2) == e2);
    
}


/* Your test cases here */

TEST_CASE("Empty database state", "[empty]") {
    Database<std::string> db;
    REQUIRE(db.isEmpty());
    REQUIRE(db.getNumberOfEntries() == 0);
    REQUIRE_FALSE(db.contains("anything"));
    REQUIRE_FALSE(db.remove("ghost"));
}


TEST_CASE("getNumberOfEntries tracks adds and removes", "[size]") {
    Database<std::string> db;
    REQUIRE(db.getNumberOfEntries() == 0);

    db.add("a1", "b1", "one");
    REQUIRE(db.getNumberOfEntries() == 1);

    db.add("a2", "b2", "two");
    db.add("a3", "b3", "three");
    REQUIRE(db.getNumberOfEntries() == 3);

    db.remove("a2");
    REQUIRE(db.getNumberOfEntries() == 2);

    db.clear();
    REQUIRE(db.getNumberOfEntries() == 0);
}


TEST_CASE("Reject duplicate keys on add", "[add]") {
    Database<std::string> db;
    REQUIRE(db.add("a", "b", "first"));

    // collision on key1
    REQUIRE_FALSE(db.add("a", "c", "second"));
    // collision on key2
    REQUIRE_FALSE(db.add("d", "b", "third"));
    // collision on both
    REQUIRE_FALSE(db.add("a", "b", "fourth"));
    // cross-tree: new key1 collides wit' an existing key2
    REQUIRE_FALSE(db.add("b", "z", "fifth"));
    // same string for both keys o' a single entry
    REQUIRE_FALSE(db.add("x", "x", "same"));

    // none o' the failed adds should've changed the size
    REQUIRE(db.getNumberOfEntries() == 1);
}


TEST_CASE("Remove middle entry triggers swap-with-last", "[remove]") {
    Database<std::string> db;
    db.add("a1", "b1", "first");
    db.add("a2", "b2", "second");
    db.add("a3", "b3", "third");

    // removin' th' first-added forces a swap, since 'tisn't the tail
    REQUIRE(db.remove("a1"));
    REQUIRE_FALSE(db.contains("a1"));
    REQUIRE_FALSE(db.contains("b1"));

    // remainin' entries still reachable by both keys
    REQUIRE(db.getValue("a2") == "second");
    REQUIRE(db.getValue("b2") == "second");
    REQUIRE(db.getValue("a3") == "third");
    REQUIRE(db.getValue("b3") == "third");
    REQUIRE(db.getNumberOfEntries() == 2);
}


TEST_CASE("Remove nonexistent key returns false", "[remove]") {
    Database<std::string> db;
    REQUIRE_FALSE(db.remove("ghost"));

    db.add("a", "b", "x");
    REQUIRE_FALSE(db.remove("nope"));
    REQUIRE(db.getNumberOfEntries() == 1);
}


TEST_CASE("Add after remove reuses keys", "[add][remove]") {
    Database<std::string> db;
    db.add("a", "b", "first");
    db.remove("a");

    // both keys should be free again
    REQUIRE(db.add("a", "b", "second"));
    REQUIRE(db.getValue("a") == "second");
    REQUIRE(db.getValue("b") == "second");
}


TEST_CASE("Stress: many entries, remove every other one", "[stress]") {
    Database<int> db;
    for (int i = 0; i < 20; i++) {
        std::string k1 = "A" + std::to_string(i);
        std::string k2 = "B" + std::to_string(i);
        db.add(k1, k2, i);
    }
    REQUIRE(db.getNumberOfEntries() == 20);

    // remove evens — exercises swap-with-last repeatedly
    for (int i = 0; i < 20; i += 2) {
        REQUIRE(db.remove("A" + std::to_string(i)));
    }
    REQUIRE(db.getNumberOfEntries() == 10);

    // odds should still be intact an' reachable by both keys
    for (int i = 1; i < 20; i += 2) {
        REQUIRE(db.getValue("A" + std::to_string(i)) == i);
        REQUIRE(db.getValue("B" + std::to_string(i)) == i);
    }
    // evens are gone
    for (int i = 0; i < 20; i += 2) {
        REQUIRE_FALSE(db.contains("A" + std::to_string(i)));
        REQUIRE_FALSE(db.contains("B" + std::to_string(i)));
    }
}
