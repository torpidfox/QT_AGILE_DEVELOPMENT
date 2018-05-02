#ifndef IVECTOR_H
#define IVECTOR_H
#include<cmath>
#include <QSharedPointer>
#include "opt.h"

typedef unsigned int uint;
class IVectorImpl;

class IVector{
public:
    static IVector* createVector(uint size);
    static IVector* copyVector(const IVector& v);

    virtual opt::ReturnCode add(IVector const& added) = 0;
    virtual opt::ReturnCode substract(IVector const& substracted) = 0;
    virtual opt::ReturnCode dotProduct(IVector const& multiplier, double& res) = 0;
    virtual opt::ReturnCode multiplyByScalar(double multipler) = 0;

    virtual size_t getDimension() const = 0;
    virtual opt::ReturnCode getElement(size_t index, double& elem) const = 0;
    virtual opt::ReturnCode setElement(size_t index, double elem) = 0;
    virtual opt::ReturnCode setVector(const IVector&) = 0;
    virtual opt::ReturnCode eq(const IVector& v, bool& res) const = 0;
    //virtual double const* getPtr() const = 0;

    virtual double norm(opt::TypeNorm t) const = 0;
    virtual bool GT(opt::TypeNorm t, const IVector& v) const = 0;
    virtual bool LT(opt::TypeNorm t, const IVector& v) const = 0;
    virtual bool eq(opt::TypeNorm t, const IVector& v) const = 0;
    virtual void unaryMinus() = 0;

    virtual ~IVector() {}
protected:
    IVector() {}
};

#endif // IVECTOR_H
