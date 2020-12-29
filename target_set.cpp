#include "target_set.hpp"

PlexFx::TargetSet::TargetSet() : uses(nullptr), ref(nullptr) { }

PlexFx::TargetSet::TargetSet(Set* set) : uses(new size_t(1)), ref(set) { }

PlexFx::TargetSet::TargetSet(const TargetSet& other) : uses(other.uses), ref(other.ref) {
	*uses += 1;
}

PlexFx::TargetSet::~TargetSet() {
	clean();
}

PlexFx::TargetSet& PlexFx::TargetSet::operator=(const TargetSet& other) {
	clean();
	ref = other.ref;
	uses = other.uses;
	*uses += 1;
	return *this;
}

PlexFx::TargetSet& PlexFx::TargetSet::operator=(Set* ref) {
	clean();
	this->ref = ref;
	*uses = 1;
	return *this;
}

void PlexFx::TargetSet::clean() {
	if (ref) {
		if (*uses <= 1) {
			delete ref;
			delete uses;
		} else {
			*uses -= 1;
		}
	}
}
