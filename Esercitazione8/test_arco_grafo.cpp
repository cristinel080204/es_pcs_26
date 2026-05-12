#include <iostream>
#include <set>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include <algorithm>

//Testo i vari metodi implementati prima

int main(){
	unidirected_edge e1(1,3); 
	unidirected_edge e2(5,6); 
	unidirected_edge e3(19,7);
	unidirected_edge e4(2,34); 
	
	unidirected_graph g1; 
	g1.add_edge(e1); 
	g1.add_edge(e2);
	g1.add_edge(e3); 
	g1.add_edge(e4);
	
    std::cout << "Nodi nel grafo: ";
    for (int nodi : g1.all_nodes()) {
        std::cout << nodi << " ";  //Voglio i nodi del grafo
    };
    std::cout << "\n";

   
    std::cout << "Vicini del nodo 3: "; //Verifico che mi dia i vicini del nodo 3
    for (int vicini3 : g1.neighbours(3)) {
        std::cout << vicini3 << " ";
    };
    std::cout << "\n";

   //Testo anche i metodi edge_number e edge_at
    std::cout << "L'arco " << e1 << " è il numero: " << g1.edge_number(e1) << "\n";
    std::cout << "Il secondo arco e': " << g1.edge_at(2) << "\n";

   //Testo l'operatore differenza
    unidirected_graph g2;
	unidirected_graph g3;
	unidirected_graph g4;
	
    g2.add_edge(e1);
	g2.add_edge(e3);
	g3.add_edge(e1);
	g3.add_edge(e2);
	g3.add_edge(e3);
	g4.add_edge(e2);
	g4.add_edge(e4);
    
    unidirected_graph g_diff1 = g1 - g2; 
	unidirected_graph g_diff2 = g3 - g4; 
   
    std::cout << "Archi rimanenti nella differenza (g1-g2):" << "\n";
    for (const auto& edge : g_diff1.all_edges()) {
        std::cout << edge << " ";
    };
    std::cout << "\n";
	std::cout << "archi rimasti nella differenza (g3-g4): "<< "\n"; 
	for (const auto& edge: g_diff2.all_edges()) {
		std::cout << edge << " "; 
	};
	std::cout << "\n"; 

    return 0;
};