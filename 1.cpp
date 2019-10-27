#include <iostream>
#include <fstream>
#include <cmath>

using fptr = double(double);  
int bisection(double xl, double xu, double Delta, fptr f);
int regulafalsi(double xl, double xu, double Delta, fptr f);
int newton_raphson(double x0, double Delta, fptr f, fptr fderiv);
double fun(double x);
double gaux(double x);
double deriv(double x);

int main(void)
{
 std::ofstream fout("1.txt");
 fout.precision(15); fout.setf(std::ios::scientific);
 fout << "# EPS-Delta" << "\t        ";
 fout << "NBisect" << "\t";
 fout << "NFalsePos" << "\t";
 fout << "NNewton" << "\n";
  for (int ii=1; ii<= 9; ++ii)
    {
  double Delta = pow(10,-ii);
  double N = 0;
  fout << Delta << "\t  ";
  fout << bisection(0.1, 2.0, Delta, fun) <<"\t   ";
  fout << regulafalsi(0.1, 2.0, Delta, fun) << "\t         ";
  fout << newton_raphson(0.1, Delta, fun, deriv) << "\n";
  // std::cout << "Iter Bisection" << N << "\t";
  //N  = regulafalsi(1, 2, Delta, fun);
  //std::cout << "Iter RegulaFalsi"  << N << "\t";
  //N = newton_raphson(1, Delta, fun, deriv);
  //std::cout << "Iter Newton" << N  << "\n";
    }
  fout.close();
  return 0;
}

int bisection(double xl, double xu, double Delta, fptr f)
{
  double xr = xl;
  int N = 0;
  while(1) {
    xr=(xl+xu)/2;
    if (std::fabs(f(xr)) <= Delta) {
      break;
    }
    else if (f(xr)*f(xl) < 0) {
      xu = xr;
    }
    else {
      xl = xr;
    }
    N++;
  }

  return N;
}

//Para Regulafalsi y Biseccion, N inicia con 1

int regulafalsi(double xl, double xu, double Delta, fptr f)
{
  double xr = xl;
  int N = 1;
  while(1) {
    xr = xu - (f(xu)*(xl-xu))/(f(xl) -f(xu));
    if (std::fabs(f(xr)) <= Delta) {
      break;
    }
    else if (f(xr)*f(xl) < 0) {
      xu = xr;
    }
    else {
      xl = xr;
    }
    N++;
  }


  return N;
}

/*double fixedpoint(double x0, double Delta, fptr f, fptr g)
{
  double xr = x0;
  int N = 1;
  while(1) {
    if (std::fabs(f(xr)) <= Delta) {
      break;
    }
    xr = g(xr);
    N++;
  }
  return N;
  }*/

double fun(double x)
{
  return 3*(1/exp(x)) - x;
}

double gaux(double x)
{
  return 3*(1/exp(x)) - x;
}
int newton_raphson(double x0, double Delta, fptr f, fptr fderiv)
{
  double xr = x0;
  int N = 0;
  while(1) {
    if (std::fabs(f(xr)) <= Delta) {
      break;
    }
    xr = xr - f(xr)/fderiv(xr);
    N++;
  }
  
  return N;
}

//Para Newton Inicia con N=0

double deriv(double x)
{
  return -3*(1/exp(x)) - 1;
}
