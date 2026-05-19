#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "fifo_lifo.hpp"
#include "unidirected_graph.hpp"
#include "graph_visit_recursive_dfs.hpp"
#include "dijsktra.hpp"
#include "graph_viz.hpp"


int main() {
    unidirected_graph grafo;
    // Creo un grafo
    grafo.add_edge(unidirected_edge(0, 1));
    grafo.add_edge(unidirected_edge(0, 3));
    grafo.add_edge(unidirected_edge(1, 2));
    grafo.add_edge(unidirected_edge(2, 3));
    grafo.add_edge(unidirected_edge(3, 4));

    // Testo BFS
    std::cout << "Algoritmo BFS: " << "\n";
	
    fifo<int> coda;
    unidirected_graph bfs_albero = graph_visit(grafo, 0, coda);
    for (auto& edge : bfs_albero.all_edges()){
	    std::cout << edge << " " << "\n";
	};
	// Testo DFS
    std::cout << "Algortimo DFS: " << "\n";
	
    lifo<int> pila;
    unidirected_graph dfs_albero = graph_visit(grafo, 0, pila);
    for (auto& edge : dfs_albero.all_edges()){
	    std::cout << edge << " " << "\n";
	};
	// Testo DFS ricorsivo
	std::cout << "Algoritmo DFS ricorsivo: " << "\n";
	
	unidirected_graph dfsr_albero = recursive_dfs(grafo, 0);
	for (auto& edge : dfsr_albero.all_edges()){
		std::cout << edge << " " << "\n";
	};
	// Testo Dijkstra
    std::cout << "Algoritmo Dijkstra: " << "\n";
	
    unidirected_graph djk_albero = dijkstra(grafo, 0);
    for (auto& edge : djk_albero.all_edges()){
		std::cout << edge << " " << "\n";
    };
	
	//Chiamata .dot per graphviz
	
	scrittura_dot(bfs_albero, "bfs_albero.dot");
	scrittura_dot(dfs_albero, "dfs_albero.dot");
	scrittura_dot(djk_albero, "djk_albero.dot");

    return 0;
};