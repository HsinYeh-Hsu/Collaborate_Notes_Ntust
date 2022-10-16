import paho.mqtt.client as mqtt
import json

client = mqtt.Client()

# 設定連線資訊(IP, Port, 連線時間)
client.connect("125.229.111.81", 1203, 60)

while True:
    t = input()
    client.publish("github", json.dumps(t))