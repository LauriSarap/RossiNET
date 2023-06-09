#include "rpch.h"
#include "MathFunctions.h"
#include <cmath>

namespace NNetwork
{
	double MathFunctions::Sigmoid(double x)
	{
		return 1.0 / (1.0 + exp(-x));
	}

	double MathFunctions::SigmoidDerivative(double x)
	{
		return x * (1.0 - x);
	}
}

