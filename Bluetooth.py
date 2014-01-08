'''
Created on 6 Jan 2014

@author: Maged
'''

from NeuroPy import NeuroPy
import serial

object1=NeuroPy("COM14") # Port connecting to Neurosky bluetooth
ser = serial.Serial(41) # Port to send data on (to serial DUE USB = 12, serial UNO = 42 / Bluetooth shield = variable)
max = 2
idx = max
sum = 0

def blink_callBack(blink_rate):
    print "Blink rate is", blink_rate
    return None

def attention_callback(attention_value):
    "this function will be called everytime NeuroPy has a new value for attention"
    global idx, sum
    if idx > 0:
        idx= idx -1
        sum = sum + attention_value
        return None
    else:
        idx = max
        print "Average value of attention is", sum/max
        #do other stuff (fire a rocket), based on the obtained value of attention_value
        #do some more stuff
        #ser.write(sum/max)
        ser.write(str(sum/max))
        sum = 0
        return None

#set call backs
object1.setCallBack("attention",attention_callback)

object1.setCallBack("blinkStrength", blink_callBack)

#call start method
object1.start()

while True:
    var = object1    