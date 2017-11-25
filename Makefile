CC=g++
CFLAGS=-Wall -Wundef -std=c++11
LDIR =-L/usr/local/lib 
LIBS=-lzmq

all:logserver logclient

logserver: logserver.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDIR) $(LIBS)

logclient: logclient.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDIR) $(LIBS)

clean:
	rm -f *.o logserver
