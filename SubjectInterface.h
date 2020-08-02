#pragma once
#include "ObserverInterface.h"

class SubjectInterface
{
private:

public:
	SubjectInterface() {}

	virtual void attach(std::shared_ptr<ObserverInterface>) = 0;
	virtual void detach(std::shared_ptr<ObserverInterface>) = 0;
	virtual void notify() = 0;
};