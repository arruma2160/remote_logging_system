CC=g++
CFLAGS=-Wall -Wundef -std=c++11
LDIR =-L/usr/local/lib 
LIBS=-lzmq

all:logserver logclient

logserver: logserver.cpp server_main.cpp
	$(CC) $(CFLAGS) -c logserver.cpp $(LDIR) $(LIBS)
	$(CC) $(CFLAGS) -c server_main.cpp $(LDIR) $(LIBS)
	$(CC) $(CFLAGS) -o $@ logserver.o server_main.o $(LDIR) $(LIBS)

logclient: logclient.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LDIR) $(LIBS)

clean:
	rm -f *.o logserver logclient
