#pragma once

#include <cassert>

namespace geneial
{
namespace operation
{
namespace mutation
{

class MutationSettings
{
private:

    /**
     * probability that one chromosome is choosen for mutation
     */

    double _probability;

    /**
     * _amountOfMutation defines the probability to choose a value in a chromosome.
     */
    double _amountOfMutation;

    /**
     * _amountOfPointsOfMutation defines at how many points, mutation will change a chromosome.
     * Does ignore _amountOfMutation.
     * 0 Will turn of this feature, and switch to _amountOfMutation
     */
    unsigned int _amountOfPointsOfMutation;

public:
    virtual ~MutationSettings()
    {
    }

    MutationSettings(const double probability, const double amountOfMutation, const unsigned int amountOfPointsOfMutation)
    {
        assert((probability <= 1) && (probability >= 0));
        _probability = probability;
        _amountOfPointsOfMutation = amountOfPointsOfMutation;
        _amountOfMutation = amountOfMutation;
    }

    double getPropability() const
    {
        return _probability;
    }

    double getAmountOfMutation() const
    {
        return _amountOfMutation;
    }

    unsigned int getAmountOfPointsOfMutation() const
    {
        return _amountOfPointsOfMutation;
    }

    void setAmountOfPointsOfMutation(const unsigned int amount)
    {
        _amountOfPointsOfMutation = amount;
    }

    void setPropability(const double propabilityOfMutation)
    {
        _probability = propabilityOfMutation;
    }

    void setAmountOfMutation(const double amountOfMutation)
    {
        _amountOfMutation = amountOfMutation;
    }
};
//Class MutationSettings

} /* namespace mutation */
} /* namespace operation */
} /* namespace geneial */

