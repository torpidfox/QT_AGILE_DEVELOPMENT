#ifndef IVECTOR_H
#define IVECTOR_H
#include<cmath>
#include <QSharedPointer>
#include "opt.h"


class IVector{
public:
    static IVector* createVector();
    static IVector* copyVector(QSharedPointer<IVector>& v);

    virtual opt::ReturnCode add(IVector const& added) = 0;
    virtual opt::ReturnCode substract(IVector const& substracted) = 0;
    virtual opt::ReturnCode dotProduct(IVector const& multiplier) = 0;
    virtual opt::ReturnCode multiplyByScalar(double multipler) = 0;

    virtual size_t getDimension() const = 0;
    virtual opt::ReturnCode getElement(size_t index, double& elem) const = 0;
    virtual opt::ReturnCode setElement(size_t index, double elem) = 0;
    virtual opt::ReturnCode setVector(IVector const& v) = 0;
    virtual double const* getPtr() const = 0;

    virtual double norm(opt::TypeNorm t) const = 0;
    virtual bool GT(opt::TypeNorm t, IVector const& v) const = 0;
    virtual bool LT(opt::TypeNorm t, IVector const& v) const = 0;
    virtual bool eq(opt::TypeNorm t, IVector const& v) const = 0;

    virtual ~IVector() {}
protected:
    IVector() {}
};

#endif // IVECTOR_H
