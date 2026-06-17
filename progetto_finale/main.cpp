#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "creazione_grafo.hpp"
#include "creazione_circuito.hpp"
#include "DFS.hpp"
#include "de_pina.hpp"
#include "ordinamento.hpp"
#include "matrice_incidenza.hpp"
#include <Eigen/Dense>

int main(){
	
    //Apertura file e netlist.
    
	std::string filename = "Dati.txt"; 
	std::ifstream ifs(filename);

	if (!ifs.is_open()){
		std::cerr << "Riprovare, si è verificato un errore nell'apertura del file" << "\n"; 
	}; 
    std::string rv = "";
	float val = 0.0f;
	int nodo1 = 0;
	int nodo2 = 0;
	std::map<std::string,Dati> netlist;
	
	std::vector<std::pair<std::string,float>> resistori;
	std::vector<std::pair<int,int>> nodi_res;
	std::map<std::pair<int,int>,float> generatori;
	
	while (ifs >> rv >> val >> nodo1 >> nodo2){ 	
		netlist[rv]={val,nodo1,nodo2};
		if (rv.starts_with("V")) {
			generatori[{nodo1,nodo2}]= val;
		}; 
		if (rv.starts_with("R")){
			resistori.push_back({rv,val});
			nodi_res.push_back({nodo1,nodo2});
		}; 
    };
	
	for (const auto& [chiave,valori] : netlist) {
		std::cout << chiave << " " << valori.val << "\t" << valori.nodo1 << " " << valori.nodo2 << "\n"; 
	};
	
	//Creazione grafo G,T,C.
	
	creazione_grafo G;
	G = circuito(netlist);
	std::vector<arco> archi = G.all_edges();
	
	lifo<int> pila;
	creazione_grafo T = graph_visit(G, 1, pila);
	creazione_grafo C = G - T;
	
	int k = G.all_edges().size()-G.all_nodes().size()+1;
	int num_nodi = G.all_nodes().size();
	int num_archi = G.all_edges().size();
	
	std::cout << "Numero di cicli minimi :" << k << "\n";
	
	//Cicli minimi De Pina e Ordinamento.
	
	std::vector<std::vector<bool>> S(k,std::vector<bool>(num_archi,false));
	for (int i=0; i<k; i++){
		int arco_attivo = G.edge_number(C.all_edges()[i]);
	        S[i][arco_attivo]=true;
	};
	
	int n1; //Primo termine del pair nel ciclo di de pina
	int n2; //Secondo termine del pair nel ciclo di de pina
	
    std::vector<std::list<std::pair<int,int>>> cicli_non_ordinati(k);
	std::vector<std::list<std::pair<int,int>>> cicli_ordinati(k);
	
	std::vector<std::vector<bool>> base_cicli = de_pina(num_nodi,num_archi,archi,S,k);
	for(int n = 0; n < k; n++){
		std::list<std::pair<int,int>> list;
		for(int d = 0; d < num_archi; d++){
			if(base_cicli[n][d]){
				n1 = archi[d].from();
				n2 = archi[d].to();
				std::pair<int,int> dp_nodi = {n1,n2};
				list.push_back(dp_nodi);
            };
		};
		cicli_non_ordinati[n] = list;
	};
	
    for (int j=0; j<k; j++){
		cicli_ordinati[j] = ordinamento(cicli_non_ordinati[j]);
	};
	
   // Matrici e Sistema Lineare.
   
   Eigen::MatrixXd R = Eigen::MatrixXd::Zero(resistori.size(),resistori.size());
   for (size_t r = 0; r < resistori.size(); r++){
	   R(r,r) = resistori[r].second;
   };
   
   Eigen::MatrixXd B = matrice_incidenza(nodi_res, cicli_ordinati);
   Eigen::VectorXd V = vettore_gen(generatori, cicli_ordinati);
   
   //Costruisco il sistema lineare e la soluzione con il gradiente coniugato.
   Eigen::MatrixXd A = B.transpose() * R * B; 
   Eigen::VectorXd Im = Eigen::VectorXd::Zero(V.size()); //Inizializzo soluzione a 0
   Eigen::VectorXd residuo = V - A*Im; //Vettore residuo
   
   int iter_max = 10000; //Massima iterazione
   double residuo_tol = 1e-10; //Tolleranza del residuo
   double residuo_norm_0 = residuo.norm(); //Norma del primo residuo.
   int iter = 0 ; //Prima iterazione.
   Eigen::VectorXd p = residuo; // Definisco p che serve per le iterazioni
   double alpha_k = 0.0;
   double beta_k = 0.0;
   
   while (iter < iter_max && residuo.norm() > residuo_tol * residuo_norm_0 ){ //Metodo del gradiente coniugato.
		alpha_k = ((p.transpose() * residuo)/(p.transpose() * A * p)).value();
		Im = Im + alpha_k * p;
		Eigen::VectorXd next_residuo = residuo - alpha_k * A *p;
		beta_k = ((p.transpose() * A * next_residuo)/(p.transpose() * A * p)).value();
		p = next_residuo - beta_k * p;
		residuo = next_residuo;
		iter++;
	};
	
   Eigen::VectorXd VR = R * B * Im;
   
   std::cout << "Risultati finali: " << "\n";
   for (size_t i=0; i < resistori.size(); i++){
	   std::cout<< "Tensione su " << resistori[i].first << " (" << resistori[i].second << " Ohm): " << VR(i) << "V \n";
   };
   
   return 0;
};

