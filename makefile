CC = g++
CFLAGS = -std=c++11

complex: test.cpp Complex.cpp Complex.hpp catch.hpp
	$(CC) $(CFLAGS) -c Complex.cpp

test: test.cpp Complex.cpp Complex.hpp catch.hpp
	$(CC) $(CFLAGS) -o test Complex.cpp test.cpp && ./test

zip: test.cpp Complex.cpp Complex.hpp catch.hpp
	mkdir src
	cp Complex.cpp src/Complex.cpp
	cp Complex.hpp src/Complex.hpp
	cp test.cpp src/test.cpp
	cp catch.hpp src/catch.cpp
	zip -r complex.zip src

clean:
	rm *.o
	rm test
