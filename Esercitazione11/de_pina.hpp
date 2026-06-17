#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include "creazione_grafo.hpp"

bool dotproduct(std::vector<bool>& S1, std::vector<bool>& S2){
	bool result = false;
	for (size_t i = 0; i < S1.size(); i++){
		if(S1[i] && S2[i]){
		   result = !result; //XOR
		};
	};
	return result;
};

std::vector<bool> find_minimal_cycle(int num_nodi, int num_archi, std::vector<arco>& archi, std::vector<bool>& Si){
	int best_size = std::numeric_limits<int>::max();
	std::vector<bool> best_cycle(num_archi, false);
	
	for (int w = 0; w < num_nodi; w++){
		std::vector<std::vector<lifting_edge>> lifting_graph (2 * (num_nodi+1)); //Dimensione maggiore per avere tutti i nodi raddoppiati.
		
		for(int i = 0; i < num_archi; i++){
			
			int u = archi[i].from();
			int v = archi[i].to();
			
			int u_plus = 2*u;
			int u_minus = (2*u)+1;
			int v_plus = 2*v;
			int v_minus = (2*v)+1;
			
			if (Si[i]){
			   lifting_graph[u_plus].push_back({v_minus,i});
			   lifting_graph[v_minus].push_back({u_plus,i});
			   lifting_graph[u_minus].push_back({v_plus,i});
			   lifting_graph[v_plus].push_back({u_minus,i});
			}else{
			   lifting_graph[u_plus].push_back({v_plus,i});
			   lifting_graph[v_minus].push_back({u_minus,i});
			   lifting_graph[u_minus].push_back({v_minus,i});
			   lifting_graph[v_plus].push_back({u_plus,i});
			   
			};
		};
		
		int first_node = 2*w; // 1+
		int last_node = 2*w + 1; // 1-
		
		std::map<int,double> distanza;
		std::map<int,int> nodi_padre;
		std::map<int,int> arco_visitato;
		
		for(int j = 0; j < 2*(num_nodi+1) ; j++){
			distanza[j] = std::numeric_limits<double>::infinity();
		};
		
		distanza[first_node] = 0.0;
		
		std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
	    pq.push({0.0, first_node});

    while (!pq.empty()) {
        int u_corrente = pq.top().second;
        double d = pq.top().first;
        pq.pop();

        if(d > distanza[u_corrente]) continue;
		if(u_corrente == last_node) break;
		
		for(const auto& arco : lifting_graph[u_corrente]){
			int next_node = arco.to_nodo;
			double peso = 1.0;
			
			if(distanza[next_node] > distanza[u_corrente] + peso){
				distanza[next_node] = distanza[u_corrente] + peso;
		        nodi_padre[next_node] = u_corrente;
				arco_visitato[next_node] = arco.indice_arco;
				pq.push({distanza[next_node],next_node});
			};
		};
	};
	if(distanza[last_node] != std::numeric_limits<double>::infinity()){
		std::vector<bool> ciclo_corrente(num_archi, false);
	    int target = last_node;
		
		while(target != first_node){
			int origine = arco_visitato[target];
			ciclo_corrente[origine] = !ciclo_corrente[origine];
			target = nodi_padre[target];
		};
		
		if(distanza[last_node] < best_size){
			best_size = distanza[last_node];
			best_cycle = ciclo_corrente;
		};
	};
};
	return best_cycle;
};

		
std::vector<std::vector<bool>> de_pina(int num_nodi, int num_archi, std::vector<arco>& archi, std::vector<std::vector<bool>>& S, int k){
	std::vector<std::vector<bool>> B;
	
	for(int i=0; i < k; i++){
		std::vector<bool> Ci = find_minimal_cycle(num_nodi, num_archi, archi, S[i]);
		B.push_back(Ci);
		
		for(int j=i+1; j < k; j++){
			if(dotproduct(Ci,S[j])){
				for(int a = 0; a < num_archi; a++){
					S[j][a]=S[j][a] ^ S[i][a];
				};
			};
		};
	};
	return B;
};