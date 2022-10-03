//
// Created by smile on 2022/10/3.
//

#include <vector>
#include <random>
#include <cmath>

class Solution {
public:
    double xCenter, yCenter, radius;

    explicit Solution(double radius, double x_center, double y_center) :
            xCenter(x_center), yCenter(y_center), radius(radius) {
        std::random_device rd;
        eng = std::default_random_engine(rd());
        thetaRand = std::uniform_real_distribution<double>(0, M_PI * 2);
        distRand = std::uniform_real_distribution<double>(0, 1);

    };

    std::vector<double> randPoint() {
        // x = ρ * cos(θ)
        // y = ρ * sin(θ)
        auto rho = sqrt(distRand(eng)) * radius;
        auto theta = thetaRand(eng);
        auto x = rho * std::cos(theta);
        auto y = rho * std::sin(theta);
        return {xCenter + x, yCenter + y};
    }

private:
    std::default_random_engine eng;
    std::uniform_real_distribution<double> thetaRand;
    std::uniform_real_distribution<double> distRand;
};