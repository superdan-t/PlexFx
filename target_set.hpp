#pragma once

#include <stddef.h>

#include "set.hpp"

namespace PlexFx {

class TargetSet {
public:
	TargetSet();
	TargetSet(Set* set);
	TargetSet(const TargetSet& other);
	~TargetSet();
	inline Set& operator*() const { return *ref; }
	inline Set* operator->() const { return ref; }
	TargetSet& operator=(const TargetSet& other);
	TargetSet& operator=(Set* ref);
private:
	size_t* uses;
	Set* ref;
};

}