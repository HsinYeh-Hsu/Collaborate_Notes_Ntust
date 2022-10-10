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