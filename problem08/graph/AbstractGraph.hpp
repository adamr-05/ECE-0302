
#ifndef _ABSTRACT_GRAPH_HPP_
#define _ABSTRACT_GRAPH_HPP_

#include <cstdlib>

template <typename LabelType>
class AbstractGraph
{
  public:

    /** Virtual destructor to ensure overriding */
    virtual ~AbstractGraph(){};

    /** Get number of vertices/nodes in the graph
     * @return int number of nodes in the graph */ 
    virtual int getNumVertices() const = 0;

    /** Get number of edges in the graph
     * @return int number of edges in the graph */
    virtual int getNumEdges() const = 0;

    /** Create an undirected edge between two vertices with the provided labels.
     * If vertices do not exist, create them and add them to the graph before adding the edge.
     * @param start vertex label where the new edge starts (should be created if it does not already exist)
     * @param end vertex label where the new edge ends (should be created if it does not already exist)
     * @return true if the addition was successful, false if not 
     * (does not allow addition of duplicate edges or if graph would be disconnected) 
     * @post new edge (and possibly vertices) is added to the graph */
    virtual bool add(LabelType start, LabelType end) = 0;

    /** Remove an edge from the graph.
     * If a vertex is left with no other edges, remove it from the graph 
     * (graph should always be connected). 
     * @param start vertex label where the edge to remove starts
     * @param end vertex label where the edge to remove ends
     * @return true if the edge was found and removed, false if the edge does not exist
     * @post edge is removed from the graph along with any nodes that became disconnected */ 
    virtual bool remove(LabelType start, LabelType end) = 0;

    /** Perform a depth-first search of the graph beginning at the given vertex.
     * Call the provided function once for each vertex visited.
     * Where there is a choice of next vertex, vertices should be visited in ascending order.
     * @pre assumes LabelType has overloaded comparison operators
     * @param start vertex label to start the search
     * @param visit function to call for each vertex visited */
    virtual void depthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;

    /** Perform a breadth-first search of the graph beginning at the given vertex.
     * Call the provided function once for each vertex visited.
     * Where there is a choice of next vertex, vertices should be visited in ascending order.
     * @pre assumes LabelType has overloaded comparison operators
     * @param start vertex label to start the search
     * @param visit function to call for each vertex visited */
    virtual void breadthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;
};

#endif 
