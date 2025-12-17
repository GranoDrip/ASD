#include "GrafoList.h"

int main(){

    GraphList<int,int> g(30);

    GraphNode g1;
    GraphNode g2;
    GraphNode g3;


    g.insertNode(g1,5);
    std::cout << g1.getGraphNodeId() << std::endl;


    g.insertNode(g2,10);
    std::cout << g2.getGraphNodeId() << std::endl;

    g.insertNode(g3,15);
    std::cout << g3.getGraphNodeId() << std::endl;


    g.insertEdge(g1,g2,1);
    g.insertEdge(g1,g3,1);

    g.toString();

    std::cout << "Nodi: " << std::endl;
    g.getNodes().toString();

    std::cout << "Nodi Adiacenti a 0: " << std::endl;
    g.getAdjacentNodes(g1).toString();



}