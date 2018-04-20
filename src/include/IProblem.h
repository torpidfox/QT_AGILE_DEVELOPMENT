#include<QSharedPointer>

class IVector;
class ICompact;

class IProblem {
public:
	enum ErrorCode {

	};
	using arg_ptr = QSharedPointer<IVector const>;

	static QSharedPointer<IProblem> createProblem();

	virtual ErrorCode goalFunction(arg_ptr const args, arg_ptr params, double& res) = 0;
	virtual ErrorCode goalFunctionByArgs(arg_ptr const args, double& res) = 0;
	virtual ErrorCode goalFunctionByParams(arg_ptr params, double& res) = 0;
	virtual size_t getArgsDim() const = 0;
	virtual size_t getParamsDim() const = 0;


	template <int ORDER>
	virtual ErrorCode derivativeByParams<ORDER>(size_t index, arg_ptr args, arg_ptr params, double& res) const = 0;

	virtual bool validateArgs(QSharedPointer<const ICompact> c) const = 0;
	virtual bool validateParams(QSharedPointer<const ICompact> c) const = 0;
};