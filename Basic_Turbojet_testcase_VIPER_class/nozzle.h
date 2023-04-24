//
// Created by Andrew on 19/04/2023.
//

#ifndef BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H
#define BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H

#include <cmath>
#include "turbine.h"

class Nozzle : public Turbine{

public:
    double T_9 = T_05 * pow((P_a/P_05), ((gamma_e-1)/gamma_e));
    double P_9 = P_a;     //Assume the nozzle fully expands the flow so that the core jet stream exits at ambient pressure
    double T_09 = T_05;
    // P_09 = P_05;     pg 182

// DESIGN POINT table
    double F_g = 15167;
    double V_9_dp = F_g/mdot_a;                                         // V_9_dp = V_j

// Calculated thermodynamic cycle
    double V_9_calc = pow((2 * cpe * (T_09 - T_9)), 0.5);        // V_9_calc = V_j

// Discrepancy of V_j values is likely due to neglecting the combustor pressure loss, and the simplifying assumptions
    // made for the gas properties (i.e. constant gamma).

// double A_nozz_p =  ((mdot_tot * pow((cpe * T_05), 0.5)) / (P_05 * m_norm_ge));

    double y = P_05/P_a;

    Nozzle() = default;
    ~Nozzle() = default;
};
#endif //BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H
