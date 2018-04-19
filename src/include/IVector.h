#ifndef IVECTOR_H
#define IVECTOR_H

#include <QSharedPointer>

class Logger;
enum ReturnCode;
enum TypeNorm;

class IVector{
public:
	using vector_ptr = QSharedPointer<IVector>;

	enum ReturnCode {
		NO_ERRORS,
		DIFFERENT_DIMENSIONS,
		MEMORY_ALLOCATION,
		OUT_OF_RANGE
	};

	enum TypeNorm {
		NORM1,
		NORM2,
		INF
	};

    static vector_ptr createVector(Logger const& l);
    static vector_ptr moveVector(IVector&& v);
    static vector_ptr copyVector(IVector const& v);

    virtual ReturnCode add(IVector const& added) = 0;
    virtual ReturnCode substract(IVector const& substracted) = 0;
    virtual ReturnCode dotProduct(IVector const& multiplier) = 0;
    virtual ReturnCode crossProduct(IVector const& right) = 0;
    virtual ReturnCode multiplyByScalar(double multipler) = 0;

    virtual ReturnCode setDimension(size_t dim) = 0;
    virtual size_t getDimension() const = 0;
    virtual ReturnCode getElement(size_t index, double& elem) const = 0;
    virtual ReturnCode setElement(size_t index, double elem) = 0;
    virtual ReturnCode setVector(IVector const& v) = 0;
    //virtual double const* getPtr() const = 0;
    virtual QSharedPointer<Logger> getLogger() const = 0;
    virtual void setLogger(Logger const& l) = 0;
	//TYPE_ID get_type_info()

    virtual double norm(TypeNorm t) const = 0;
    virtual bool compare(TypeNorm t, IVector const& v) const = 0;
    virtual bool GT(TypeNorm t, IVector const& v) const = 0;
    virtual bool LT(TypeNorm t, IVector const& v) const = 0;
    virtual ~IVector() {};
protected:
	IVector() {};
};


#endif // IVECTOR_H
