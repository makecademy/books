import serial
import numpy as np
import time
from matplotlib import pyplot as plt
ser = serial.Serial('/dev/tty.usbmodem1411', 9600)
time.sleep(0.1)

# Trash the first data
for i in range(2):
    ser.readline()

# Do first read
first_temp = ((int(ser.readline())*0.004882814) - 0.5) * 100
 
# Start interactive mode
plt.ion() 
 
# Create data array
data_array = [first_temp]
 
# Plot data
plot, = plt.plot(data_array)

# Configure plot area
plt.ylim([0,50])
plt.xlabel("Time [s]")
plt.ylabel("Temperature")
 
# start data collection
while True:  

    # Read from Arduino
    data = ((int(ser.readline())*0.004882814) - 0.5) * 100

    # Append data to data array
    data_array.append(data)

    # Configure plot area
    ymin = float(min(data_array))-10
    ymax = float(max(data_array))+10
    plt.ylim([ymin,ymax])
    plt.xlim([0,len(data_array)])

    # Update plot
    plot.set_xdata(np.arange(len(data_array)))
    plot.set_ydata(data_array)  
    plt.draw()
