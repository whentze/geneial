/*
 * FitnessDeltaCriterion.h
 *
 *  Created on: Dec 10, 2014
 *      Author: bewo
 */

#ifndef FITNESSDELTACRITERION_H_
#define FITNESSDELTACRITERION_H_

#include <geneial/core/population/management/BaseManager.h>
#include <geneial/algorithm/criteria/BaseStoppingCriterion.h>

using namespace GeneticLibrary::Population::Manager;

namespace GeneticLibrary {
namespace Algorithm {
namespace StoppingCriteria {


//TODO (bewo) Idea to implement here: -> c.f. TrailingStop in Stock market
//Trace the best chromosome, when its gets worser due as a given threshold abort.

template <typename FITNESS_TYPE>
class TrailingStopCriterion : public BaseStoppingCriterion<FITNESS_TYPE> {
public:
	virtual ~TrailingStopCriterion() {};
	virtual bool wasReached(BaseManager<FITNESS_TYPE> &manager){
		//TODO (bewo) here be dragons!
		return true;
	}
};

} /* namespace StoppingCriteria */
} /* namespace Algorithm */
} /* namespace GeneticLibrary */

#endif /* FITNESSDELTACRITERION_H_ */