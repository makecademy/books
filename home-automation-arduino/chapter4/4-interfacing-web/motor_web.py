import serial
import time

try:
    print "Trying..."
    arduino = serial.Serial('/dev/tty.usbmodem1411', 114000)
    time.sleep(1)
    arduino.flush()
except:
    print "Failed to connect"

sleeptime = 0.1
speed = 0

while True:
    try:
        
        # Open a file
        fo = open("motorCommand.txt", "r+")
        speed = fo.read()
        # Close the file
        fo.close()
        
        arduino.write('H,1,' + speed)
        time.sleep(sleeptime)
        
        # Read analog data
        sensorValue = arduino.readline()
        print sensorValue
        
        # Open a file
        fo = open("sensorValue.txt", "w")
        fo.write(sensorValue)
        # Close the file
        fo.close()
    
    except:
        print "Failed to send!"
