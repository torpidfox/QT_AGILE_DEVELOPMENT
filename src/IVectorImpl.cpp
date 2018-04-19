#include "IVectorImpl.h"

IVector::vector_ptr createVector(Logger const& l) {
    return IVectorImpl::createVector(l);
}

IVector::vector_ptr IVectorImpl::copyVector(const IVectorImpl& v) {
    return IVectorImpl::copyVector(v);
}

IVector::vector_ptr IVectorImpl::moveVector(IVectorImpl &&v) {
    return IVectorImpl::moveVector(std::move(v));
}

IVector::vector_ptr IVectorImpl::createVector(Logger const& l){
    return QSharedPointer<IVector>(new IVectorImpl(l));
}

IVector::vector_ptr IVectorImpl::copyVector(IVectorImpl const& v){
    return QSharedPointer<IVector>(new IVectorImpl(v));
}

IVector::vector_ptr IVectorImpl::moveVector(IVectorImpl &&v) {
    return QSharedPointer<IVector>(new IVectorImpl(std::move(v)));
}
