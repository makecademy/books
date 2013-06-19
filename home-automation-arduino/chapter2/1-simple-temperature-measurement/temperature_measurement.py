# Imports
import serial
import time
import numpy
import ftplib

# Open serial port
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
time.sleep(1)
ser.flush()

# Trash the first data
for i in range(2):
	ser.readline()

# Main loop
while(True):
    
	# Read data and convert to temperature
	temp = ((int(ser.readline())*0.004882814) - 0.5) * 100
	print temp
    
	# Save into file
	f = open('temperatures.txt', 'w')
	f.write(str(temp) + '\n')
    f.close()
