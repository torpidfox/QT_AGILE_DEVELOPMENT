#ifndef PROBLEMIMPL_H
#define PROBLEMIMPL_H
#include "IProblem.h"

class ProblemImpl : public virtual IProblem
{
public:
    static QSharedPointer<IProblem> createProblem();

    ErrorCode goalFunction(QSharedPointer<QVector<double> > const args,
                           QSharedPointer<QVector<double> > const params, double& res);

};

#endif // PROBLEMIMPL_H
