from logging.handlers import SocketHandler
from multiprocessing.context import SpawnContext
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #IPv4 streaming
s.connect((socket.gethostname(),1234)) #連接到server

full_msg = ''
while True:
    #s.send(bytes("B10902125_Hsinyeh","utf-8"))
    msg = s.recv(1024)#封包大小上限1KB
    if len(msg)<=0:
        break
    full_msg += msg.decode("utf-8")
    print(full_msg)