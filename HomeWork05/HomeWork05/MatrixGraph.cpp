#include "MatrixGraph.h"

#pragma once

typedef std::list<NWPair> EList;

MatrixGraph::MatrixGraph(unsigned num_nodes){
	M.resize(num_nodes);
	for(unsigned int ii=0; ii<num_nodes; ii++){
		M.at(ii).resize(num_nodes);
	}
	num_edges = 0;
}

MatrixGraph::~MatrixGraph(){}

// Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}
  
// Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M.at(u).at(v); 
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	EList edgList;

	for(unsigned int ii=0; ii<M[u].size(); ii++){
		if(M.at(u).at(ii)!=0)
			edgList.push_back(NWPair(ii,M.at(u).at(ii)));
	}
	return edgList;
}

unsigned MatrixGraph::degree(NodeID u) const{
	int degree = 0;
	for(unsigned int ii=0; ii<M.at(u).size(); ii++){
		if(M.at(u).at(ii)!=-1)
			degree++;
	}
	return degree;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}