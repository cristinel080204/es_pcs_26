#pragma once
#include <iostream>
#include <set>
#include <map>
#include "creazione_grafo.hpp"
#include "fifo_lifo.hpp"

template <typename contenitore>
creazione_grafo graph_visit(const creazione_grafo& graph, int n_sorg, contenitore& c){
	
	creazione_grafo albero; //l'albero che deve dare in output
	std::set<int> n_visitati; //inizializzo un set di interi, di nodi che saranno visitati
	c.put(n_sorg); //in particolare metto il nodo sorgente nel contenitore
	n_visitati.insert(n_sorg); //il primo nodo visitato è proprio quello sorgente
	
	while(!c.empty()){ //Visita BFS o DFS in base al contenitore che viene passato
	    int u = c.get();
		for(int nodo : graph.neighbours(u)){
			if(n_visitati.find(nodo) == n_visitati.end()){ //Se il nodo vicino non è presente lo inseriamo nei visitati
			   n_visitati.insert(nodo);
               albero.add_edge(arco(u, nodo));//Costruisco l'albero
			   c.put(nodo);
			};			   
		};
	};
	return albero;
};

template<typename contenitore>
bool find_path(creazione_grafo graph, int u, int v, contenitore& path, std::set<int>& n_visitati){
	path.put(u);
	n_visitati.insert(u);
	if (u==v) {
		return true;
	};
	for (int nodo : graph.neighbours(u)){
		if(n_visitati.find(nodo) == n_visitati.end()){
			if (find_path(graph, nodo, v, path, n_visitati)){
				return true;
				};
			};
		};
	path.get();
	return false;
};
	