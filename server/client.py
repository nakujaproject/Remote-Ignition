#MQTT client
import paho.mqtt.client as mqtt
from log import secretary

broker_address="192.168.100.18"
client = mqtt.Client("windows") #create new instance
client.connect(broker_address)

#TODO: Handle when broker reconnects

def on_message(client, userdata, message):
    #The message parameter is a message class with members topic, qos, payload, retain
    secretary(message.payload)


client.on_message=on_message #attach function to callback
client.subscribe(('thrust',0))
client.loop_forever()