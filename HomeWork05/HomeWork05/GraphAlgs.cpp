#include "GraphAlgs.h"

# pragma once

#define swap(a,b)\
	if(a!=b){\
		b = a^b;\
		a = b^a;\
		b = a^b;\
	}

std::vector<NodeID> bestTour;
EdgeWeight bestLen;
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	int* n = new int(G->size());
	int* curTour = new int[*n];
	bestLen = DBL_MAX;

	bestTour.resize(G->size());

	for(unsigned int ii=0; ii<*n; ii++){
		curTour[ii] = ii;
		bestTour[ii] = ii;
	}		
	tour(G, curTour, 0, n, 1);
	delete n;
	delete curTour;
	return std::pair<std::vector<NodeID>, EdgeWeight>(bestTour,bestLen);
}

void tour(Graph* G, int* curTour, EdgeWeight curLen, int* n, int startPnt){
	if(*n-startPnt==1){
		curLen+=G->weight(curTour[startPnt],curTour[startPnt-1]);
		curLen+=G->weight(curTour[0], curTour[*n-1]);
		if(curLen<bestLen){
			bestLen = curLen;
			for(int jj=0; jj<*n; jj++)
				bestTour[jj] = curTour[jj];
		}
	}else{
		if(curLen>bestLen)
			return;
		for(int ii=startPnt; ii<*n; ii++){
			if(ii!=startPnt){ swap(curTour[startPnt],curTour[ii]);}
			tour(G, curTour, curLen+G->weight(curTour[startPnt],curTour[startPnt-1]), n, startPnt+1);
			if(ii!=startPnt){ swap(curTour[startPnt],curTour[ii]);}
		}
	}
}
