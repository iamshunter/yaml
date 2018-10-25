all : yt.x

yt.x : yt.o  Makefile
	g++ -std=gnu++11 -Bstatic -I. -I./yaml-cpp/include -I./yaml-cpp/include/yaml-cpp -o yt.x yt.o -lz -L./yaml-cpp/build -lyaml-cpp

yt.o : yt.cpp Makefile
	g++ -std=gnu++11 -I. -I./yaml-cpp/include -I./yaml-cpp/include/yaml-cpp -c yt.cpp

clean :
	rm -f yt.x yt.o 
