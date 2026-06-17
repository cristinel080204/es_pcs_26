#pragma once
#include <iostream>
#include <algorithm>

class arco{
//Fisso i nodi

    int i_from;
	int i_to;
	
public: //Scrivo cosa vuol dire arco
    arco(int v1, int v2){ //Il primo nodo deve essere sempre il più piccolo
	i_from = std::min(v1,v2);
	i_to = std::max(v1,v2);
	};
	
//Implemento i metodi from() e to() che restituiscono i due nodi

int from() const{
	return i_from;
};

int to() const{
	return i_to;
};

//Implemento gli operatori necessari

bool operator<(const arco& other) const{
	 if (i_from != other.i_from){
		return i_from < other.i_from; 
	 };
	 return i_to < other.i_to; 
}

bool operator==(const arco& other) const{
	 return(i_from == other.i_from && i_to == other.i_to); //Ritorna che v1.1 = v1.2 e che v2.1 = v2.2
}


friend std::ostream& //Aggiungo friend in modo da tenerlo nella classe
operator<<(std::ostream& os, const arco& edge){
	os << "(" << edge.i_from << "," << edge.i_to << ")"; //Stampa l'arco come (v1,v2)
	return os;
}
};