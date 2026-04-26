#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "AbstractGraph.hpp"
#include <map>
#include <set>

template <typename LabelType>
class Graph: public AbstractGraph<LabelType>
{
    public:

        Graph();

        int getNumVertices() const;
        
        int getNumEdges() const;

        bool add(LabelType start, LabelType end);

        bool remove(LabelType start, LabelType end);

        void depthFirstTraversal(LabelType start, void visit(LabelType&));

        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
    
    private:

        //map using set
        std::map<LabelType, std::set<LabelType>> adjacencyList;
  
};

#include "Graph.tpp"

#endif 
