#pragma once

#include <geneial/core/operations/mutation/MultiValueChromosomeMutationOperation.h>

#include <cassert>

geneial_private_namespace(geneial)
{
geneial_private_namespace(operation)
{
geneial_private_namespace(mutation)
{

geneial_export_namespace
{

template<typename VALUE_TYPE, typename FITNESS_TYPE>
class UniformMutationOperation: public MultiValueChromosomeMutationOperation<VALUE_TYPE,FITNESS_TYPE>
{
public:
    /*
     * UniformMutationOperation Mutates a chromosome, by replacing some of it's values randomly.
     */
    UniformMutationOperation(
            const std::shared_ptr<const MutationSettings> &settings,
            const std::shared_ptr<const BaseChoosingOperation<FITNESS_TYPE>> &choosingOperation,
            const std::shared_ptr<MultiValueChromosomeFactory<VALUE_TYPE, FITNESS_TYPE>> &builderFactory) :

                MultiValueChromosomeMutationOperation<VALUE_TYPE,FITNESS_TYPE>(
                        settings,
                        choosingOperation,
                        builderFactory
                        )
    {
    }


    /*
     *  Returns a new chromosome which is a partially mutated version of the old one.
     *  */
    virtual typename Population<FITNESS_TYPE>::chromosome_container doMutate(
            const typename Population<FITNESS_TYPE>::chromosome_container &mutants, BaseManager<FITNESS_TYPE> &manager) const override;


};

} /* geneial_export_namespace */
} /* private namespace mutation */
} /* private namespace operation */
} /* private namespace geneial */

#include <geneial/core/operations/mutation/UniformMutationOperation.hpp>

