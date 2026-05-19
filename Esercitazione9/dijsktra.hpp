#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include "fifo_lifo.hpp"
#include "unidirected_graph.hpp"

unidirected_graph dijkstra(const unidirected_graph& graph, int n_sorg) {
    unidirected_graph albero;
    std::map<int, double> distanza; //inizializzo le distanze minime che dovrò cercare
    std::map<int, int> padre; //nodi padre

    for (int nodi : graph.all_nodes()){ //per i nodi del grafo
	distanza[n_sorg] = 0; //distanza dal nodo sorgente inizialmente =0
    distanza[nodi] = std::numeric_limits<double>::infinity(); //imposto la distanza infinito per gli altri nodi inizialmente
	};
	
  
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq; //implemento la priority queue che mi indica la distanza (primo elemento) dal nodo (secondo elemento)
    // std::pair mi permette di accoppiare due elementi qualsiasi, mentre la priority queue mi permette di ordinare i nodi in base alla distanza in questo caso, tenendo sempre il nodo con il cammino minimo grazie a std::greater che consente
	// di estrarre prima i valori più bassi
	pq.push({0, n_sorg}); //Fisso subito la distanza =0 per il nodo sorgente da se stesso

    while (!pq.empty()) {
        int u = pq.top().second; //.second per la struttura pair
        double d = pq.top().first; //.first per la struttura pair
        pq.pop();

        if (d > distanza[u]) continue;

        for (int v : graph.neighbours(u)) {
            double peso = 1.0; // Assumo peso 1 in questo caso, dato che dijsktra ha bisogno dei pesi di un arco.
            if (distanza[v] > distanza[u] + peso) {
                distanza[v] = distanza[u] + peso;
                padre[v] = u;
                pq.push({distanza[v], v});
            };
        };
    };

    for (auto const& [node, p] : padre) { //costruisco l'albero 
        albero.add_edge(unidirected_edge(p, node));
    };
    return albero;
};