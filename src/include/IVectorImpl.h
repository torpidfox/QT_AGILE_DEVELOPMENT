#ifndef IVECTORIMPL_H
#define IVECTORIMPL_H
#include<QVector>
#include "IVector.h"

#define DIM_CHECK(second)\
 {if (_dim != second.getDimension())\
    { return opt::DIFFERENT_DIMENSIONS;}};

#define RANGE_CHECK(ind)\
{ if (ind > _dim)\
    { return opt::OUT_OF_RANGE; }};

class IVectorImpl : public IVector
{
public:
    static IVector* copyVector(const IVector& v);
    static IVector* createVector(uint dim);

    opt::ReturnCode add(const IVector& added);
    opt::ReturnCode substract(const IVector& substracted);
    opt::ReturnCode dotProduct(const IVector& multiplier, double& res);
    opt::ReturnCode multiplyByScalar(double multipler);

    size_t getDimension() const { return _dim; }
    opt::ReturnCode getElement(size_t index, double& elem) const;
    opt::ReturnCode setElement(size_t index, double elem);
    opt::ReturnCode setVector(const IVector& v);
    opt::ReturnCode eq(const IVector& v, bool& res) const;

    void unaryMinus();
    double norm(opt::TypeNorm t) const;
    bool GT(opt::TypeNorm t, const IVector& v) const;
    bool LT(opt::TypeNorm t, const IVector& v) const;
    bool eq(opt::TypeNorm t, const IVector& v) const;

    ~IVectorImpl() {}
protected:
    IVectorImpl(const IVector& v);
    IVectorImpl(uint dim);
private:
    inline double _norm_l1() const;
    inline double _norm_l2() const;

    QVector<double> _vals;
    unsigned int _dim;
    //QSharedPointer<opt::Logger> _l;
};


#endif // IVECTORIMPL_H
