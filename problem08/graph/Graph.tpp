#include "Graph.hpp"

template <typename LabelType>
Graph<LabelType>::Graph() {}

template <typename LabelType> 
int Graph<LabelType>::getNumVertices() const {
    //return size of MAP, is total number of vertices (nodes)
    return adjacencyList.size();
}

template <typename LabelType> 
int Graph<LabelType>::getNumEdges() const {
    return 0;
}
        
template <typename LabelType> 
bool Graph<LabelType>::add(LabelType start, LabelType end) { 

    // ex: connect A--A (false) -- no duplicates
    if (start==end) return false;
    // edge already exists -- start and end nodes exist and are connected (false)
    if (adjacencyList.count(start) && adjacencyList[start].count(end)) return false;
    // both start and end nodes are new                            and       any edge exists already     (false)
    if (!((adjacencyList.count(start)) || adjacencyList.count(end)) &&      !(adjacencyList.empty()))   return false;

    // map key will be automatically set when Set elements are added,
    // so insert END as neighbor of START (automatically creates start map) & vice versa
    adjacencyList[start].insert(end);
    adjacencyList[end].insert(start);
    

    //now both nodes are added as neighbors of eachother (connected with edge)
    return true;
}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    //if edge doesn't exist, return false
    if (!(adjacencyList.count(start) && adjacencyList[start].count(end))) return false;

    //erase both neighbors, so edge is removed
    adjacencyList[start].erase(end);
    adjacencyList[end].erase(start);

    //if either has no neighbors (other edges) -- delete it
    if (adjacencyList[start].empty()) adjacencyList.erase(start);
    if (adjacencyList[end].empty()) adjacencyList.erase(end);

    return true;
}

template <typename LabelType> 
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}

template <typename LabelType> 
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}