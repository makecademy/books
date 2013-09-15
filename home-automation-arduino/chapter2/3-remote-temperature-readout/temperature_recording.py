import serial
import time
import sqlite3 as lite
import datetime

ser = serial.Serial('/dev/tty.usbmodem1a12131', 9600)
time.sleep(0.1)

# Trash the first data
for i in range(2):
    ser.readline()

# Connect to DB
con = lite.connect('test.db')

# Table creation
with con:
    
	cur = con.cursor()    
	cur.execute("DROP TABLE IF EXISTS Temperatures")
	cur.execute("CREATE TABLE Temperatures(Measurement INT, Temperature INT)")

# Start measurement
while (True):  

	# Read from Arduino
	data = ((int(ser.readline())*0.004882814) - 0.5) * 100
	print data

	# Store measurements
	with con:
    
		cur = con.cursor()    
		now = datetime.datetime.now()
		cur.execute("INSERT INTO Temperatures VALUES (?, ?)", (i, data))

	i+=1