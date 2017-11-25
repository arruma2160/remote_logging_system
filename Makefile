CC=g++
INCL=-Iinclude
CFLAGS=-Wall -Wundef -std=c++11
LDIR =-L/usr/local/lib 
LIBS=-lzmq

all:logserver logclient

logserver: src/logserver.cpp src/server_main.cpp
	$(CC) $(CFLAGS) $(INCL) -c src/logserver.cpp $(LDIR) $(LIBS)
	$(CC) $(CFLAGS) $(INCL) -c src/server_main.cpp $(LDIR) $(LIBS)
	$(CC) $(CFLAGS) $(INCL) -o $@ logserver.o server_main.o $(LDIR) $(LIBS)

logclient: src/logclient.cpp
	$(CC) $(CFLAGS) $(INCL) -o $@ $^ $(LDIR) $(LIBS)

clean:
	rm -f *.o logserver logclient
