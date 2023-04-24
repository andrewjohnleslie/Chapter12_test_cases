//
// Created by Andrew on 02/04/2023.
//

#include "CustomFunction.h"
#include <iostream>
#include <cmath>

void myCustomFunction(double T02, double P02, double Pa, double cp, double cpe, double gama, double gamma_e, double e_t,
                      double e_c, double KH, double SigT, double T04_OD, double r_area, double mbar4, double mbar9,
                      int x, double prev_mbar9) {
    T02 = 288.15;
    P02 = 101300;
    Pa = P02;
    cp = 1005;
    cpe = 1244;

    gama = 1.4;
    gamma_e = 1.3;
    e_t = 0.85;                  // Polytropic efficiency
    e_c = 0.9;
    KH = 0.157;
    SigT = (2 * e_t * (gamma_e - 1)) / ((2 * gamma_e) - (e_t * (gamma_e - 1)));        // pg 180

    T04_OD = 750;
    r_area = pow((1 - KH), (1/SigT));
    //double rn_choke = 1.832;

    mbar4 = 1.389;
    mbar9 = 1.389;

    x = 0;
    //rmbar = 1;
    prev_mbar9 = 0;

    do {

        //rmbar = 1;                                 // Both of these variable initialisations appear to work
        //prev_mbar9 = 0;

        double rmbar = mbar4/mbar9;
        //double saved_rmbar = rmbar;
        double prev_mbar9 = mbar9;                  // Tests to prove that the previous mbar9 value is saved during the iteration.
        //double diff_rmbr = rmbar - saved_rmbar;

        if (x == 0){
            double KH_OD = 1 - pow((r_area * rmbar), SigT);
            double T05_OD = T04_OD * (1 - KH_OD);
            double T03_OD = T02 + ((cpe/cp)*KH_OD*T04_OD);
            double OPR_OD = pow((T03_OD/T02),((e_c * gama)/(gama - 1)));
            double P03_OD = OPR_OD * P02;
            double P04_OD = P03_OD;
            double P05_OD = P04_OD * pow((T05_OD/T04_OD),(gamma_e/(e_t * (gamma_e - 1))));

            double  NPR = P05_OD / Pa;

            double* mb9 = &mbar9;
            *mb9 = ((gamma_e)/(gamma_e - 1)) * pow(2*(pow(NPR,(-2/gamma_e)) - pow(NPR,(-1*(gamma_e+1))/gamma_e)), 0.5);
        }else{
            double KH_OD = 1 - pow((r_area * rmbar), SigT);
            double T05_OD = T04_OD * (1 - KH_OD);
            double T03_OD = T02 + ((cpe/cp)*KH_OD*T04_OD);
            double OPR_OD = pow((T03_OD/T02),((e_c * gama)/(gama - 1)));
            double P03_OD = OPR_OD * P02;
            double P04_OD = P03_OD;
            double P05_OD = P04_OD * pow((T05_OD/T04_OD),(gamma_e/(e_t * (gamma_e - 1))));

            double  NPR = P05_OD / Pa;

            double* mb9 = &mbar9;
            *mb9 = ((gamma_e)/(gamma_e - 1)) * pow(2*(pow(NPR,(-2/gamma_e)) - pow(NPR,(-1*(gamma_e+1))/gamma_e)), 0.5);

        }

        std::cout.precision(35);
        std::cout << " Iteration = " << x << std::endl;

        //std::cout << " saved_rmbar = " << saved_rmbar << std::endl;
        //std::cout << " diff_rmbr = " << diff_rmbr << std::endl;
        std::cout << " mbar9 = " << mbar9 << std::endl;
        std::cout << " prev_mbar9 = " << prev_mbar9 << std::endl;
        std::cout << " prev_mbar9/mbar9 = " << prev_mbar9/mbar9 << std::endl;
        std::cout << " rmbar = " << rmbar << std::endl;

        if (x != 0){
            if ((prev_mbar9 - mbar9) == 0){                            // Test using a much larger precision
                std::cout << "Bingo! " << std::endl;
                break;
            }
        }

        x++;

    } while (std::abs(prev_mbar9 / mbar9 - 1) >= 1e-6);

}
