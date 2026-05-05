#include <iostream>
#include <vector>
#include <chrono> 
#include <algorithm> //serve per std::sort()
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main () 
{
	randfiller rf; //Chiamo la funzione per riempire di numeri casuali
	timecounter tc; //Chiamo la funzione per calcolare i tempi di ordinamento
	int num_vec = 100;
	int val_soglia = 0;
	for (int n=1; n<=100; n++){
	  std::vector<std::vector<int>> vectors(num_vec, std::vector<int>(n));
	  for (auto& vec : vectors){  //sintassi per vettori di vettori
	     rf.fill(vec,-1500,1500);
	  };
	  
	  std::vector<std::vector<int>> vec_bubble = vectors; //Copio i vettori per i vari ordinamenti.
	  std::vector<std::vector<int>> vec_insertion = vectors;
	  std::vector<std::vector<int>> vec_selection = vectors;
	  std::vector<std::vector<int>> vec_merge = vectors;
	  std::vector<std::vector<int>> vec_quick = vectors;
	  std::vector<std::vector<int>> vec_altro = vectors;
	
	//Analizziamo i tempi di ordinamento
	
	tc.tic();
	for (int i=0; i<100; i++){
	  bubblesort(vec_bubble[i]);
	};
     double t_bubble = tc.toc();
	 std::cout<< "Media Bubble: " << t_bubble / 100 << "\n";
	
	 
	tc.tic();
	for (int i=0; i<100; i++){
	  insertionsort(vec_insertion[i]);
	};
     double t_insertion = tc.toc();
	 std::cout<< "Media Insertion: " << t_insertion / 100 << "\n";
	 
	 
    tc.tic();
	for (int i=0; i<100; i++){
	  selectionsort(vec_selection[i]);
	};
     double t_selection = tc.toc();
	 std::cout<< "Media Selection: " << t_selection / 100 << "\n";
	 
	 
	tc.tic();
	for (int i=0; i<100; i++){
	  mergesort(vec_merge[i], 0, vec_merge[i].size()-1);
	};
     double t_merge = tc.toc();
	 std::cout<< "Media Mergesort: " << t_merge / 100 << "\n";
	 
	 
	tc.tic();
	for (int i=0; i<100; i++){
	  quicksort(vec_quick[i], 0, vec_quick[i].size()-1);
	};
     double t_quick = tc.toc();
	 std::cout<< "Media Quicksort: " << t_quick / 100 << "\n";
	 

	tc.tic();
	for (int i=0; i<100; i++){
	  std::sort(vec_altro[i].begin(), vec_altro[i].end());
	};
     double t_altro = tc.toc();
	 std::cout<< "Media Sort Standard: " << t_altro / 100 << "\n";
	 
	if (val_soglia == 0 && t_quick < t_insertion && n > 2){
		val_soglia = n;
	};
	 std::cout << "Valore di soglia è: " << val_soglia << "\n";
	 
};

	return 0;
};