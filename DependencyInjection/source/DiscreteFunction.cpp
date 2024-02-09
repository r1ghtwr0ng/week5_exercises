#include "DiscreteFunction.h"
#include <stdexcept>

DiscreteFunction::DiscreteFunction(std::vector<double> y, double x_min, double x_max, std::unique_ptr<TrapeziumIntegrator> &integrator_ref) : max_x(x_max), min_x(x_min)
{
    if(y.size() < 3)
    {
        throw std::runtime_error("Discrete function must be represented at at least 3 points.");
    }
    if(y.size() % 2 != 1)
    {
        throw std::runtime_error("Discrete function must be represented at an odd number of points.");
    }
    // If y is a valid function representation then move data ownership to this object
    // y (passing in vector) will be left empty
    ys = std::move(y);

    delta_x = (x_max - x_min) / (ys.size()-1);

    integrator = std::move(integrator_ref);
}

double DiscreteFunction::integrate()
{
    return integrator->integrate(delta_x, ys);
}

void DiscreteFunction::setIntegrator(std::unique_ptr<TrapeziumIntegrator> &integrator_ref)
{
    integrator = std::move(integrator_ref);
}

SimpsonIntegrator::SimpsonIntegrator() {};

TrapeziumIntegrator::TrapeziumIntegrator() {};

double SimpsonIntegrator::integrate(const double delta_x, const std::vector<double> &ys)
{
    double total = ys[0];
    for(size_t i = 1; i < ys.size()-1; i++)
    {
        total += (i%2==1 ? 4 : 2) * ys[i];
    }
    total += ys[ys.size()-1];
    total *= delta_x / 3;
    return total;
}

double TrapeziumIntegrator::integrate(const double delta_x, const std::vector<double> &ys)
{
    double total = ys[0];
    for(size_t i = 1; i < ys.size()-1; i++)
    {
        total += ys[i] * 2;
    }
    total += ys[ys.size()-1];
    total *= delta_x / 2;

    return total;
}