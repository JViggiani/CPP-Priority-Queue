INCLUDE_DIRS = -I. -I/home/ibutt/googletest-master/googletest/include 
WARNINGS = -Wall -Werror
OBJECTS = order.o order.t.o
GTESTMAIN = /home/ibutt/googletest-master/googletest/make/gtest_main.a

order : $(OBJECTS)
	g++ -lpthread -o order $(GTESTMAIN) $(OBJECTS)

order.o : order.h order.cpp
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c order.cpp
	
order.t.o : order.h order.t.cpp
	g++ $(WARNINGS) $(INCLUDE_DIRS) -c order.t.cpp

clean : 
	rm $(OBJECTS) order

