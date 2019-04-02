#ifndef CALCULATOR_H
#define CALCULATOR_H
class Calculator {
    public:
    static double CM_TO_M(double CM) { return 0.01 * CM; }
    static double M_TO_CM(double M) { return 100 * M; }
    static double M_TO_KM(double M) { return 0.001* M; }
    static double KM_TO_M(double KM) { return 1000 * KM; }
    static double KM_TO_CM(double KM) { return M_TO_CM(KM_TO_M(KM)); }
    static double CM_TO_KM(double CM) { return M_TO_KM(CM_TO_M(CM)); }
};
#endif