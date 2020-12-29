#include "set.hpp"

PlexFx::Set::Iterator::Iterator(Set& set, Index init) : set(set), i(init) { }

PlexFx::Index PlexFx::Range::at(Index i) {
	return start + i;
}

PlexFx::Index PlexFx::Range::size() {
	return end - start;
}

PlexFx::Range::Range(Index start, Index end) : start(start), end(end) { }
