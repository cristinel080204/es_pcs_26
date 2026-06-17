#include <iostream>
#include <list>
#include <utility>
#include <Eigen/Dense>
                                                                                                   
Eigen::MatrixXd matrice_incidenza (std::vector<std::pair<int,int>>& archi_direzione_file, std::vector<std::list<std::pair<int,int>>>& cicli_pina){
//
int n = cicli_pina.size();
int m = archi_direzione_file.size();

	Eigen::MatrixXd B = Eigen::MatrixXd::Zero(m, n);
	
	std::map<std::pair<int,int>,int> mappa_direzioni; 
	for (size_t k = 0; k < archi_direzione_file.size(); k++){
		int n_min = std::min(archi_direzione_file[k].first, archi_direzione_file[k].second);
		int n_max = std::max(archi_direzione_file[k].first, archi_direzione_file[k].second);
		mappa_direzioni[{n_min,n_max}] = k;
	};
	
	for(int i=0; i<n; i++){
		for(auto& arcop : cicli_pina[i]){
			int u = arcop.first;
			int v = arcop.second;
			if (u < v){ //Se u è minore di v, quindi è concorde con i pair in mappa_direzioni che sono ordinati allora dai contributo 1
			    auto iter_concorde = mappa_direzioni.find({u,v});
			    if (iter_concorde != mappa_direzioni.end()){
				    int riga = iter_concorde->second;
				    B(riga,i) = 1.0;
			    };
			}else{ // Se u è maggiore di v, quindi discorde con i pair dai contributo -1.
				auto iter_discorde = mappa_direzioni.find({v,u});
				if (iter_discorde != mappa_direzioni.end()){
					int riga = iter_discorde->second;
					B(riga,i) = -1.0;
				};
			};
		};
	};
	return B;
};

Eigen::MatrixXd vettore_gen (std::map<std::pair<int,int>,float> map_gen, std::vector<std::list<std::pair<int,int>>>& cicli_pina){
	int n = cicli_pina.size();
	Eigen::VectorXd V = Eigen::VectorXd::Zero(n);
	for(int i = 0; i<n ; i++){
		for(auto& arcop : cicli_pina[i]){
			int u = arcop.first;
			int v = arcop.second;
			auto iter_concorde = map_gen.find({u,v});
			if (iter_concorde != map_gen.end()){
			    V(i) += (iter_concorde->second)*(-1); //Cambio da *1 a *(-1) perchè passare da + a - da contributo NEGATIVO
			} else{
				auto iter_discorde = map_gen.find({v,u});
				if (iter_discorde != map_gen.end()){
                V(i) += (iter_discorde->second)*1;
				};
			};
		};
	};
	return V;
};

	
	
