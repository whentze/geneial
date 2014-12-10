/*
 * BaseGeneticAlgorithm.hpp
 *
 *  Created on: Nov 26, 2014
 *      Author: bewo
 */

#ifndef BASEGENETICALGORITHM_HPP_
#define BASEGENETICALGORITHM_HPP_

#include <algorithm/BaseGeneticAlgorithm.h>

namespace GeneticLibrary {
namespace Algorithm {

template <typename FITNESS_TYPE>
void BaseGeneticAlgorithm<FITNESS_TYPE>::solve(){

	//TODO (bewo) use a Logger for output

	//TODO (bewo) scout for Memleaks using valgrind

	std::cout << "Initial Replenishing" << std::endl;

	//Initialize the first population candidate
	_manager.replenishPopulation();


	std::cout << _manager.getPopulation().getAge() << std::endl;

	std::cout << "Entering Main Loop" << std::endl;

	//Do a barrel roll...
	while(!_stoppingCriterion->wasReached(_manager)){

		//std::cout << _manager.getPopulation() << std::endl;
		_manager.getPopulation().print(std::cout);

		//TODO (bewo) implement genetic algorithm workflow here
		//TODO (bewo) selection
		//TODO (bewo) mutation
		//TODO (bewo) scaling
		//TODO (bewo) fitness evaluation

		_manager.getPopulation().doAge();

		_manager.getPopulation().getChromosomes().clear();

		_manager.replenishPopulation();

	}

	std::cout << "Main Loop Done" << std::endl;

}


} /* namespace Algorithm */
} /* namespace GeneticLibrary */

#endif /* BASEGENETICALGORITHM_HPP_ */
