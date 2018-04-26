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

IVector::ReturnCode IVectorImpl::add(IVector const & added)
{
	IVector::ReturnCode error = NO_ERRORS;
	if (this->dim != added.getDimension())
	{
		error = DIFFERENT_DIMENSIONS;
	}
	for (int i = 0; i < this->dim; i++)
	{
		double tmp = 0;
		error = added.getElement(i, tmp);
		if (error != NO_ERRORS)
			break;
		this->elem[i] += tmp;
	}
	return error;
}

IVector::ReturnCode IVectorImpl::substract(IVector const & substracted)
{
	IVector::ReturnCode error = NO_ERRORS;
	if (this->dim != substracted.getDimension())
	{
		error = DIFFERENT_DIMENSIONS;
	}
	for (int i = 0; i < this->dim; i++)
	{
		double tmp = 0;
		error = substracted.getElement(i, tmp);
		if (error != NO_ERRORS)
			break;
		this->elem[i] -= tmp;
	}
	return error;
}

IVector::ReturnCode IVectorImpl::dotProduct(IVector const & multiplier)
{
	IVector::ReturnCode error = NO_ERRORS;
	if (this->dim != multiplier.getDimension())
	{
		error = DIFFERENT_DIMENSIONS;
	}
	for (int i = 0; i < this->dim; i++)
	{
		double tmp = 0;
		error = multiplier.getElement(i, tmp);
		if (error != NO_ERRORS)
			break;
		this->elem[i] *= tmp;
	}
	return error;
}

IVector::ReturnCode IVectorImpl::crossProduct(IVector const & right)
{
	return IVector::ReturnCode();
}

IVector::ReturnCode IVectorImpl::multiplyByScalar(double multipler)
{
	IVector::ReturnCode error = NO_ERRORS;
	for (int i = 0; i < this->dim; i++)
	{
		this->elem[i] *= multipler;
	}
	return error;
}

IVector::ReturnCode IVectorImpl::getElement(size_t index, double & elem) const
{
	IVector::ReturnCode error = NO_ERRORS;
	if (index > this->dim)
	{
		error = OUT_OF_RANGE;
	}
	elem = this->elem[index];
	return error;
}

IVector::ReturnCode IVectorImpl::setElement(size_t index, double elem)
{
	IVector::ReturnCode error = NO_ERRORS;
	if (index > this->dim)
	{
		error = OUT_OF_RANGE;
	}
	this->elem[index] = elem;
	return error;
}

IVector::ReturnCode IVectorImpl::setVector(IVector const & v)
{
	return IVector::ReturnCode();
}

QSharedPointer<Logger> IVectorImpl::getLogger() const
{
	return QSharedPointer<Logger>();
}


