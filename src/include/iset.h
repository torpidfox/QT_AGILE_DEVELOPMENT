#ifndef ISET_H
#define ISET_H
#include<QVariant>
#include<QSharedData>
#include "opt.h"

class ISet{
    public:
        static ISet* createISet(opt::Type t);
        static ISet* copyISet(QSharedPointer<ISet> const& r);

        virtual ~ISet() {}

        virtual opt::ErrorCode add(QVariant& elem) = 0;
        virtual opt::ErrorCode getByIndex(size_t ind, QVariant& dst) const = 0;
        virtual opt::ErrorCode insert(size_t ind, QVariant& el) = 0;
        virtual opt::ErrorCode remove(size_t ind) = 0;
    protected:
        ISet() = default;
}

#endif // ISET_H
