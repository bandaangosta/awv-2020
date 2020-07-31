#!/usr/bin/env python3
from Acspy.Clients.SimpleClient import PySimpleClient
client = PySimpleClient()
m = client.getComponent("INSTRUMENT")
m.cameraOn()
pic = m.takeImage(20)
print("Our nice starry sky picture is: {}".format(pic.decode("utf-8")))
m.cameraOff()
