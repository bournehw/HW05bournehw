#include "ListGraph.h"

#pragma once

ListGraph::ListGraph(int numNodes){
	std::vector<EdgeWeight>::iterator it;
	edgeList.resize(numNodes);
	num_edges = 0;
}

ListGraph::~ListGraph(){}

// Modifiers
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	edgeList[u].push_back(NWPair(v,weight));
	edgeList[v].push_back(NWPair(u,weight));
	num_edges++;
}
  
// Inspectors
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
		NWPair theEdge = *it;
		if(theEdge.first==v){
			return theEdge.second;
		}
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const{
	return edgeList[u].size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}