# tcp-socket: server.py
import socket

HOST = '127.0.0.1'
PORT = 8000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(5)

print('server start at: %s:%s' % (HOST, PORT))
print('wait for connection...' + '\n')

while True:
    conn, addr = server.accept()
    print('connected by ' + str(addr))

    indata = conn.recv(1024)
    print('receive: ' + indata.decode())

    outdata = 'hello tcp client'
    print('send: ' + outdata + '\n')
    conn.send(outdata.encode())
    conn.close()