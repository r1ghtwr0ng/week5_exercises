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
    std::unique_ptr<TrapeziumIntegrator> integrator = std::make_unique<TrapeziumIntegrator>();
    DiscreteFunction DF(ys, 0, 1, integrator);
    std::unique_ptr<TrapeziumIntegrator> integrator2 = std::make_unique<TrapeziumIntegrator>();
    DF.setIntegrator(integrator2);

    std::cout << DF.integrate() << std::endl;

    return 0;
}