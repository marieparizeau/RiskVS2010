#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>

using namespace std;

class Subject
{
public:
	virtual void attach(Observer* o);
	virtual void detach(Observer* o);
	virtual void notify();
	Subject();
	~Subject();
private:
	list<Observer*> *_observers;
};

#endif