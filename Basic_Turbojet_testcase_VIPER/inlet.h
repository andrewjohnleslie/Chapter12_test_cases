//
// Created by Andrew on 19/02/2023.
//

#include  <cmath>

#ifndef TEST_CASES_INLET_H
#define TEST_CASES_INLET_H

// Properties of air
auto gama = 1.4;
auto gamma_e = 1.3;
double cp = 1005;
double cpe = 1244;
double R = 287;

// Ambient conditions
double T_a = 288.15;
double P_a = 101300;

double M_f = 0;

double T_02 = T_a * (1 + ((gama - 1) / 2) * pow(M_f, 2));
double P_02 = P_a * pow((1 + ((gama - 1) / 2) * pow(M_f, 2)),gama/(gama - 1));


#endif //TEST_CASES_INLET_H
