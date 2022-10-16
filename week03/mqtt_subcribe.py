import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    client.subscribe("github")

def on_message(client, userdata, msg):
    if msg.payload.decode('utf-8') == '"git"':
        print("hub")


client = mqtt.Client()

client.on_connect = on_connect
client.on_message = on_message

client.connect("125.229.111.81", 1203, 60)
client.loop_forever()