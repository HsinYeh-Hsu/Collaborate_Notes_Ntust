from http import client
from pydoc import cli
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(),1234)) # 接收端
s.listen(5)

while True:
    clientsocket , address = s.accept()
    print(f"Connection from {address} has been estalished!")
    clientsocket.send(bytes("B10902125","utf-8"))
    clientsocket.close()
    #msg = s.recv(1024)
    #full_msg += msg.decode("utf-8")
    #print(full_msg)