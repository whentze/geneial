/*
 * ReplaceWorstOperation.h
 *
 *  Created on: Dec 21, 2014
 *      Author: bewo
 */

#ifndef REPLACEWORSTOPERATION_H_
#define REPLACEWORSTOPERATION_H_

#include <geneial/core/operations/replacement/BaseReplacementOperation.h>


namespace GeneticLibrary {
namespace Operation {
namespace Replacement {

using namespace GeneticLibrary::Population;
using namespace GeneticLibrary::Population::Manager;

/**
 * Select a number of parents based on a certain criteria.
 */
template <typename FITNESS_TYPE>
class ReplaceWorstOperation : public BaseReplacementOperation<FITNESS_TYPE>{
private:
	unsigned int getAmountToReplace(
			const Population<FITNESS_TYPE> &population,
			const typename Coupling::BaseCouplingOperation<FITNESS_TYPE>::offspring_result_set &offspring) const;
public:
	ReplaceWorstOperation(BaseReplacementSettings* settings): BaseReplacementOperation<FITNESS_TYPE>(settings){};
	virtual ~ReplaceWorstOperation() {};

	void doReplace(
			Population<FITNESS_TYPE> &population,
			typename Selection::BaseSelectionOperation<FITNESS_TYPE>::selection_result_set &parents,
			typename Coupling::BaseCouplingOperation<FITNESS_TYPE>::offspring_result_set &offspring,
			BaseManager<FITNESS_TYPE> &manager);

};

} /* namespace Replacement */
} /* namespace Operation */
} /* namespace GeneticLibrary */

#include <geneial/core/operations/replacement/ReplaceWorstOperation.hpp>

#endif /* REPLACEWORSTOPERATION_H_ */
