'''
Created on 6 Jan 2014

@author: Maged
'''

from NeuroPy import NeuroPy
import serial

object1=NeuroPy("COM16") #If port not given 57600 is automatically assumed
                        #object1=NeuroPy("/dev/rfcomm0") for linux
ser = serial.Serial(12)
max = 5
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
        print "Value of attention is", sum/max, "Value of blinking is", object1.blinkStrength, "Value of attention is ", object1.attention
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