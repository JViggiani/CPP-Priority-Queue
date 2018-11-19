#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include <string>

class OrderQueue
{
	private:
		int queueSize;
		Order *queue[queueSize]

	
	public:
		int addOrder(Order order);

};

#endif
