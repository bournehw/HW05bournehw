#include "GraphAlgs.h"

# pragma once

#define swap(a,b)\
	b = a^b;\
	a = b^a;\
	b = a^b;

std::vector<NodeID> bestTour;
EdgeWeight bestLen = DBL_MAX;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	const int n = G->size();
	std::vector<NodeID> curTour;
	
	curTour.resize(G->size());
	bestTour.resize(G->size());

	for(unsigned int ii=0; ii<G->size(); ii++){
		curTour[ii] = ii;
		bestTour[ii] = ii;
	}		
	tour(G, curTour, 0, G->size(), 1);

	return std::pair<std::vector<NodeID>, EdgeWeight>(bestTour,bestLen);
}

void tour(Graph* G, std::vector<NodeID> curTour, EdgeWeight curLen, int n, int startPnt){
	if(n-startPnt==1){
		curLen+=G->weight(curTour[startPnt],curTour[startPnt-1]);
		curLen+=G->weight(curTour[0], curTour[n-1]);
		if(curLen<bestLen){
			bestLen = curLen;
			for(int jj=0; jj<n; jj++)
				bestTour[jj] = curTour[jj];
		}
	}else{
		if(curLen>bestLen)
			return;
		for(int ii=startPnt+1; ii<n; ii++){
			swap(curTour[startPnt],curTour[ii]);
			tour(G, curTour, curLen+G->weight(curTour[startPnt],curTour[startPnt-1]), n, startPnt+1);
			swap(curTour[startPnt],curTour[ii]);
		}
	}
}
