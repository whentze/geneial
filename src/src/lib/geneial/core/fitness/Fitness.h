#pragma once

#include <geneial/utility/Printable.h>

#include <boost/optional.hpp>

#include <memory>

namespace geneial
{

using namespace geneial::utility;
/**
 * This class encapsulates the fitness.
 * In most cases this will only encapsulate a single value,
 * However being polymorphic, it enables the user to store other values or states associated with the fitness
 *
 * This is particulary useful when using scaling or scenarios where the fitness computation is expensive and should be reused.
 */
template<typename FITNESS_TYPE>
class Fitness: public Printable
{
private:
    boost::optional<FITNESS_TYPE> _value;

public:
    Fitness()
    {
    }

    explicit Fitness(FITNESS_TYPE value) :
            _value(value)
    {
    }

    virtual ~Fitness()
    {
    }

    inline void set(FITNESS_TYPE value);

    inline FITNESS_TYPE get() const;

    //cast operator overload
    inline operator FITNESS_TYPE() const
    {
        return get();
    }

    //cast operator overload
    inline FITNESS_TYPE operator()() const
    {
        return get();
    }

    virtual bool isValid() const;

    void print(std::ostream&) const;
};

} /* namespace geneial */

#include <geneial/core/fitness/Fitness.hpp>

