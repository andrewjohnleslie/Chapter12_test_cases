#include <iostream>
#include <cmath>

int main() {

    double T02 = 288.15;
    double P02 = 101300;
    double Ta = T02;
    double Pa = P02;
    double cp = 1005;
    double cpe = 1244;

    double gama = 1.4;
    double gamma_e = 1.3;
    double e_t = 0.85;                  // Polytropic efficiency
    double e_c = 0.9;
    double KH = 0.157;
    double SigT = (2 * e_t * (gamma_e - 1)) / ((2 * gamma_e) - (e_t * (gamma_e - 1)));        // pg 180

    double T04_OD {750};
    double r_area = pow((1 - KH), (1/SigT));
    double rn_choke = 1.832;

    double mbar4 = 1.389;
    double mbar9 {1.389};

    int x = 0;
    double rmbar {1};
    //double diff_rmbr {0};
    //double saved_rmbar {0};
    double prev_mbar9 {0};

    do {

        double rmbar = mbar4/mbar9;
        //double saved_rmbar = rmbar;
        double prev_mbar9 = mbar9;                  // Tests to prove that the previous mbar9 value is saved during the iteration.
        //double diff_rmbr = rmbar - saved_rmbar;

        if (rmbar == 1){
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

    // Previous do-while test conditions:     diff_rmbr >= saved_rmbar * 0.001             rmbar != saved_rmbar
    //                                            std::abs(prev_mbar9 / mbar9 - 1) > 1e-6
    return 0;
}
