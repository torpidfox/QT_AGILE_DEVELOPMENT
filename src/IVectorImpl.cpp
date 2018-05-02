#include "IVectorImpl.h"

//add error logging!
/*IVector::vector_ptr IVectorImpl::createVector(opt::Logger const& l) {
    opt::ReturnCode err;
    STATIC_CONSTRUCTOR(IVectorImpl, l);
}*/
IVector* IVector::createVector(uint size)
{
    return IVectorImpl::createVector(size);
}

IVector* IVector::copyVector(const IVector& v)
{
    return IVectorImpl::copyVector(v);
}

IVectorImpl::IVectorImpl(const IVector& v){
    _dim = v.getDimension();
    _vals = QVector<double>(_dim);
    this->copyVector(v);
}

IVectorImpl::IVectorImpl(uint dim){
    _dim = dim;
    _vals = QVector<double>(_dim);
}

IVector* IVectorImpl::copyVector(const IVector& v)
{
    return new IVectorImpl(v);
}

IVector* IVectorImpl::createVector(uint dim)
{
    return new IVectorImpl(dim);
}


opt::ReturnCode IVectorImpl::add(IVector const& added)
{ 
    DIM_CHECK(added)

    opt::ReturnCode err = opt::NO_ERRORS;
    double tmp = 0;

    for (uint i = 0; i < _dim; i++)
    {
        err = added.getElement(i, tmp);
        if (err != opt::NO_ERRORS)
            return err;
        _vals[i] += tmp;
    }

    return err;
}


opt::ReturnCode IVectorImpl::dotProduct(const IVector& multiplier, double& res)
{
    DIM_CHECK(multiplier)

    opt::ReturnCode error = opt::NO_ERRORS;
    res = 0;

    for (uint i = 0; i < _dim; i++)
	{
        double tmp = 0;

        error = multiplier.getElement(i, tmp);
        if (error)
                return error;

        res += _vals[i] * tmp;
	}

	return error;
}


opt::ReturnCode IVectorImpl::multiplyByScalar(double multipler)
{
    for (uint i = 0; i < _dim; i++)
    {
        _vals[i] *= multipler;
    }

    return opt::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::getElement(size_t index, double& elem) const
{
    RANGE_CHECK(index)

    elem = _vals[index];

    return opt::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::setElement(size_t index, double elem)
{
    RANGE_CHECK(index)
    _vals[index] = elem;

    return opt::NO_ERRORS;
}

opt::ReturnCode IVectorImpl::setVector(const IVector& v)
{
    DIM_CHECK(v)
    opt::ReturnCode err = opt::NO_ERRORS;

    for (unsigned i = 0; i < _dim; i++)
    {
        err = v.getElement(i, _vals[i]);
    }

    return err;
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
    case opt::NORM1:
    {
        return _norm_l1();
    }
    case opt::NORM2:
    {
        return _norm_l1();
    }
    default:
        return -1;
    }
}

bool IVectorImpl::GT(opt::TypeNorm t, const IVector& v) const
{
    return norm(t) > v.norm(t);
}

bool IVectorImpl::LT(opt::TypeNorm t, const IVector& v) const
{
    return norm(t) < v.norm(t);
}

bool IVectorImpl::eq(opt::TypeNorm t, const IVector& v) const
{
    return norm(t) == v.norm(t);
}

opt::ReturnCode IVectorImpl::substract(IVector const& substracted){
    DIM_CHECK(substracted)

    double buff = 0;
    opt::ReturnCode err = opt::NO_ERRORS;

    for (uint i = 0; i < _dim; i++)
    {
        err = substracted.getElement(i, buff);

        if(err)
            return err;

        _vals[i] -= buff;
    }

    return err;
}

void IVectorImpl::unaryMinus()
{
    for (uint i = 0; i < _dim; i++)
    {
        _vals[i] = -_vals[i];
    }
}

opt::ReturnCode IVectorImpl::eq(const IVector& v, bool& res) const
{
    DIM_CHECK(v)

    double buff = 0;
    opt::ReturnCode err = opt::NO_ERRORS;

    for (uint i = 0; i < _dim; i++)
    {
        err = v.getElement(i, buff);

        if(_vals[i] != buff)
        {
            res = false;
            return err;
        }
    }

    res = true;
    return err;
}


