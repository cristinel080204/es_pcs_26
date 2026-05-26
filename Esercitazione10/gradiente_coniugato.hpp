#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

Eigen::VectorXd gradiente_coniugato(const int& n, const Eigen::MatrixXd& B, Eigen::VectorXd& x, const unsigned int& iter_max, const double& res_tol){
	
	Eigen::MatrixXd A = B.transpose() * B; //Creazione di una matrice simmetrica e def positiva che serve per il metodo del gradiente coniugato.
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //Soluzione di tutti 1
	Eigen::VectorXd b = A * x_ex; //Termine noto.
	Eigen::VectorXd res = b - A * x; //Residuo.
	double res_norm_0 = res.norm(); //Norma del primo residuo.
	unsigned int iter = 0 ; //Prima iterazione.
	Eigen::VectorXd p = res; // Definisco p che serve per le iterazioni
	double alpha_k = 0.0;
	double beta_k = 0.0;
	
	while ( iter < iter_max && res.norm() > res_tol * res_norm_0 ){ //Metodo del gradiente coniugato.
		alpha_k = ((p.transpose() * res)/(p.transpose() * A * p)).value();
		x = x + alpha_k * p;
		Eigen::VectorXd next_res = res - alpha_k * A *p;
		beta_k = ((p.transpose() * A * next_res)/(p.transpose() * A * p)).value();
		p = next_res - beta_k * p;
		res = next_res;
		iter++;
	};
	return x;
};