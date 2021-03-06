#pragma once

#include <geneial/namespaces.h>
#include <geneial/core/operations/crossover/MultiValueChromosomeCrossoverOperation.h>
#include <geneial/utility/mixins/EnableMakeShared.h>

#include <cassert>

geneial_private_namespace(geneial)
{
geneial_private_namespace(operation)
{
geneial_private_namespace(crossover)
{
using ::geneial::population::Population;
using ::geneial::population::chromosome::MultiValueChromosome;
using ::geneial::utility::EnableMakeShared;

geneial_export_namespace
{

template<typename VALUE_TYPE, typename FITNESS_TYPE>
class MultiValuePermutationCrossover: public MultiValueChromosomeCrossoverOperation<VALUE_TYPE,FITNESS_TYPE>,
                                      public virtual EnableMakeShared<MultiValuePermutationCrossover<VALUE_TYPE,FITNESS_TYPE>>
{
public:
	MultiValuePermutationCrossover(
            const std::shared_ptr<MultiValueChromosomeFactory<VALUE_TYPE, FITNESS_TYPE>> &builderFactory
            ) : MultiValueChromosomeCrossoverOperation<VALUE_TYPE,FITNESS_TYPE>(builderFactory)
    {
    }

    virtual ~MultiValuePermutationCrossover()
    {
    }

    bool isSymmetric() const override
    {
        return false;
    }

    /****
     * Takes a part from the first parent and adds the remainder from the second parent
     *
     *
     * A (mommy)
     * ===========================
     * |A1|A2|A3|A4|A5|A6|A7|A8|A9
     * ===========================
     *
     * B (daddy)
     * ===========================
     * |B1|B2|B3|B4|B5|B6|B7|B8|B9
     * ===========================
     *
     * Random split is 3, direction is left.
     * Result is
     *
     * Child
     * ===================================
     * |A1|A2|A3| + Rest from B which is not in A1...A3
     * ===================================
     *
     */
    virtual typename BaseCrossoverOperation<FITNESS_TYPE>::crossover_result_set doMultiValueCrossover(
            const typename MultiValueChromosome<VALUE_TYPE, FITNESS_TYPE>::const_ptr &mommy,
            const typename MultiValueChromosome<VALUE_TYPE, FITNESS_TYPE>::const_ptr &daddy) const override;


    class Builder : public MultiValueChromosomeCrossoverOperation<VALUE_TYPE,FITNESS_TYPE>::Builder
    {
    public:
        Builder(const std::shared_ptr<MultiValueChromosomeFactory<VALUE_TYPE, FITNESS_TYPE>> & builderFactory) :
                MultiValueChromosomeCrossoverOperation<VALUE_TYPE, FITNESS_TYPE>::Builder(builderFactory)
        {
        }


        virtual typename BaseCrossoverOperation<FITNESS_TYPE>::ptr create() override
        {
            if(! this->_builderFactory )
            {
                throw new std::runtime_error("Must set a Chromosome Factory to build MultiValueCrossover");
            }

            return MultiValuePermutationCrossover<VALUE_TYPE, FITNESS_TYPE>::makeShared(this->_builderFactory);
        }
    };
};

} /* geneial_export_namespace */
} /* private namespace crossover */
} /* private namespace operation */
} /* private namespace geneial */

#include <geneial/core/operations/crossover/MultiValuePermutationCrossover.hpp>

