/*
 * BasicChromome.h
 *
 *  Created on: Nov 26, 2014
 *      Author: bewo
 */

#ifndef BASICCHROMOME_H_
#define BASICCHROMOME_H_


#include "Config.h"
#include <vector>

namespace GeneticLibrary {
namespace Population {
namespace Chromosome {

class BasicChromosome {
private:
	int fitness;
	double values[defChromosomeSize];
	unsigned int age;

public:
	BasicChromosome();
	virtual ~BasicChromosome();

	int getFitness();
	void setFitness(int fit);
	double getValue(int i);
	void setValue(int postion, double value);
	void doAge();
	unsigned int getAge();
	void setAge(unsigned int age);
};

} /* namespace Chromosome */
} /* namespace Population */
} /* namespace GeneticLibrary */

#endif /* BASICCHROMOME_H_ */
