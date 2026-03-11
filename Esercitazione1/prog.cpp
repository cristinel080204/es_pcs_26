#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]){
	if (argc < 2){
		std::cerr << "Errore!";
	}
	else {
		std::cout << "Numero di parametri: " << argc << "\n";
        for (int i = 0; i < argc; i++) {
        std::cout << "Parametro " << i << " = " << argv[i] << "\n";
        }
		std::string file=argv[1];
	    std::ifstream ifs(file);
		}
 return 0;
}
