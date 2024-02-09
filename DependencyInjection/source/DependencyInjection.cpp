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
    // Use Trapezium integrator
    std::unique_ptr<Integrator> t_integr = std::make_unique<TrapeziumIntegrator>();
    DiscreteFunction DF(ys, 0, 1, t_integr);
    std::cout << DF.integrate() << std::endl;

    // Use Simpson integrator
    std::unique_ptr<Integrator> s_integr = std::make_unique<SimpsonIntegrator>();
    DF.setIntegrator(s_integr);
    std::cout << DF.integrate() << std::endl;

    return 0;
}