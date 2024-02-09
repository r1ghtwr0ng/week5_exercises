#include <iostream>
#include "DiscreteFunction.h"
#include <vector>

int main()
{
    std::vector<double> ys(21);
    double delta_x = 1.0 / 20;
    for(size_t i = 0; i < ys.size(); i++)
    {
        double x = delta_x * i;
        ys[i] = x*x;
    }
    // Create instance
    DiscreteFunction DF(ys, 0, 1);

    // Compare integrators
    std::unique_ptr<Integrator> t_integr = std::make_unique<TrapeziumIntegrator>();
    std::unique_ptr<Integrator> s_integr = std::make_unique<SimpsonIntegrator>();
    DF.setIntegrator(t_integr);
    double t_result = DF.integrate();
    DF.setIntegrator(s_integr);
    double s_result = DF.integrate();

    std::cout << "[i] Trapezium result: " << t_result << "\n[i] Simpson result: " << s_result << std::endl;

    return 0;
}