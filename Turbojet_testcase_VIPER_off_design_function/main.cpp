#include <iostream>
#include <cmath>
#include "CustomFunction.h"
//#include "CustomFunction.cpp"

int main() {

    double T02 = 288.15;
    double P02 = 101300;
    double Pa = P02;
    double cp = 1005;
    double cpe = 1244;

    double gama = 1.4;
    double gamma_e = 1.3;
    double e_t = 0.85;                  // Polytropic efficiency
    double e_c = 0.9;
    double KH = 0.157;
    double SigT = (2 * e_t * (gamma_e - 1)) / ((2 * gamma_e) - (e_t * (gamma_e - 1)));        // pg 180

    double T04_OD = 750;
    double r_area = pow((1 - KH), (1/SigT));
    //double rn_choke = 1.832;

    double mbar4 = 1.389;
    double mbar9 = 1.389;

    int x = 0;
    //double rmbar = 1;
    double prev_mbar9 = 0;

    myCustomFunction(T02, P02, Pa, cp, cpe, gama, gamma_e, e_t, e_c,
                     KH, SigT, T04_OD, r_area, mbar4, mbar9, x,
                     prev_mbar9);

    return 0;
}
