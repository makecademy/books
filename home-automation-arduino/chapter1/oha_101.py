import serial
import time
import numpy

# Is the serial port available ?
try:
    ser = serial.Serial('/dev/tty.usbmodem1411', 9600)
    time.sleep(2)
except:
    print 'No Arduino found'
    sys.exit()

# Function to send the command
def send_command(value):
    ser.write('H')
    cmd = str(value) + ','
    ser.write(cmd)

# Make the LED blink
while True:
    send_command(1)
    time.sleep(0.1)
    send_command(0)
    time.sleep(0.1)
