#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision
using namespace std;
using std::cout;
using std::endl;
using std::abs;
using std::setprecision;

/*
 uno
 * long double a = 0.005;
long double b = 0.1;
long double p0 = 0.075;
long double T = pow(10, -9);
 */

long double a = 1.5;
long double b = 2;
long double p0 = abs((a + b) / 2);
long double T = pow(10, -6);
long double maxFuncion = 2; //valor que de la calcu
// fmax(∣g′(x)∣,x,a,b) 


// FunciÃ³n para IPF

inline double g(double x) {

    //return (2.0 - exp(x) + pow(x, 2))/3.0; 
    //return (0.330295 / pow((log(re * sqrt(x)) - 0.229885), 2));
    return ((pow(x, 3) + 1) / 3);
}

inline double dg(double x) {

    //return (-0.330295 / ((pow((log(re * sqrt(x)) - 0.229885), 3))*(x)));
    return ( pow(x, 2));
}



long double k = abs(dg(maxFuncion)); //   valor absoluto de la primera derivada
//en el max que se encontro
long double maxDivision = fmax(p0 - a, b - p0);
long double x = T / maxDivision;
//long double Nmax = (log(x)/log(k));
long double Nmax = ceil(log(x) / log(k));

/*
IteraciÃ³n de punto fijo
p0: aproximaciÃ³n inicial
Nmax: nÃºmero mÃ¡ximo de iteraciones
T: tolerancia
 */

void fixedPoint(double p0, int Nmax, double T) {

    double p;

    for (int i = 0; i < Nmax; i++) {
        p = g(p0);
        cout << i << setprecision(10) << "\t" << p0 << "\t" << p << "\t" << abs(p - p0) << endl;

        if (abs(p - p0) < T) {
            cout << "Objetivo logrado con " << i + 1 << " iteraciones" << endl;
            break;
        }

        p0 = p;
    }

}

int main() {


    if (g(a) <= b and g(a) >= a and g(b) <= b and g(b) >= a and k < 1 and k > 0
            ) {
        fixedPoint(p0, Nmax, T);
        cout << endl << endl;
        cout << " G(a) " << g(a) << " G(b) " << g(b) << " DG(max) " << k << " NUM MAX " << Nmax << endl;

    } else {

        cout << " G(a) " << g(a) << " G(b) " << g(b) << " DG(max) " << k << " NUM MAX " << Nmax << " NUM MAX DE LOG " << maxDivision << endl;
        cout << "No cumple con las condiciones de punto fijo :(" << endl;
    
    }

    return 0;
}
