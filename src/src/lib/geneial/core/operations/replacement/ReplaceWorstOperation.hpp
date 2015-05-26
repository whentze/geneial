#pragma once

#include <geneial/core/operations/replacement/ReplaceWorstOperation.h>

#include <algorithm>
#include <iterator>
#include <functional>
#include <tuple>
#include <utility>

geneial_private_namespace(geneial)
{
geneial_private_namespace(operation)
{
geneial_private_namespace(replacement)
{
using ::geneial::population::Population;
using ::geneial::operation::coupling::BaseCouplingOperation;
using ::geneial::operation::selection::BaseSelectionOperation;

geneial_export_namespace
{

template<typename FITNESS_TYPE>
unsigned int ReplaceWorstOperation<FITNESS_TYPE>::getAmountToReplace(const Population<FITNESS_TYPE> &population,
        const typename BaseCouplingOperation<FITNESS_TYPE>::offspring_result_set &offspring) const
{
    switch (this->getSettings().getMode())
    {

    case BaseReplacementSettings::REPLACE_ALL_OFFSPRING:
    {
        return std::min(population.getFitnessMap().size() - this->getSettings().getAmountElitism() - 1,
                offspring.size());
    }
        break;

    case BaseReplacementSettings::REPLACE_FIXED_NUMBER: /*FALLTHROUGH*/
    default:
    {
        return std::min(population.getFitnessMap().size() - 1,
                (typename Population<FITNESS_TYPE>::fitness_map::size_type) this->getSettings().getAmountToReplace());
    }
        break;
    }
}

template<typename FITNESS_TYPE>
void ReplaceWorstOperation<FITNESS_TYPE>::doReplace(Population<FITNESS_TYPE> &population,
        const typename BaseSelectionOperation<FITNESS_TYPE>::selection_result_set &parents,
        typename BaseCouplingOperation<FITNESS_TYPE>::offspring_result_set &offspring,
        BaseManager<FITNESS_TYPE> &manager) const
{
    unsigned int numberToReplace = getAmountToReplace(population, offspring); //this also takes care of elitism!

    //Insert all the offspring, parents are ignored here (since they are assumed to be already in the population)

    //We'd rather insert the chromsomes all at one, so we can use multithreading for determining the fitness.
    //However, first we need to check whehter we will have duplicates

    typename Population<FITNESS_TYPE>::chromosome_container newChildren;
    newChildren.reserve(offspring.size());

    unsigned int childrenCandidates = 0;
    for(const auto& newOffspring: offspring)
    {
        if(!population.hashExists(newOffspring->getHash()))
        {
            newChildren.push_back(newOffspring);
            childrenCandidates++;
        }
        if(childrenCandidates >= numberToReplace)
        {
            break;
        }
    }

    population.insertChromosomeContainer(newChildren);


    //we might have a deficit at this point if offsprings were already contained.

    //remove the worst chromosomes to replace (assuming worst is at the very beginning)
    typename Population<FITNESS_TYPE>::fitnessmap_const_it advanced = population.getFitnessMap().cbegin();

    const unsigned int worstChromosomesToRemove = population.getSize() - manager.getPopulationSettings().getMaxChromosomes();
    if(worstChromosomesToRemove != 0)
    {
        std::advance(advanced, worstChromosomesToRemove);

        typename Population<FITNESS_TYPE>::chromosome_container toRemove;
        toRemove.reserve(numberToReplace);

        //insert the second component of the fitness map (the chromosome ptr) into toRemove
        std::transform(
                population.getFitnessMap().cbegin(),
                advanced, std::back_inserter(toRemove),
                [](decltype(*advanced)& p){ return p.second; }
        );
        population.removeChromosomeContainer(toRemove);
    }
    else
    {
        //TODO(bewo) else log this case, if this occurs frequently this is
        //an indicator of some saturation or misconfiguration in the GA
         //static int noop = 0;
        //std::cout << "Noop Replacement" << noop++ << std::endl;
    }

}

} /* geneial_export_namespace */
} /* private namespace replacement */
} /* private namespace operation */
} /* private namespace geneial */

