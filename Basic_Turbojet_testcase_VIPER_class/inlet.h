//
// Created by Andrew on 19/04/2023.
//

#ifndef BASIC_TURBOJET_TESTCASE_VIPER_CLASS_INLET_H
#define BASIC_TURBOJET_TESTCASE_VIPER_CLASS_INLET_H

#include  <cmath>

class Inlet {

// Protected inheritance: You CANNOT access variables that are protected in the base class anywhere other than the
//                          derived class.
protected:
    //Member variables
    double gama = 1.4;
    double gamma_e = 1.3;
    double cp = 1005;
    double cpe = 1244;
    double R = 287;

// Ambient conditions
    double T_a = 288.15;
    double P_a = 101300;

    double M_f = 0;

// Public inheritance: Public member variables in the base class become protected in the derived class; therefore, not
//                      accessible.
public:
    //Member variables
    double T_02 = T_a * (1 + ((gama - 1) / 2) * pow(M_f, 2));
    double P_02 = P_a * pow((1 + ((gama - 1) / 2) * pow(M_f, 2)),gama/(gama - 1));

    Inlet() = default;          //Constructor
    ~Inlet() = default;         //Destructor

};
#endif //BASIC_TURBOJET_TESTCASE_VIPER_CLASS_INLET_H
