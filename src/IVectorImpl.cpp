#include "include/IVectorImpl.h"

//add error logging!
/*IVector::vector_ptr IVectorImpl::createVector(opt::Logger const& l) {
    opt::ReturnCode err;
    STATIC_CONSTRUCTOR(IVectorImpl, l);
}*/

IVectorImpl::IVectorImpl(IVectorImpl const& v){
    _dim = v._dim;
    _vals = v._vals;
    _l = v._l;
}

IVector::vector_ptr IVectorImpl::copyVector(const IVectorImpl& v) {
    opt::ReturnCode err;
    STATIC_CONSTRUCTOR(IVectorImpl, v);
}

/*IVector::vector_ptr IVectorImpl::moveVector(IVectorImpl &&v) {
    opt::ReturnCode err;
    STATIC_CONSTRUCTOR(IVectorImpl, std::move(v));
}*/

opt::ReturnCode IVectorImpl::add(IVector const& added)
{ 
    DIM_CHECK(added);

    opt::ReturnCode err = opt::ReturnCode::NO_ERRORS;

    for (unsigned int i = 0; i < _dim; i++)
	{
		double tmp = 0;
		err = added.getElement(i, tmp);
        if (err != opt::ReturnCode::NO_ERRORS)
			return err;
        _vals[i] += tmp;
	}
	return err;
}

opt::ReturnCode IVectorImpl::substract(IVector const & substracted)
{
	DIM_CHECK(substracted)

    opt::ReturnCode err = opt::ReturnCode::NO_ERRORS;

    for (unsigned int i = 0; i < _dim; i++)
	{
		double tmp = 0;
        err = substracted.getElement(i, tmp);
        if (err != opt::ReturnCode::NO_ERRORS)
			return err;
		_vals[i] -= tmp;
	}
    return err;
}

opt::ReturnCode IVectorImpl::dotProduct(IVector const & multiplier)
{
    DIM_CHECK(multiplier)

    opt::ReturnCode error = opt::ReturnCode::NO_ERRORS;

    for (int i = 0; i < _dim; i++)
	{
		double tmp = 0;
		error = multiplier.getElement(i, tmp);
        if (error != opt::ReturnCode::NO_ERRORS)
			return error;

		_vals[i] *= tmp;
	}
	return error;
}


opt::ReturnCode IVectorImpl::multiplyByScalar(double multipler)
{
    for (int i = 0; i < _dim; i++)
	{
		_vals[i] *= multipler;
	}
    return opt::ReturnCode::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::getElement(size_t index, double & elem) const
{
	RANGE_CHECK(index)

	elem = _vals[index];
    return opt::ReturnCode::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::setElement(size_t index, double elem)
{
	RANGE_CHECK(index)

	_vals[index] = elem;
    return opt::ReturnCode::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::setVector(IVector const & v)
{
	DIM_CHECK(v)

    for (unsigned i = 0; i < _dim; i++){
        v.getElement(i, _vals[i]);
	}

    return opt::ReturnCode::NO_ERRORS;
}

double IVectorImpl::_norm_l2() const{
    double res = 0;

    for(unsigned i = 0; i < _dim; i++)
    {
        res += _vals[i] * _vals[i];
    }

    return std::sqrt(res);
}

double IVectorImpl::_norm_l1() const{
    double res = 0;

    for(unsigned i = 0; i < _dim; i++)
    {
        res += std::abs(_vals[i]);
    }

    return res;
}

double IVectorImpl::norm(opt::TypeNorm t) const
{
    switch(t)
    {
    case opt::TypeNorm::NORM1:
    {
        return _norm_l1();
    }
    case opt::TypeNorm::NORM2:
    {
        return _norm_l1();
    }
    defualt:
        return -1;
    }

    return -1;
}

bool IVectorImpl::GT(opt::TypeNorm t, IVector const& v) const
{
    return norm(t) > v.norm(t);
}

bool IVectorImpl::LT(opt::TypeNorm t, IVector const& v) const
{
    return norm(t) < v.norm(t);
}

bool IVectorImpl::eq(opt::TypeNorm t, IVector const& v) const
{
    return norm(t) == v.norm(t);
}



