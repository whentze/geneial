#pragma once

#include <geneial/utility/Printable.h>
#include <geneial/core/fitness/Fitness.h>
#include <geneial/core/fitness/FitnessEvaluator.h>

#include <iostream>
#include <memory>
#include <cassert>

namespace geneial
{
namespace population
{
namespace chromosome
{

using namespace geneial::utility;

/**
 * @brief Abstract superclass for any type of chromosome
 */
template<typename FITNESS_TYPE>
class BaseChromosome: public Printable, public std::enable_shared_from_this<BaseChromosome<FITNESS_TYPE> >
{

public:
    static const int CHROMOSOME_AGE_UNITIALIZED = 0;

    typedef unsigned int chromosome_age;
    typedef std::size_t chromsome_hash;

    typedef typename std::shared_ptr<BaseChromosome<FITNESS_TYPE> > ptr;
    typedef typename std::shared_ptr<const BaseChromosome<FITNESS_TYPE> > const_ptr;

    ptr getPtr() //TODO (bewo) constness correct?
    {
        return this->shared_from_this();
    }

    const_ptr getConstPtr() //TODO (bewo) constness correct?
    {
        return this->shared_from_this();
    }

    /**
     *
     */
    BaseChromosome(typename FitnessEvaluator<FITNESS_TYPE>::ptr fitnessEvaluator) :
            _fitness(), _fitnessEvaluator(fitnessEvaluator), _age(CHROMOSOME_AGE_UNITIALIZED)
    {
        assert(_fitnessEvaluator);
    }

    virtual ~BaseChromosome()
    {
    }

    virtual bool equals(const_ptr chromosome) const = 0;

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

    bool inline hasFitness() const
    {
        return !(_fitness == NULL);
    }

    /**
     * Gets the fitness value of a Chromosome.
     * Calls the fitness evaluator, if chromosome has no fitness yet.
     */
    const typename Fitness<FITNESS_TYPE>::ptr getFitness();

    /**
     * Gets the fitness value of a Chromosome.
     * Does not evaluate the fitness.
     */
    const typename Fitness<FITNESS_TYPE>::ptr getFitness() const;

    /**
     * If the chromosome was modified from outside and it's "cached" fitness can no no longer be
     * guaranteed to be accurate, this should be invoked to trigger a new Fitness Evaluation
     *
     * Caution: this function only has an effect on the concrete chromosome object, but does not
     * alter any external datastructures outside of the object's context
     * (e.g., the fitness map of a population)
     */
    void invalidateFitness();

    /**
     * Sets fitness of a chromosome
     */
    void setFitness(const typename Fitness<FITNESS_TYPE>::ptr& fitness);

    bool inline hasFitnessEvaluator() const
    {
        return !(_fitnessEvaluator == NULL);
    }

    const typename FitnessEvaluator<FITNESS_TYPE>::ptr getFitnessEvaluator() const;

    void setFitnessEvaluator(const typename FitnessEvaluator<FITNESS_TYPE>::ptr& fitnessEvaluator);

    virtual chromsome_hash getHash() const = 0;

protected:
    virtual bool hashEquals(const_ptr chromosome) const;
    virtual void printHash(std::ostream& os) const;

private:
    typename Fitness<FITNESS_TYPE>::ptr _fitness;

    typename FitnessEvaluator<FITNESS_TYPE>::ptr _fitnessEvaluator;

    chromosome_age _age;
};

} /* namespace chromomsome */
} /* namespace population */
} /* namespace geneial */

#include <geneial/core/population/chromosome/BaseChromosome.hpp>

