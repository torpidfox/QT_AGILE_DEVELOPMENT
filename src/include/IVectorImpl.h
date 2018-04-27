#ifndef IVECTORIMPL_H
#define IVECTORIMPL_H
#include<QVector>
#include "include/IVector.h"

#define STATIC_CONSTRUCTOR(type, ...)\
 {type* constructed = new type(__VA_ARGS__);\
  if(constructed == nullptr) \
{err = opt::ReturnCode::MEMORY_ALLOCATION;}\
 return QSharedPointer<IVector>(constructed);}

#define DIM_CHECK(second)\
 {if (_dim != second.getDimension())\
    { return opt::ReturnCode::DIFFERENT_DIMENSIONS;}}

#define RANGE_CHECK(ind)\
{ if (ind > _dim)\
    { return opt::ReturnCode::OUT_OF_RANGE; }}

class IVectorImpl : public virtual IVector{
public:
    static IVector::vector_ptr createVector(opt::Logger const& l);
    static IVector::vector_ptr moveVector(IVectorImpl&& v);
    static IVector::vector_ptr copyVector(const IVectorImpl& v);

    opt::ReturnCode add(IVector const& added) override;
    opt::ReturnCode substract(IVector const& substracted) override;
    opt::ReturnCode dotProduct(IVector const& multiplier) override;
    //opt::ReturnCode crossProduct(IVector const& right) override;
    opt::ReturnCode multiplyByScalar(double multipler) override;

    //opt::ReturnCode setDimension(size_t dim); //пока opt::ReturnCode, далее - opt::ReturnCode_CODE
    size_t getDimension() const override { return _dim; }
    opt::ReturnCode getElement(size_t index, double& elem) const override;
    opt::ReturnCode setElement(size_t index, double elem) override;
    opt::ReturnCode setVector(IVector const& v) override;
    //inline QSharedPointer<opt::Logger> getLogger() const override;

    double norm(opt::TypeNorm t) const override;
    bool GT(opt::TypeNorm t, IVector const& v) const override;
    bool LT(opt::TypeNorm t, IVector const& v) const override;
    bool eq(opt::TypeNorm t, IVector const& v) const override;

    ~IVectorImpl() override {}
protected:
    //IVectorImpl(opt::Logger const& l);
    IVectorImpl(IVectorImpl const& v);
    /*IVectorImpl(IVectorImpl&& v)
        : _dim(std::move(v._dim),
               _vals(v._vals),
               _l(std::move(v._l)) {};*/
private:
    inline double _norm_l1() const;
    inline double _norm_l2() const;

    QVector<double> _vals;
    unsigned int _dim;
    QSharedPointer<opt::Logger> _l;
};

#endif // IVECTORIMPL_H
