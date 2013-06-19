import serial
import time
import sqlite3 as lite
import datetime

ser = serial.Serial('/dev/tty.usbmodem1411', 9600)
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
	cur.execute("CREATE TABLE Temperatures(Time TEXT, Temperature INT)")

# Start measurement
nb_measurements = 10
i = 0
while (i < nb_measurements):  

	# Read from Arduino
	data = ((int(ser.readline())*0.004882814) - 0.5) * 100

	# Store measurements
	with con:
    
		cur = con.cursor()    
		now = datetime.datetime.now()
		record_time = now.strftime("%d-%m-%Y %H:%M:%S")
		cur.execute("INSERT INTO Temperatures VALUES (?, ?)", (record_time, data))

	i+=1

# Show results
with con:
    
	cur = con.cursor()    
	
	# Get measurements
	cur.execute("SELECT * FROM Temperatures")
	rows = cur.fetchall()

	# Print results
	for row in rows:
		print row
