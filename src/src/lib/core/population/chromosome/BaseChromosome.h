/*
 * BasicChromome.h
 *
 *  Created on: Nov 26, 2014
 *      Author: bewo
 */

#ifndef BASE_CHROMOSOME_H_
#define BASE_CHROMOSOME_H_

//TODO (bewo) chromosome_age is unsigned int but -1?
#define CHROMOSOME_AGE_UNITIALIZED (-1)


#include <iostream>
#include <utility/random.h>
#include <utility/printable.h>
#include <core/fitness/Fitness.h>
#include "Config.h"

namespace GeneticLibrary {
namespace Population {
namespace Chromosome {

/**
 * @brief Abstract superclass for any type of chromosome
 */
template <typename FITNESS_TYPE>
class BaseChromosome : public Utility::printable {

public:
	typedef unsigned int chromosome_age;
	/**
	 * Creates a new Chromosome with random values and a fitness of -1
	 */
	BaseChromosome();
	virtual ~BaseChromosome();


	/**
	 * Gets the fitness value of a Chromosome.
	 * Does not calculate the fitness.
	 */
	Fitness<FITNESS_TYPE> getFitness() const;
	/**
	 * Sets Fitness of a chromosome
	 */
	void setFitness(const Fitness<FITNESS_TYPE> fitness);

	/**
	 * Used to 'age' a chromosome. Increments the age of a chromosome by one
	 * Returns the new age of the chromosome
	 */
	chromosome_age doAge();
	/**
	 * Returns the age of a chromosome
	 */
	chromosome_age getAge() const;

	void setAge(const chromosome_age age);

	virtual void print(std::ostream& os) const = 0;

private:
	Fitness<FITNESS_TYPE> _fitness;
	chromosome_age _age;
};

} /* namespace Chromosome */
} /* namespace Population */
} /* namespace GeneticLibrary */

#include <core/population/chromosome/BaseChromosome.hpp>

#endif /* BASE_CHROMOSOME_H_ */
