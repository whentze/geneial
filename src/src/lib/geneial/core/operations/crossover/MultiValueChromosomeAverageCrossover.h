#pragma once

#include <geneial/core/operations/crossover/MultiValueChromosomeCrossoverOperation.h>

#include <cassert>

namespace geneial
{
namespace operation
{
namespace crossover
{

template<typename VALUE_TYPE, typename FITNESS_TYPE>
class MultiValueChromosomeAverageCrossover: public MultiValueChromosomeCrossoverOperation<VALUE_TYPE,FITNESS_TYPE>
{
public:
    MultiValueChromosomeAverageCrossover(
            const std::shared_ptr<const MultiValueBuilderSettings<VALUE_TYPE, FITNESS_TYPE>> &builderSettings
            ) : MultiValueChromosomeCrossoverOperation(_builderFactory)
    {
    }

    virtual ~MultiValueChromosomeAverageCrossover()
    {
    }

    bool inline isSymmetric() const override
    {
        return true;
    }

    /****
     * Computes the average of the two parents.
     *
     * Example:
     * Say, A and B are Chromosomes with
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
     * Result is
     *
     * Child
     * ===================================
     * |(A1+B1)/2|(A2+B2)/2| ... |(A9+B9)/2
     * ===================================
     *
     */
    virtual typename BaseCrossoverOperation<FITNESS_TYPE>::crossover_result_set doMultiValueCrossover(
            const typename MultiValueChromosomeFactory<VALUE_TYPE, FITNESS_TYPE>::const_ptr &mommy,
            const typename MultiValueChromosomeFactory<VALUE_TYPE, FITNESS_TYPE>::const_ptr &daddy) const override;


};

} /* namespace crossover */
} /* namespace operation */
} /* namespace geneial */

#include <geneial/core/operations/crossover/MultiValueChromosomeAverageCrossover.hpp>

