#ifndef ORDER_H
#define ORDER_H
#include <string>

class Order
{
	private:
		std::string buyerName_;
		int size_;
		double maxPrice_;
		long int orderTime_;

		int id_;
		friend class OrderQueue;
		/*
			The id works in conjunction with the order queue to remove / retrieve specific orders via the overriden function removeOrder / retrieveOrder
		*/
	
	public:
		Order( const std::string& buyerName, int size, double maxPrice, long int orderTime);
		/* 
			The constructor which constructs the Order object. Sets the properties: buyerName, size, maxPrice, and orderTime
				buyerName is passed by const reference because the name could potentially be expensive to copy and won't change inside the constructor. 
					Null value has undefined functionality
				size is passed by value since the value will be cheap to copy
				interestRate is passed by reference since the interest rate can change for some types of bond
				yearsToMaturity decreases by 1 each year, and this change should be reflected elsewhere in the program, so we also pass by reference
				All values are constant for the constructor because the implementation of the constructor should not change what is defined by the client
		*/

		const std::string& getBuyerName( void );
		/*
			Returns a constant reference to the string name
		*/

		void setBuyerName ( const std::string& name );
		/*
			Sets the buyerName attribute to a provided name as a constant reference
		*/

		int getSize( void );
		/* 
			Returns an integer order size
				TODO: describe what happens with zero, negative or null values
		*/

		void setSize ( const int size );
		/*	
			Sets the size to a given value
				TODO: describe what happens with zero, negative or null values
		*/

		double getMaxPrice( void );
		/* 
			Returns a double value representing the maximum price the buyer is willing to pay per share in pennies
				TODO: describe what happens with zero, negative or null values
		*/

		void setMaxPrice ( const double maxPrice );
		/* 
			Sets the maximum price the buyer is willing to pay per share in pennies
				TODO: describe what happens with zero, negative or null values
		*/

		long int getOrderTime( void );
		/*
			Returns the orderTime for the order as expressed as long int nanoseconds from midnight
			This is the time the order was recieved by the exchange, not the time the order was sent by the client
				TODO: describe what happens with zero, negative or null values. Describe what happens for values greater than the number of nanoseconds in a day
		*/

		void setOrderTime ( const long int orderTime );
		/*
			Sets the orderTime as a long int representing the nanoseconds from midnight 
			This is the time the order was recieved by the exchange, not the time the order was sent by the client
				TODO: describe what happens with zero, negative or null values. Describe what happens for values greater than the number of nanoseconds in a day
		*/

		void displayOrder( void );	
		// Displays all order properties on the standard output stream
};

#endif
