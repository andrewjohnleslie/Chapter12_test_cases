//
// Created by Andrew on 20/02/2023.
//
#include <cmath>
#include "inlet.h"

#ifndef TEST_CASES_COMPRESSOR_H
#define TEST_CASES_COMPRESSOR_H

double pi_c = 5.5;              // OPR = P_03/P_02
double e_c = 0.9;

double T_03 = T_02 * pow(pi_c, (gama - 1)/(e_c * gama));
double P_03 = pi_c * P_02;
// double tau_c = T_03 / T_02;

double DelT_c = T_03 - T_02;
double DelT_t = (cp/cpe) * DelT_c;


#endif //TEST_CASES_COMPRESSOR_H
