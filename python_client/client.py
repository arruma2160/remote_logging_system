from datetime import datetime
import os
import socket
import sys
import time
import zmq

class Client:
    def __init__(self, ip="0.0.0.0", port=2222):
        self._context = zmq.Context()
        self._socket = self._context.socket(zmq.SUB)
        self._server_ip = ip
        self._server_port = port
        self._filter = b""

    def connect(self):
        if self._filter:
            self._socket.setsockopt(zmq.SUBSCRIBE, self._filter)

        _server_url = 'tcp://{}:{}'
        url = _server_url.format(self._server_ip, self._server_port)
        self._socket.connect(url)

    def set_filter(self, filter_by):
        self._filter = filter_by

    def _recv_data(self):
        return self._socket.recv()

    def receive_logs(self):
        rx1 = self._recv_data()
        rx2 = self._recv_data()
        return b"[" + rx1 + b"]" + b" " + rx2

    def __del__(self):
        self._socket.close()
        self._context.term()

# Configuring client.
client = Client()
client.set_filter(b"DEBUG")
client.connect()

while True:
    res = client.receive_logs()
    print("{}".format(res))

