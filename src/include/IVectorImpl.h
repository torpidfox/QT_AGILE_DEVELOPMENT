#ifndef IVECTORIMPL_H
#define IVECTORIMPL_H
#include "IVector.h"

class IVectorImpl : public virtual IVector{
public:
    static IVector::vector_ptr createVector(Logger const& l);
    static IVector::vector_ptr moveVector(IVectorImpl&& v);
    static IVector::vector_ptr copyVector(const IVectorImpl& v);

	IVector::ReturnCode add(IVector const& added) override;
	IVector::ReturnCode substract(IVector const& substracted) override;
    IVector::ReturnCode dotProduct(IVector const& multiplier) override;
    IVector::ReturnCode crossProduct(IVector const& right) override;
	IVector::ReturnCode multiplyByScalar(double multipler) override;

    IVector::ReturnCode setDimension(size_t dim) { return ReturnCode::NO_ERRORS; }; //пока IVector::ReturnCode, далее - IVector::ReturnCode_CODE
	size_t getDimension() const { return 1; };
    IVector::ReturnCode getElement(size_t index, double& elem) const override ;
    IVector::ReturnCode setElement(size_t index, double elem) override;
    IVector::ReturnCode setVector(IVector const& v) override;
	QSharedPointer<Logger> getLogger() const override;
	void setLogger(Logger const& l) override;

    double norm(TypeNorm t) const override;
    bool compare(TypeNorm t, IVector const& v) const override;
    bool GT(TypeNorm t, IVector const& v) const override;
    bool LT(TypeNorm t, IVector const& v) const override;
protected:
    IVectorImpl(Logger const& l);
    IVectorImpl(IVectorImpl const& v);
    IVectorImpl(IVectorImpl&& v);
};

#endif // IVECTORIMPL_H
