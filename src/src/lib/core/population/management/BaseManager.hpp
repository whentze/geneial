/**
 *  Manager.cpp
 *  Created on: Dec 8, 2014
 *  Manages the population and most of the processes which modify the chromosomes
 *
 */
#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <core/population/management/BaseManager.h>
namespace GeneticLibrary {
namespace Population {
namespace Manager {

template <typename FITNESS_TYPE>
Population<FITNESS_TYPE> BaseManager<FITNESS_TYPE>::replenishPopulation (Population<FITNESS_TYPE> population){

	/* TODO (bewo)
	 *
	//if there are less chromosomes than required fill up:
	while (_population.size() < defPopulationSize){

		//build new chromosome
		Chromosome::BaseChromosome<FITNESS_TYPE> newChromosome = GeneticLibrary::Population::Chromosome::BasicChromosome::BasicChromosome();

		//add at the end of vector
		population.getChromosomes().push_back(newChromosome);
	}
	return population;

	*/

	return _population;
}

template <typename FITNESS_TYPE>
Chromosome::BaseChromosome<FITNESS_TYPE> BaseManager<FITNESS_TYPE>::selectBestChromosome(Population<FITNESS_TYPE> population){
	/* TODO (bewo)
	 * {

	Chromosome::BaseChromosome<FITNESS_TYPE> bestChromosome = population.getChromosomes().at(0);
	for (int i = 0; i <= population.size(); i++){
		if (population.getChromosomes().at(i) > bestChromosome.getFitness()){
			bestChromosome = population.getChromosomes().at(i);
		}
	}
	return bestChromosome;

	*/

	return Chromosome::BaseChromosome<FITNESS_TYPE>();
}

} /* namespace Manager */
} /* namespace Population */
} /* namespace GeneticLibrary */

#endif /* MANAGER_HPP_ */
