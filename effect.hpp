#pragma once

#include <stdlib.h>
#include "definitions.hpp"
#include "target_set.hpp"

namespace PlexFx {

class Effect {
public:
	// Callback function should perform the effect given the settings here
	bool (*callback)(Effect& effect) = nullptr;

	// Unspecified data which can be used however necessary. Freed automatically
	void* data = nullptr;

	// Specify which indices the effect should apply to
	TargetSet targets;

	ID id;

	// Should be called at a regular interval
	inline bool update() {
		if (callback != nullptr) return callback(*this);
		else return false;
	}
	inline ~Effect() {
		free(data);
	}
};

} // end namespace PlexFx
