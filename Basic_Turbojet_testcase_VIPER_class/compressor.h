//
// Created by Andrew on 19/04/2023.
//

#ifndef BASIC_TURBOJET_TESTCASE_VIPER_CLASS_COMPRESSOR_H
#define BASIC_TURBOJET_TESTCASE_VIPER_CLASS_COMPRESSOR_H

#include <cmath>
#include "inlet.h"

class Compressor : public Inlet {

public:
    Compressor() = default;
    ~Compressor() = default;

    double pi_c = 5.5;              // OPR = P_03/P_02
    double e_c = 0.9;

    double T_03 = T_02 * pow(pi_c, (gama - 1)/(e_c * gama));
    double P_03 = pi_c * P_02;
    double tau_c = T_03 / T_02;

protected:
    double DelT_c = T_03 - T_02;
    double DelT_t = (cp/cpe) * DelT_c;

};
#endif //BASIC_TURBOJET_TESTCASE_VIPER_CLASS_COMPRESSOR_H
