#include "Graph.hpp"

template <typename LabelType>
Graph<LabelType>::Graph() {}

template <typename LabelType> 
int Graph<LabelType>::getNumVertices() const {
    return 0;
}

template <typename LabelType> 
int Graph<LabelType>::getNumEdges() const {
    return 0;
}
        
template <typename LabelType> 
bool Graph<LabelType>::add(LabelType start, LabelType end) { 
    return false; 
}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    return false;
}

template <typename LabelType> 
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}

template <typename LabelType> 
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}