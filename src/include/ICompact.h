#pragma once

#include<QVector>
#include<QPair>
#include<QSharedPointer>
#include "IVector.h"


class ICompact{
public:
	using compact_ptr = QSharedPointer<ICompact>;
	using compact_base = QVector<QPair<compact_ptr, compact_ptr>>;

	enum ErrorCode {
		NO_ERRORS,
		MEMORY_ALLOCATION,
		DIMENSIONS_MISMATCH
	};
    virtual ErrorCode Intersection(ICompact const& c) = 0;
    virtual ErrorCode Union(ICompact const& c) = 0;
    virtual ErrorCode Difference(ICompact const& c) = 0;
    virtual ErrorCode SymDifference(ICompact const& c) = 0;
    virtual ErrorCode MakeConvex() = 0;

    static compact_ptr CreateCompact(compact_base const& boundaries, IVector step);
    static compact_ptr CopyCompact(ICompact const& c);
    static compact_ptr MoveCompact(ICompact&& c);
protected:
	ICompact() {};
};