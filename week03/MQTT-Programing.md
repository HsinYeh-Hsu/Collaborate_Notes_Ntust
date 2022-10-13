# 專題筆記: MQTT Programing
10/06 - 10/12, 2022

<!-- -------------------------------------------------- -->
MQTT
---

工作在 TCP/IP 協定族上，是為硬體效能低下的遠端裝置以及網路狀況糟糕的情況下而設計的發布/訂閱型訊息協定。

### 功能

使用MQTT做出兩個client端，一個發送Git，另一個收到後要印出Hub。

### 工具

    paho-mqtt 套件
    
### Broker

在本機架設，需先下載 [mosquitto](https://mosquitto.org/)。在工作管理員開啟服務，將mosquitto設為啟用，可在cmd使用以下指令監聽伺服器是否開啟。

    netstat -an|find "1883"
    
![啟用mosquitto](https://i.imgur.com/jjJ6Nx9.png)

### Subscriber

```python=
# subscriber.py

import paho.mqtt.client as mqtt
import json

HOST = "127.0.0.1"
PORT = 1883
USER = ""
PASS = ""
TOPIC = "TEST"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe(TOPIC)

def on_message(client, userdata, msg):
    # msg.topic
    messages = json.loads(msg.payload)['messages']
    if (messages == 'Git'): print("Hub")

if __name__ == '__main__':

    client = mqtt.Client()
    # client.username_pw_set(USER, PASS)
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(HOST, PORT, 60)
    client.loop_forever()
```

    PS D:\Document\Code\Python\mqtt-test> python subscriber.py
    Connected with result code 0
    Hub
    Hub

### Publisher

```python=
# publisher.py

import paho.mqtt.client as mqtt
import json

HOST = "127.0.0.1"
PORT = 1883
USER = ""
PASS = ""
TOPIC = "TEST"

if __name__ == '__main__':

    client = mqtt.Client()
    # client.username_pw_set(USER, PASS)
    client.connect(HOST, PORT, 60)
    payload = {'messages': 'Git'}
    print (payload['messages'])
    client.publish(TOPIC, json.dumps(payload))
```

    發送2次
    
    PS D:\Document\Code\Python\mqtt-test> python publisher.py  
    Git
    PS D:\Document\Code\Python\mqtt-test> python publisher.py  
    Git

<!-- -------------------------------------------------- -->
參考資料
---

[使用 Python 進行 Publish & Subscribe](https://ithelp.ithome.com.tw/articles/10227131)

<!-- -------------------------------------------------- -->