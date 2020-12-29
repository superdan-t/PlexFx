#include "target_set.hpp"
#include <iostream>
PlexFx::TargetSet::TargetSet() : uses(new size_t(0)), ref(nullptr) { }

PlexFx::TargetSet::TargetSet(Set* set) : uses(new size_t(1)), ref(set) { }

PlexFx::TargetSet::TargetSet(const TargetSet& other) : uses(other.uses), ref(other.ref) {
	*uses += 1;
}

PlexFx::TargetSet::~TargetSet() {
	*uses -= 1;
	if (*uses == 0) {
		delete ref;
		delete uses;
	}
}

PlexFx::TargetSet& PlexFx::TargetSet::operator=(const TargetSet& other) {
	ref = other.ref;
	uses = other.uses;
	*uses += 1;
	return *this;
}

PlexFx::TargetSet& PlexFx::TargetSet::operator=(Set* ref) {
	this->ref = ref;
	*uses = 1;
	return *this;
}
