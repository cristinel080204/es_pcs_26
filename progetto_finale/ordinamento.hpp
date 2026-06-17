#include<iostream>
#include<list>
#include<utility>

std::list<std::pair<int,int>> ordinamento(std::list<std::pair<int,int>> archi_pina){ 
	auto arc = archi_pina.front();
	std::list<std::pair<int,int>> archi_ord;
	archi_ord.push_front(arc);
	archi_pina.remove(arc);
	while(!archi_pina.empty()){
		for (auto i : archi_pina){
			if (arc.second == i.second){
				std::pair<int,int> j;
				j.first = i.second;
				j.second = i.first;
				archi_ord.push_back(j); 
				arc = j;
				archi_pina.remove(i);
			    break;
			}else if (arc.second == i.first){
				 archi_ord.push_back(i);
				 arc = i;
				 archi_pina.remove(i);
				 break;
			};
		};
	};
	return archi_ord;
};