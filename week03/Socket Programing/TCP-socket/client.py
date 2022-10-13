# tcp-socket: client.py
import socket

HOST = '127.0.0.1'
PORT = 8000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

outdata = 'hello tcp server'
print('send: ' + outdata)
client.send(outdata.encode())

indata = client.recv(1024)
print('receive: ' + indata.decode() + '\n')

client.close()