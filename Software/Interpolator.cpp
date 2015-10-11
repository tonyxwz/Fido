#include "Interpolator.h"

#include <iostream>

#include "LSInterpolator.h"

using namespace net;

Interpolator * Interpolator::getAnyInterpolatorFromFile(std::ifstream *in) {
	long placeInFile = in->tellg();
	Interpolator *interpolator;

	interpolator = static_cast<Interpolator *>(new LSInterpolator());
	if(interpolator->initFromFile(in)) {
		return interpolator;
	}
	delete interpolator;
	in->seekg(placeInFile);

	std::cout << "Could not get any interpolator from file\n";
	throw 1;
};