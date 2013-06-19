import serial
import time
import sqlite3 as lite
import datetime

# Connect to DB
con = lite.connect('test.db')

# Show results
with con:
    
	cur = con.cursor()    
	
	# Get measurements
	cur.execute("SELECT * FROM Temperatures")
	rows = cur.fetchall()

	# Print results
	for row in rows:
		print row
