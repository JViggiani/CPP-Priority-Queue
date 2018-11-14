#include <order.h>
#include <string>
#include <iostream>

Order::Order(const std::string& buyerName, int size, double maxPrice, long int orderTime)
{
	buyerName_ = buyerName;
	size_ = size;
	maxPrice_ = maxPrice;
	orderTime_ = orderTime;
}

const std::string& Order::getBuyerName( void ) 
{
   return buyerName_;
}

void Order::setBuyerName ( const std::string& buyerName )
{
	buyerName_ = buyerName;
}

int Order::getSize( void ) 
{
   return size_;
}

void Order::setSize (const int size )
{
	size_ = size;
}

double Order::getMaxPrice( void ) 
{
   return maxPrice_;
}

void Order::setMaxPrice ( double maxPrice )
{
	maxPrice_ = maxPrice;
}

long int Order::getOrderTime( void )
{
   return orderTime_;
}

void Order::setOrderTime ( long int orderTime )
{
	orderTime_ = orderTime;
}

void Order::displayOrder( void )
{
	std::cout << "Order Name: " << buyerName_ << "\n"
		<< "Order Size: " << size_ << "\n"
		<< "Order Max Size: " << maxPrice_ << "%\n"
		<< "Order Time: " << orderTime_ << "\n";
};

