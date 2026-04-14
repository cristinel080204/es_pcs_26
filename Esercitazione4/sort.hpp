#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>
#include <optional>

//Mettiamo i sorted tutti assieme.
//Iniziamo dalla funzione is_sorted, per dirci se il vettore sarà ordinato o no.

template<typename T>
bool is_sorted(const std::vector<T>& vec){
	if (vec.size()==0){
		return {}; //Se il vettore non ha elementi allora ritorna niente.
	};
	for (size_t i = 0; i < (vec.size()-1); i++){ 
		if (vec[i]>vec[i+1]){
		     return false;
		   };
	    };
	return true;
};

//Implementiamo la funzione Bubblesort;

template<typename T>
void bubblesort(std::vector<T>& vec)
{
	for (size_t i=0; i < vec.size(); i++){ 
		for (size_t j= (vec.size()-1); j > i; j--){ 
			if (vec[j] < vec[j-1]){
				std::swap(vec[j],vec[j-1]);
			};
		};
	};
};

//Implementiamo la funzione Insertionsort;

template<typename T>
void insertionsort(std::vector<T>& vec)
{
	for (size_t j=1; j < vec.size(); j++){ 
		T val = vec[j];
		int i = j-1;
		while (i >= 0 && vec[i] > val){
			   vec[i+1]=vec[i];
			   i=i-1;
			};
		vec[i+1]=val;
	};
};

//Implementiamo la funzione Selectionsort;

template<typename T>
void selectionsort(std::vector<T>& vec)
{
	for (size_t i=0; i < (vec.size()-1); i++){ 
		size_t min = i;
		for (size_t j=i+1; j < vec.size(); j++){ 
			if (vec[j]<vec[min]){
				min=j;
			};
		};
		std::swap(vec[i],vec[min]);
	};
};

