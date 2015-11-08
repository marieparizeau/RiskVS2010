#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H
	
#include "Observer.h"
#include "Player.h"

class PlayerView : public Observer
{
public:
	PlayerView();
	PlayerView(Player* s);
	~PlayerView();
	void update();
	void display();
private:
	Player *_subject;
};

#endif