#include <iostream>
#include <cmath>

int main()
{
	static const int N = 3;
	double arr[N] = {1.23, 2.34, 3.45};
	double M = arr[0];
	double m = arr[0];
	double somma;
	double media;
	double somma2;
	double dev_stad;
	for (int i=0; i<N; i++){
		if (arr[i]>=M){
		     M = arr[i];
		}
		if (arr[i]<=m){
		     m = arr[i];
		}
	somma += arr[i];
    media = somma/N;
	somma2 += (arr[i]-media)*(arr[i]-media);
	dev_stad = std::sqrt(somma2/(N-1));
	}
	
	std::cout << "Il massimo è " << M << "\n";
	std::cout << "Il minimo è " << m << "\n";
	std::cout << "La media è " << media << "\n";
	std::cout << "La deviazione standard è " << dev_stad << "\n";
	return 0;
}
	
	