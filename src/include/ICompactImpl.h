#include <memory>
#include "ICompact.h"

class ICompactImpl : public virtual ICompact{


public:
	ErrorCode Intersection(ICompact const& c) { return NO_ERRORS; };
	ErrorCode Union(ICompact const& c) { return NO_ERRORS; };
	ErrorCode Difference(ICompact const& c) { return NO_ERRORS; };
	ErrorCode SymDifference(ICompact const& c) { return NO_ERRORS; };
	ErrorCode MakeConvex() { return NO_ERRORS; };

    static compact_ptr CreateCompact(compact_base const& boundaries, compact_ptr step);
    static compact_ptr CopyCompact(QSharedPointer<ICompact>& c);
	static compact_ptr MoveCompact(QScopedPointer<ICompact>&& c);
protected:
    ICompactImpl(compact_base boundaries, compact_ptr const& step);
    ICompactImpl(QScopedPointer<ICompact>&& c);
	ICompactImpl(QSharedPointer<ICompact>& c);
private:
    compact_ptr step;
	compact_base boundaries;
};


