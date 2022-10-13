# 專題筆記: Socket Programing
10/06 - 10/12, 2022

<!-- -------------------------------------------------- -->
Socket
---

Socket 是通訊中的一種方式，主要用來處理客戶端與伺服器端之串連，只需要Protocol、IP、Port即可進行網路串連

### 指令

- 引入套件

        import socket

- socket 函式

        - 建構socket，回傳 <socket> 物件
        <socket> = socket.socket([family], [type] , [proto])

        - 關閉socket連接
        <socket>.close()

    | 欄位類別 | 名稱宣告 | 解釋內容 |
    | -------- | -------- | -------- |
    |family | socket.AF_UNIX | 於本機端進行串接(IPv4) |
    | | socket.AF_INET | 於伺服器與伺服器之間進行串接(IPv4) |
    | | socket.AF_INET6 | 於伺服器與伺服器之間進行串接(IPv6) |
    |type | socket.SOCK_STREAM | 使用TCP(資料流)的方式提供可靠、雙向、串流的通信頻道 |
    | | socket.SOCK_DGRAM | 使用UDP的方式提供通用的免連線訊息交換通道|
    |protocol| |串接協定(通常預設為0) |

        - 伺服器端監聽的IP位址和Port
        <socket>.bind(host, port)
        
        - 伺服器端最多可接受多少socket串接
        <socket>.listen(value)
        
        - 伺服器端接收串接，回傳串接對象與IP位址資訊(client, address)
        <socket>, (host, port) = <socket>.accept()
        
        - 客戶端指定要串接的IP位址跟Port號
        <socket>.connect(host, port)
        
- TCP
        
        - 傳送資料過去給串接對象，回傳送出的字數
        number = <socket>.send(data)
        
        - 可用於接收資料，回傳接收到的資料。value代表接收最多字數 
        data = <socket>.recv(value)
        
- UDP

        - 傳送資料過去給串接對象，回傳送出的字數
        number = <socket>.sendto(data, (addr, port))
        
        - 可用於接收資料，回傳接收到的資料與IP位址資訊(data, addr)。value代表接收最多字數
        data, addr = <socket>.recvfrom(value)

### 執行

- TCP

    ```python=
    # Server.py

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
    ```
    
        server start at: 127.0.0.1:8000
        wait for connection...

        connected by ('127.0.0.1', 50738)
        receive: hello tcp server
        send: hello tcp client
    
    ```python=
    # Client.py

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
    ```
    
        send: hello tcp server
        receive: hello tcp client
    
- UDP

    ```python=
    # Server.py
    
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
    ```
    
        server start at: 127.0.0.1:8000
        wait for connection...

        recvfrom ('127.0.0.1', 64656): hello udp server
        sendto ('127.0.0.1', 64656): hello udp client
    
    ```python=
    # Client.py
    
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
    ```
    
        sendto ('127.0.0.1', 8000): hello udp server
        recvfrom ('127.0.0.1', 8000): hello udp client
    
### 問題

以上寫法會造成堵塞，可以使用多線程來解決

- threading
- selector
- asyncio

<!-- -------------------------------------------------- -->
參考資料
---

[Python_Socket小實作](https://ithelp.ithome.com.tw/articles/10205819)

[影片: TCP/IP 網路通信之 Socket 程式設計入門](https://www.youtube.com/watch?v=ST6WLZFSHXs)

<!-- -------------------------------------------------- -->