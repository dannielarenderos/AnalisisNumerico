#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs

#include <iomanip> //std::setprecision


using std::cout;	using std::endl;
using std::abs;		using std::setprecision;
using std::sqrt;	using std::log;


//ntervalo[a,b]
//long double a = 0.005;
//long double b = 0.01;
//long double re = pow(10, 4);

//2long double a = 0;
//2long double b = 1;

long double a = 1;
long double b = 2;

//1y2 long double T = pow(10, -6);
long double T = pow(10, -3);



//funcion
inline double f(long double x) {



//	1return (1.74 * log(re * sqrt(x))) - 0.4 - sqrt(1 / x);
   //2 return( (pow(x,2)+x-1));
    return ( (pow(x,3)+4*(pow(x,2))-10));

}



/*
	f: funci�n para la cual buscamos la ra�z
	a: extremo izquierdo del intervalo
	b: extremo derecho del intervalo
	T: tolerancia
*/

void biseccion_01(long double a, long double b, long double T) {


	long double p;
	long double n = ceil(log2(abs((b - a) / T)));
	cout << "NUMERO DE ITERACIONES PARA QUE SE CUMPLA " << n << endl;


	for (int i = 0; i < n; i++) {


		p = (a + b) / 2;
		cout << " iteracion " << i << + " a " << setprecision(20) <<  a << " c " << p << " b  " << b << " f(c)  " << f(p) << endl;


		if (f(a) * f(p) < 0) {
			b = p;
		}
		else {
			a = p;
		}



	}
}

int main() {

    
    if ( f(a)*f(b) <= 0 ) 
        
    {
	cout << (f(a)) << endl; // Extremo izquierdo del intervalo
	cout << (f(b)) << endl; // Extremo derecho del intervalo
	biseccion_01(a, b, T);
    }
    else {
        cout<<"NO SE PUEDE USAR EL METODO" <<endl;
    }

}
