#pragma once
#include <iostream>
#include <set>
#include <map>
#include "unidirected_graph.hpp"
#include "fifo_lifo.hpp"

template <typename contenitore>
unidirected_graph graph_visit(const unidirected_graph& graph, int n_sorg, contenitore& c){
	
	unidirected_graph albero; //l'albero che deve dare in output
	std::set<int> n_visitati; //inizializzo un set di interi, di nodi che saranno visitati
	c.put(n_sorg); //in particolare metto il nodo sorgente nel contenitore
	n_visitati.insert(n_sorg); //il primo nodo visitato è proprio quello sorgente
	
	while(!c.empty()){ //Visita BFS o DFS in base al contenitore che viene passato
	    int u = c.get();
		for(int nodo : graph.neighbours(u)){
			if(n_visitati.find(nodo) == n_visitati.end()){ //Se il nodo vicino non è presente lo inseriamo nei visitati
			   n_visitati.insert(nodo);
               albero.add_edge(unidirected_edge(u, nodo));//Costruisco l'albero
			   c.put(nodo);
			};			   
		};
	};
	return albero;
};

//Implemento la versione ricorsiva DFS, dividendo in 2 parti che mi servono.

void recursive_dfs_1(const unidirected_graph& graph, int u, std::set<int>& n_visitati, unidirected_graph& albero) {
    n_visitati.insert(u);
    for (int nodo : graph.neighbours(u)) {
        if (n_visitati.find(nodo) == n_visitati.end()){
            albero.add_edge(unidirected_edge(u, nodo));
            recursive_dfs_1(graph, nodo, n_visitati, albero);
        };
    };
};

unidirected_graph recursive_dfs(const unidirected_graph& graph, int n_sorg) {
    unidirected_graph albero;
    std::set<int> n_visitati;
    recursive_dfs_1(graph, n_sorg, n_visitati, albero);
    return albero;
};	
		
	
	
	