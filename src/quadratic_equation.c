#include "quadratic_equation.h"
#include <math.h>

Roots solve_equation(double a, double b, double c)
{
    Roots roots;
    double discriminant = b*b - 4*a*c;
    double epsilon = 1e-10;

    if (discriminant < 0) {
        roots.num_roots = 0;
        roots.root1 = 0;
        roots.root2 = 0;
    } else if (fabs(discriminant) < epsilon) {
        roots.num_roots = 1;
        roots.root1 = -b / (2*a);
        roots.root2 = roots.root1;
    } else {
        roots.num_roots = 2;
        roots.root1 = (-b + sqrt(discriminant)) / (2*a);
        roots.root2 = (-b - sqrt(discriminant)) / (2*a);
    }

    return roots;
}