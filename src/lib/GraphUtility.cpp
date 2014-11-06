/**
 * 
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error


#include "GraphUtility.hpp"

using std::cout;
using std::cin;
using std::endl;

GraphUtility::GraphUtility() {

}

int GraphUtility::DFS(Graph graph,int v) {

    this->visited[v] = 1;

    for(int i = 0 ;i < graph.getNumberOfNodes(); i++) {

        if(this->visited[graph.getLink(v,i)] == 0 && graph.getLink(v,i) == 1)
        {
            DFS(graph,i);
        }
    }

    return v;
}