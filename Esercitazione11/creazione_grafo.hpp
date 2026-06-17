#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "creazione_arco.hpp"
#include "dati.hpp"

class creazione_grafo{
	
   std::set<arco> edges;
   
 
public:
     creazione_grafo() {} //costruttore di default vuoto
	 creazione_grafo(const creazione_grafo& other){ //costruttore di copia
		 this-> edges = other.edges;
	 }

//Implemento il metodo add_edge()

void add_edge(const arco& a_edge){
	edges.insert(a_edge); 
};

//Implemento il metodo neighbours()

std::vector<int> neighbours(int v) const{
	std::vector<int> vicini;
	for (const auto& edge : edges){
		if(edge.from() == v){
			vicini.push_back(edge.to());
		}else if (edge.to() == v) {
			vicini.push_back(edge.from());
		};
	};
	return vicini;
};

//Implemento il metodo all_edges()

std::vector<arco> all_edges() const{
	std::vector<arco> archi;
	for(const auto& edge : edges){
	    archi.push_back(edge);
	};
	return archi;
};

//Implemento il metodo all_nodes()

std::vector<int> all_nodes() const{
	std::set<int> nodi; 
	for(const auto& edge : edges){
		nodi.insert(edge.from());
		nodi.insert(edge.to());
	};
	return std::vector<int> (nodi.begin(),nodi.end());
};

//Implemento il metodo edge_number()

int edge_number(const arco& e) const{
	int i = 0;
	for (const auto& edge : edges){
		if (edge == e){
			return i;
		};
	    i++;
	}
	return -1; //se non ho trovato l'arco in questione
};

//Implemento il metodo edge_at()

arco edge_at(size_t j) const{
    size_t k=0;
	for (const auto& edge: edges){
		if(k == j){
			return edge;
		};
		k++;
	};
	throw std::out_of_range("L'indice è troppo grande");  //Uso per questo caso, controllo dell'errore.
};

//Implemento l'operazione -

creazione_grafo operator-(const creazione_grafo& other) const{
	creazione_grafo diff_graph;
	for (const auto& edge : edges){
		if(other.edges.find(edge) == other.edges.end()){	//Se non si trova un arco nell'altro grafo, lo aggiungo alla fine del primo.
	       diff_graph.add_edge(edge);
		   };
	};
	return diff_graph;
};
};