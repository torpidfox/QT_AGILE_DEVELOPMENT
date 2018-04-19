#include "ICompactImpl.h"

ICompactImpl::compact_ptr ICompactImpl::CreateCompact(compact_base const& boundaries, compact_ptr step)
{
    return QSharedPointer<ICompact>(new ICompactImpl(boundaries, step));
}

ICompactImpl::compact_ptr ICompactImpl::CopyCompact(QSharedPointer<ICompact>& c)
{
    return QSharedPointer<ICompact>(new ICompactImpl(c));
}

ICompactImpl::compact_ptr ICompactImpl::MoveCompact(QScopedPointer<ICompact>&& c)
{
	return QSharedPointer<ICompact>(new ICompactImpl(std::move(c)));
}
