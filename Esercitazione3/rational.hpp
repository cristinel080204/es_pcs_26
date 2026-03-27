#include <iostream>
#include <concepts>
#include <cmath>
#include <numeric> //L'ho inclusa per la funzione che mi calcola il massimo comune divisore
template <typename I>
requires std::integral<I>
class rational
{
   I num_;
   I den_;
   
   void simplify (){ //implementiamo la semplificazione della frazione
      if (den_== 0 && num_== 0){
		  return;
	  }else if (den_==0 && num_ !=0){
	      return;
	  };
	  if (den_ != 0){ //cerchiamo un massimo comune divisore da semplificare
		 I MCD = std::gcd(num_, den_);
		 if (MCD !=0){
		 num_ = num_ / MCD;
		 den_ = den_ / MCD;
		 };
	  };
   };
	   
public:
   bool Inf() const {return den_ == 0 && num_!=0; }; //Definisco Inf
   bool NaN() const {return den_ == 0 && num_ == 0; }; //Definisco NaN
   rational()
           :num_(I{0}), den_(I{1}) //Inizializziamo a 0 e 1 i num e den
	{}
   
   rational(const I& n, const I& d):
   num_(n), den_(d){
      simplify(); //semplifica quando possibile dopo aver messo i num e den
   }
   
   I num() const {return num_;}
   I den() const {return den_;}
 //Scrivo le operazioni
   rational& operator+=(const rational& other) { //Incremento
	   if (NaN() || other.NaN()){ //Se sono NaN restituisce NaN
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   
	   if (Inf() || other.Inf()){ //Se sono Inf restituisce Inf
		   num_=other.num_;
		   den_=0;
		   return *this;
	   };
	   
	   num_= num_ * other.den_ + other.num_ * den_;
	   den_ = den_ * other.den_;
	   simplify();
	   return *this;
   };
   
   rational operator+(const rational& other) const{ //Somma
	   rational ret = *this;
	   ret += other;
	   return ret;
   };
   
   rational& operator*=(const rational& other){
	   if (NaN() || other.NaN()){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   if ((num_==0 && other.Inf()) || (Inf() && other.num_==0)){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   num_= num_ * other.num_;
	   den_= den_ * other.den_;
	   simplify();
	   return *this;
   };
    rational operator*(const rational& other) const{ //Prodotto
		rational ret = *this;
		ret *= other;
		return ret;
	};
	rational& operator-=(const rational& other) {
	   if (NaN() || other.NaN()){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   
	   if (Inf() || other.Inf()){
		   num_=other.num_;
		   den_=0;
		   return *this;
	   };
	   
	   if (Inf() && other.Inf() || NaN() && other.Inf()){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   
	   num_= num_ * other.den_ - other.num_ * den_;
	   den_ = den_ * other.den_;
	   simplify();
	   return *this;
   };
   rational operator-(const rational& other) const{ //Sottrazione
	   rational ret = *this;
	   ret -= other;
	   return ret;
   };
   rational& operator/=(const rational& other){
	   if ((NaN() || other.NaN()) && (Inf() && other.Inf())){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   if ((num_==0 && other.Inf()) || (Inf() && other.num_==0)){
		   num_=0;
		   den_=0;
		   return *this;
	   };
	   if (num_!=0 && other.Inf()){
		   num_= 0;
		   den_= 1;
		   return *this;
	   };
	   if (num_!=0 && den_==0){
		   num_= other.num_;
		   den_ =0;
		   return *this;
	   };
		   
	   num_= num_ * other.den_;
	   den_= den_ * other.num_;
	   simplify();
	   return *this;
   };
    rational operator/(const rational& other) const{ //Divisione
		rational ret = *this;
		ret /= other;
		return ret;
	};
};
template<typename I>
 std::ostream&
 operator<<(std::ostream& os, const rational<I>& r){
	 if(r.NaN()){
		 os << "NaN";
	 }else if(r.Inf()){
		 os << "Inf";
	 }else {
		 os << r.num() << "/" << r.den();
	 };
	 return os;
 };
