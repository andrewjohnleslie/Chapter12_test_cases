// This test case is the preliminary test case for a simple turbojet (single-spool) engine.
// The engine being considered and modelled is the Rolls-Royce Viper [Mark 601] turbojet engine.

// The data provided for this engine is at a DESIGN POINT for a sea-level test bed.
    // F_G = 15167 (N)
    // sfc = 0.993 (kg/h/kg)
    // m_a = 23.81 (kg/s)
    // m_f = 0.4267 (kg/s)
    // OPR [P_03/P_02] = 5.5

#include <iostream>
// #include "inlet.cpp"
#include "inlet.h"
//#include "compressor.cpp"
#include "compressor.h"
// #include "turbine.cpp"
#include "turbine.h"
// #include "nozzle.cpp"
#include "nozzle.h"


int main() {

std::cout << "T_02 = " << T_02 << std::endl;
std::cout << "P_02 = " << P_02 << std::endl;
std::cout << "T_03 = " << T_03 << std::endl;
std::cout << "P_03 = " << P_03 << std::endl;
std::cout << "T_04 = " << T_04 << std::endl;
std::cout << "P_04 = " << P_04 << std::endl;
std::cout << "T_05 = " << T_05 << std::endl;
std::cout << "P_05 = " << P_05 << std::endl;
std::cout << "T_09 = " << T_09 << std::endl;
std::cout << "T_9 = " << T_9 << std::endl;
std::cout << "P_9 = " << P_9 << std::endl;
std::cout << "V_9 = " << V_9_calc << std::endl;          // Calculated jet velocity
std::cout << "mbar_choke_ge = " << m_norm_ge << std::endl;
std::cout << "Turbine nozzle area  (m^2) = " << A_nozz_t << std::endl;
std::cout << "Propulsive nozzle area  (m^2) = " << A_nozz_p << std::endl;
std::cout << "Critical pressure ratio - TURBINE = " << Pcrit << std::endl;
std::cout << "Turbine pressure  ratio = " << x << std::endl;
std::cout << "Nozzle pressure ratio = " << y << std::endl;

}
