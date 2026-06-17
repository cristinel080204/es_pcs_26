#include <iostream>
#include <map>
#include <string>
#include "creazione_grafo.hpp"

creazione_grafo circuito(auto& netlist){
                creazione_grafo grafo;
				for (const auto& [arc,dati]: netlist){
					grafo.add_edge(arco(dati.nodo1, dati.nodo2));
                };
				return grafo;
};