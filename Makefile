CC = g++
CFLAGS = -g -std=c++11
INCFLAGS = -I./include/
LDFLAGS = 

RM = /bin/rm -f
BUILDDIR = build
APPNAME = alz

all: createBuild alz
createBuild:
	mkdir -p $(BUILDDIR)
alz: main.o CPU.o Debug.o Test1KBMemory.o ROM.o include/types.h include/IMemory.hpp include/IROM.hpp
	$(CC) $(CFLAGS) -o $(APPNAME) $(BUILDDIR)/main.o $(BUILDDIR)/CPU.o $(BUILDDIR)/Debug.o $(BUILDDIR)/Test1KBMemory.o $(BUILDDIR)/ROM.o $(INCFLAGS) $(LDFLAGS) 
main.o: main.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/main.o -c main.cpp
CPU.o: src/CPU.cpp include/CPU.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/CPU.o -c src/CPU.cpp

Debug.o: src/Debug.cpp include/Debug.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Debug.o -c src/Debug.cpp

Test1KBMemory.o: src/Test1KBMemory.cpp include/Test1KBMemory.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/Test1KBMemory.o -c src/Test1KBMemory.cpp

ROM.o: src/ROM.cpp include/ROM.hpp
	$(CC) $(CFLAGS) $(INCFLAGS) -o $(BUILDDIR)/ROM.o -c src/ROM.cpp

clean: 
clean: 
	$(RM) $(BUILDDIR)/*.o $(APPNAME)
	rmdir $(BUILDDIR)


 
