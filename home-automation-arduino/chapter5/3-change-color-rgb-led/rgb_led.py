from PyQt4 import QtGui, QtCore
import time
import os
import sys
import serial
import numpy

# Is the serial port available ?
try:
	ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
	time.sleep(1)
except:
	print 'No Arduino found'
	sys.exit()

# Main GUI class
class GUI(QtGui.QMainWindow):

	# Initialize the GUI
	def __init__(self, parent=None):
		
		# Main GUI object
		QtGui.QMainWindow.__init__(self, parent)
		
		# Configure windows
		self.setWindowTitle('LED Control')
		self.setStyleSheet("background-color: white;")
		
		# Create all elements of the window
		self.createWidgets()

		# Declare 
		self.red_value = 255
		self.green_value = 255
		self.blue_value = 255

	# Create all widgets of the GUI
	def createWidgets(self):
		
		# Define fonts of the GUI elements
		buttons_font = QtGui.QFont("Helvetica", 15)
		apply_font = QtGui.QFont("Helvetica", 15, QtGui.QFont.Bold)
		controls_font = QtGui.QFont("Helvetica", 15)
	
		# Title of the GUI window
		self.labelTitle = QtGui.QLabel("LED control")
		self.labelTitle.setFont(QtGui.QFont("Helvetica", 30, QtGui.QFont.Bold))

		# Create all sliders
		self.red_slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)
		self.green_slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)
		self.blue_slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)

		self.red_slider.setRange(0,255)
		self.green_slider.setRange(0,255)
		self.blue_slider.setRange(0,255)

		# Connect different objects
		QtCore.QObject.connect(self.red_slider,  QtCore.SIGNAL('valueChanged(int)'), self.update_pwm)
		QtCore.QObject.connect(self.green_slider,  QtCore.SIGNAL('valueChanged(int)'), self.update_pwm)
		QtCore.QObject.connect(self.blue_slider,  QtCore.SIGNAL('valueChanged(int)'), self.update_pwm)

		# Main box
		vbox = QtGui.QVBoxLayout()
		vbox.addWidget(self.red_slider)
		vbox.addWidget(self.blue_slider)
		vbox.addWidget(self.green_slider)
	
		# Create central widget, add layout and set
		central_widget = QtGui.QWidget()
		central_widget.setLayout(vbox)
		self.setCentralWidget(central_widget)

	# Actions when button is clicked

	# Increase speed if plus button is clicked
	def update_pwm(self):

		self.red_value = 255 - self.red_slider.value()
		self.green_value = 255 - self.green_slider.value()
		self.blue_value = 255 - self.blue_slider.value()

		ser.write('H')
		value = str(self.red_value) + ',' + str(self.green_value) + ',' + str(self.blue_value)
		ser.write(value)
		#time.sleep(0.1)

# Init testmode
app = QtGui.QApplication(sys.argv)

qb = GUI()
qb.show()
sys.exit(app.exec_())
