/*
 * BaseCouplingOperation.h
 *
 *  Created on: Dec 12, 2014
 *      Author: bewo
 */

#ifndef BASECOUPLINGOPERATION_H_
#define BASECOUPLINGOPERATION_H_

#include <geneial/core/operations/coupling/CouplingSettings.h>
#include <geneial/core/operations/selection/BaseSelectionOperation.h>
#include <geneial/core/operations/crossover/BaseCrossoverOperation.h>

#include <geneial/core/population/management/BaseManager.h>
using namespace GeneticLibrary::Population::Manager;
using namespace GeneticLibrary::Operation::Selection;
using namespace GeneticLibrary::Operation::Crossover;

namespace GeneticLibrary {
namespace Operation {
namespace Coupling {



template <typename FITNESS_TYPE>
class BaseCouplingOperation {
private:
	CouplingSettings* _settings;
public:
	typedef typename Population::Population<FITNESS_TYPE>::chromosome_container offspring_result_set;
	BaseCouplingOperation(CouplingSettings *settings): _settings(settings)  {};
	virtual ~BaseCouplingOperation() {};

	virtual offspring_result_set doCopulate
				(
						typename BaseSelectionOperation<FITNESS_TYPE>::selection_result_set &mating_pool,
						BaseCrossoverOperation<FITNESS_TYPE> *crossoverOperation,
						BaseManager<FITNESS_TYPE> &manager
				) = 0;

	CouplingSettings* const& getSettings() const {
		return _settings;
	}

	void setSettings(const CouplingSettings*& settings) {
		_settings = settings;
	}
};

} /* namespace Coupling */
} /* namespace Operation */
} /* namespace GeneticLibrary */

#endif /* BASECOUPLINGOPERATION_H_ */
