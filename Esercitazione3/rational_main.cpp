#include <iostream>
#include <cmath>
#include "rational.hpp"

int main(){
	//Verifico la buona definizione e le operazioni nel caso den_!=0 e/o num!=0.
  rational<int> r1(2,4);
  rational<int> r2(12,9);
  rational<int> r3 = r1 + r2;
  rational<int> r4 = r1 - r2;
  rational<int> r5 = r1 * r2;
  rational<int> r6 = r1 / r2;
  rational<int> r7 = (r1 * r3)/(r2 - r4) + r6;
  
  std::cout<< "Caso buono" << "\n";
  std::cout<< r1 << " "<< r2 << "\n";
  std::cout<< r3 << "\n";
  std::cout<< r4 << "\n";
  std::cout<< r5 << "\n";
  std::cout<< r6 << "\n";
  std::cout<< r7 << "\n";
  std::cout<< "\n";
  
   //Analizzo i casi particolari di Inf e NaN e le operazioni con essi.
  rational<int> r8(145,0);
  rational<int> r9(0,0);
  rational<int> r10 = r8 + r9;
  rational<int> r11 = r8 - r9;
  rational<int> r12 = r8 * r9;
  rational<int> r13 = r8 / r9;
  
  std::cout<< "Caso estremo" << "\n";
  std::cout<< r8 << " "<< r9 << "\n";
  std::cout<< r10 << "\n";
  std::cout<< r11 << "\n";
  std::cout<< r12 << "\n";
  std::cout<< r13 << "\n";
  std::cout<< "\n";
  
  //Controllo funzioni num() e den()
  int n2 = r2.num();
  int n7 = r7.num();
  int d10 = r10.den();
  int d6 = r6.den();
  
  std::cout<< n2 << " " << n7 << " " << d10 << " " << d6 << "\n";
  
  return 0;
}