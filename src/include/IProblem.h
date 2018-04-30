#ifndef IPROBLEM_H
#define IPROBLEM_H
#include"opt.h"


typedef  QSharedPointer<IVector const> arg_ptr ;

class IProblem{
    public:

        static IProblem* createProblem();

        virtual opt::ErrorCode goalFunction(arg_ptr const args, arg_ptr params, double& res) = 0;
        virtual opt::ErrorCode goalFunctionByArgs(arg_ptr const args, double& res) = 0;
        virtual opt::ErrorCode goalFunctionByParams(arg_ptr params, double& res) = 0;
        virtual size_t getArgsDim() const = 0;
        virtual size_t getParamsDim() const = 0;


        template <int ORDER>
        #добавить двумерный индекс
        virtual opt::ErrorCode derivativeByArgs<ORDER>(size_t index, arg_ptr args, arg_ptr params, double& res) const = 0;
        virtual opt::ErrorCode derivativeByParams<ORDER>(size_t index, arg_ptr args, arg_ptr params, double& res) const = 0;

        virtual bool validateArgs(QSharedPointer<ICompact> c) const = 0;
        virtual bool validateParams(QSharedPointer<ICompact> c) const = 0;
        virtual ~IProblem() {}
    }

#endif // IPROBLEM_H
