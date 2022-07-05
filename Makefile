FLAGS = -g -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ -shared -o bin/libtienda.so obj/tienda.o obj/producto.o
	mkdir -p bin/include
	cp src/tienda.h src/producto.h ./bin/include
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) tests/tienda_tests.cpp -o obj/tienda_tests.o
	g++ $(FLAGS) tests/producto_tests.cpp -o obj/producto_tests.o
	g++ -g -o bin/tests obj/tienda.o obj/tienda_tests.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin