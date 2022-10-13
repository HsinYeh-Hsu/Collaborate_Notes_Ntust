# udp-socket: client.py
import socket

HOST = '127.0.0.1'
PORT = 8000

server_addr = (HOST, PORT)
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

outdata = 'hello udp server'
print('sendto ' + str(server_addr) + ': ' + outdata)
server.sendto(outdata.encode(), server_addr)

indata, addr = server.recvfrom(1024)
print('recvfrom ' + str(addr) + ': ' + indata.decode() + '\n')