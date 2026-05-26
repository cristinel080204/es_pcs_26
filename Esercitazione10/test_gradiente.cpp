#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "gradiente_coniugato.hpp"

int main(){
	
    const double tol = 1.0e-15;
    unsigned int n = 3;
    const unsigned int iter_max = 10000;
	const double res_tol = 1.0e-12;
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	
	if (abs(B.determinant()) < tol)
    return -1; //Matrice singolare !

    Eigen::VectorXd x_sol = gradiente_coniugato(n, B, x, iter_max, res_tol); //Chiamo la funzione gradiente_coniugato
	
	const auto err_rel = (x_ex.norm() == 0.0) ? (x_sol - x_ex).norm() :
                                              (x_sol - x_ex).norm() / x_ex.norm(); //Verifica dell'errore.
  std::cout.precision(4);
  std::cout<< std::scientific<< "errore relativo"<< "\n";
  std::cout<< std::scientific<< err_rel<< "\n";
  std::cout<< std::scientific<< "soluzione"<< "\n";
  std::cout<< std::scientific<< x_sol << "\n";
    return 0;
};
