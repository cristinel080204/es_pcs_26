#include <iostream>
#include <fstream>
#include <string>
#include "unidirected_graph.hpp"

//Funzione che crea un file .dot che serve per GraphViz, per l'implementazione ho chiesto aiuto a intelligenza artificiale.

void scrittura_dot(const unidirected_graph& G, const std::string& nome_file) {
    std::ofstream file(nome_file); //
    if (!file.is_open()) return; 

    file << "graph G {\n";
	for (const auto& archi : G.all_edges()){
	    file << "   " << archi.from() << " -- " << archi.to() << "\n";
	}
	file << "}\n";
	file.close();
};