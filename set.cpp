#include "set.hpp"

namespace PlexFx {

Set::Iterator::Iterator(Set& set, PLEXFX_TYPE_BOUND init) : set(set), i(init) { }

PLEXFX_TYPE_BOUND Range::at(PLEXFX_TYPE_BOUND i) {
	return start + i;
}

PLEXFX_TYPE_BOUND Range::size() {
	return end - start;
}

Range::Range(PLEXFX_TYPE_BOUND start, PLEXFX_TYPE_BOUND end) : start(start), end(end) { }

}	// end namespace PlexFx
