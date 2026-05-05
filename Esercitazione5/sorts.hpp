#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>
#include <optional>

//Mettiamo i sorts tutti assieme.
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

//Serve la funzione Merge;

template<typename T>
void merge(std::vector<T>& vec, size_t p, size_t q, size_t r)
{
	size_t n1 = q-p+1;
	size_t n2 = r-q;
	std::vector<T> arrL(n1);
	std::vector<T> arrR(n2);
	for (size_t i=0; i<n1; i++){
		arrL[i]=vec[p+i];
	};
	for (size_t j=0; j<n2; j++){
		arrR[j]=vec[q+1+j];
	};
	size_t i=0;
	size_t j=0;
	size_t k=p;
	while (i<n1 && j<n2){ //Uso i while per controllare meglio anche la presenza di stringhe all'interno del vettore
		if (arrL[i]<=arrR[j]){
			vec[k]=arrL[i];
			i=i+1;
		}else{
			vec[k]=arrR[j];
			j=j+1;
		};
		k=k+1;
	};
	while(i<n1){
		vec[k]=arrL[i];
		i=i+1;
		k=k+1;
	};
	while(j<n2){
		vec[k]=arrR[j];
		j=j+1;
		k=k+1;
	};
};

//Implementiamo la funzione Mergesort;

template<typename T>
void mergesort(std::vector<T>& vec, size_t p, size_t r)
{
	if (p < r){
		size_t q = p + (r-p)/2;
		mergesort(vec, p, q);
		mergesort(vec, q+1, r);
		merge(vec, p, q, r);
	};
};

//Serve la funzione Partition;

template<typename T>
int partition(std::vector<T>& vec, int p, int r)
{
	T x = vec[r];
	int i = p-1;
	for (int j=p; j<r; j++){
		if (vec[j] <= x){
			i=i+1;
			std::swap(vec[i],vec[j]);
		};
	};
	std::swap(vec[i+1],vec[r]);
	return i+1;
};

//Implementiamo la funzione Quicksort

template<typename T>
void quicksort(std::vector<T>& vec, int p, int r)
{
	if (p < r){
		int q = partition(vec, p, r);
		quicksort(vec, p, q-1);
		quicksort(vec, q+1, r);
	};
};

//Definisco una nuova funzione Insertionsort Parziale per la forma modificata del Quicksort

template<typename T>
void insertionsort_parziale(std::vector<T>& vec, int p, int r) //Restringiamo l'ordinamento in un intervallo [p,r].
{
		for (size_t j = p + 1; j < r; j++){ //Partiamo da p+1 non più da 1, e arriviamo fino a r
		T val = vec[j];
		int i = j-1;
		while (i >= p && vec[i] > val){
			   vec[i+1]=vec[i];
			   i=i-1;
			};
		vec[i+1]=val;
	};
};

//Modifico la funzione Quicksort con Insertion e il val_soglia

template<typename T>
void quick_ins_sort(std::vector<T>& vec, int p, int r, int val_soglia)
{
	if (p < r){
		int dim_part = r - p + 1;
		if (dim_part < val_soglia){
			insertionsort_parziale(vec, p, r);
		}else{
			int q = partition(vec, p, r);
			quick_ins_sort(vec, p, q-1, val_soglia);
			quick_ins_sort(vec, q+1, r, val_soglia);
		};
	};
};
	
	
	