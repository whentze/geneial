/*
 * MultiValueChromosomeFactory.h
 *
 *  Created on: Dec 9, 2014
 *      Author: bewo
 */

#ifndef MULTI_INT_VALUE_CHROMOSOME_FACTORY_H_
#define MULTI_INT_VALUE_CHROMOSOME_FACTORY_H_

#include <core/population/builder/MultiValueChromosomeFactory.h>

namespace GeneticLibrary {
namespace Population {
namespace Chromosome {

template <typename FITNESS_TYPE>
class MultiIntValueChromosomeFactory : public MultiValueChromosomeFactory<int,FITNESS_TYPE>
{

public:
	MultiIntValueChromosomeFactory(MultiValueBuilderSettings<int> settings): MultiValueChromosomeFactory<int,FITNESS_TYPE>(settings){};
	typename BaseChromosome<FITNESS_TYPE>::ptr createChromosome();

};

} /* namespace Chromosome */
} /* namespace Population */
} /* namespace GeneticLibrary */

#include <core/population/builder/MultiIntValueChromosomeFactory.hpp>

#endif /* MULTI_INT_VALUE_CHROMOSOME_FACTORY_H_ */
