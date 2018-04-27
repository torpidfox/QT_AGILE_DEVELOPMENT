#ifndef IVECTOR_H
#define IVECTOR_H
#include<cmath>
#include <QSharedPointer>

namespace opt {

class Logger;

enum ReturnCode {
    NO_ERRORS,
    DIFFERENT_DIMENSIONS,
    MEMORY_ALLOCATION,
    OUT_OF_RANGE
};

enum TypeNorm {
    NORM1,
    NORM2
};
}

class IVector{
public:
	using vector_ptr = QSharedPointer<IVector>;

    static vector_ptr createVector(opt::Logger const& l);
    static vector_ptr moveVector(IVector&& v);
    static vector_ptr copyVector(IVector const& v);

    virtual opt::ReturnCode add(IVector const& added) = 0;
    virtual opt::ReturnCode substract(IVector const& substracted) = 0;
    virtual opt::ReturnCode dotProduct(IVector const& multiplier) = 0;
    //virtual opt::ReturnCode crossProduct(IVector const& right) = 0;
    virtual opt::ReturnCode multiplyByScalar(double multipler) = 0;

    //virtual opt::ReturnCode setDimension(size_t dim) = 0;
    virtual size_t getDimension() const = 0;
    virtual opt::ReturnCode getElement(size_t index, double& elem) const = 0;
    virtual opt::ReturnCode setElement(size_t index, double elem) = 0;
    virtual opt::ReturnCode setVector(IVector const& v) = 0;
    //virtual double const* getPtr() const = 0;
    //virtual QSharedPointer<opt::Logger> getLogger() const = 0;
    //virtual void setLogger(opt::Logger const& l) = 0;
	//TYPE_ID get_type_info()

    virtual double norm(opt::TypeNorm t) const = 0;
    virtual bool GT(opt::TypeNorm t, IVector const& v) const = 0;
    virtual bool LT(opt::TypeNorm t, IVector const& v) const = 0;
    virtual bool eq(opt::TypeNorm t, IVector const& v) const = 0;

    virtual ~IVector() {}
protected:
    IVector() {}
};

#endif // IVECTOR_H
