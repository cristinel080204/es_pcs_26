// Classe dei grafi.

#include <iostream>
#include <vector>
#include <set>
#include "unidirected_edge.hpp"

class unidirected_graph{
	
   std::set<unidirected_edge> edges;
   
 
public:
     unidirected_graph() {} //costruttore di default vuoto
	 unidirected_graph(const unidirected_graph& other){ //costruttore di copia
		 this-> edges = other.edges;
	 }

//Implemento il metodo add_edge()

void add_edge(const unidirected_edge& a_edge){
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

std::vector<unidirected_edge> all_edges() const{
	std::vector<unidirected_edge> archi;
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

int edge_number(const unidirected_edge& e) const{
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

unidirected_edge edge_at(size_t j) const{
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

unidirected_graph operator-(const unidirected_graph& other) const{
	unidirected_graph diff_graph;
	for (const auto& edge : edges){
		if(other.edges.find(edge) == other.edges.end()){	//Se non si trova un arco nell'altro grafo, lo aggiungo alla fine del primo.
	       diff_graph.add_edge(edge);
		   };
	};
	return diff_graph;
};
};
	
	
	

	 

	 
	 
	 