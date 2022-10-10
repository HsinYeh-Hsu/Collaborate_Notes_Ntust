# udp-socket: server.py
import socket

HOST = '127.0.0.1'
PORT = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((HOST, PORT))

print('server start at: %s:%s' % (HOST, PORT))
print('wait for connection...' + '\n')

while True:
    indata, addr = s.recvfrom(1024)
    print('recvfrom ' + str(addr) + ': ' + indata.decode())

    outdata = 'hello udp client'
    print('sendto ' + str(addr) + ': ' + outdata + '\n')
    s.sendto(outdata.encode(), addr)