// Copyright 2022 Lakhov Kirill

#ifndef MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_H_
#define MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_H_
#include <vector>
#include <cmath>

class StohasticVariable {
 protected:
    const std::vector<double>& values_;
    const std::vector<double>& probabilities_;
 public:
    StohasticVariable(const std::vector<double>& values,
                      const std::vector<double>& probabilities);

    const std::vector<double>& values();
    const std::vector<double>& probabilities();

    double RawMoment(int k);
    double Mean();

    double CentralMoment(int k);
    double Dispersion();
};


#endif  // MODULES_LAKHOV_STATISTICS_INCLUDE_STOHASTIC_VARIABLE_H_
