#include <iostream>
#include <vector>
#include <chrono> 
#include <algorithm> //serve per std::sort()
#include "sort.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main ()
{
	randfiller rf; //Chiamo la funzione per riempire di numeri casuali
	timecounter tc; //Chiamo la funzione per calcolare i tempi di ordinamento
	for (int n=4; n<=8192; n*=2){
	  std::vector<int> vec(n);
	  rf.fill(vec,-1500,1500);
	  
	  std::vector<int> vec_bubble = vec; //Copio i vettori per i vari ordinamenti.
	  std::vector<int> vec_insertion = vec;
	  std::vector<int> vec_selection = vec;
	  std::vector<int> vec_altro = vec;
	  
	  tc.tic(); //Analizziamo i tempi di ordinamento
	  bubblesort(vec_bubble);
      double t_bubble = tc.toc();
	
	  tc.tic();
	  insertionsort(vec_insertion);
	  double t_insertion = tc.toc();
	  
	  tc.tic();
	  selectionsort(vec_selection);
	  double t_selection = tc.toc();
	  
	  tc.tic();
	  std::sort(vec.begin(),vec.end()); //è un altro ordinamento
	  double t_altro = tc.toc();
	  
	std::cout << "Bubble: " << t_bubble << "\n";
	std::cout << "Insertion: " << t_insertion << "\n";
	std::cout << "Selection: " << t_selection << "\n";
	std::cout << "Altro : " << t_altro << "\n";
	};
	
	return 0;
};