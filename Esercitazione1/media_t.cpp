#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(void){
        std::string input_es1= "input_es1.txt";
        std::ifstream ifs(input_es1);
        while (!ifs.eof()){
	        std::string location;
	        double temp1,temp2,temp3,temp4;
	        ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
	        double media = (temp1+temp2+temp3+temp4)/4.0;
	        std::cout <<location << " " << media << std::endl;
        }
		return 0;
}