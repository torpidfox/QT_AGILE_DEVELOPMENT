#include<QSharedPointer>

class Logger;


class IBrocker {
public:
	enum Type{};

	IBrocker() = default;
	static QSharedPointer<IBrocker> createBrocker();

	virtual void* getId(Type t) const = 0;
	virtual void release(Type t) = 0;
	virtual ~IBrocker() {};
private:
	IBrocker(QSharedPointer<Logger> l);
	IBrocker(const IBrocker& b);
	IBrocker(IBrocker&& b);
};