#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //Uso per la funzione rand()
#include "randfiller.h"
#include "sorts.hpp"

int main ()
{
	randfiller rf; //Chiamo la funzione per riempire di numeri casuali
	
	for (int i=0; i<100; i++){ //Implemento un ciclo per creare 100 vettori da testare
	  int dim = rand() % 150; //Dimensione casuale dei vettori, che limito per memoria
	  std::vector<int> vec(dim); //Inizializzo i vettori con dimensioni casuali
	  rf.fill(vec,-1500,1500);
	  bubblesort(vec); //Effettuiamo l'ordinamento bubblesort
	  if(!is_sorted(vec)){ //Se non è ordinato, dimmelo
		  return EXIT_FAILURE;
	  };
	};
	
	std::vector<std::string> vecs = {"Fragole", "Gelato", "Fiori", "Uccello", "Angelo", "Zecca", "Numeri", "Elodie", "Verde", "Autunno"};
	bubblesort(vecs);
	if(!is_sorted(vecs)){
		return EXIT_FAILURE;
	};
	return EXIT_SUCCESS;
};