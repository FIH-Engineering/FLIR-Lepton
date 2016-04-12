#! /usr/bin/python
# Written by Dan Mandle http://dan.mandle.me September 2012
# License: GPL 2.0
 
 
from __future__ import print_function 
import os
from gps import *
#from time import *
import time
import threading
import RPi.GPIO as GPIO

gpsd = None #seting the global variable
 
os.system('clear') #clear the terminal (optional)
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

class GpsPoller(threading.Thread):
  def __init__(self):
    threading.Thread.__init__(self)
    global gpsd #bring it in scope
    gpsd = gps(mode=WATCH_ENABLE) #starting the stream of info
    self.current_value = None
    self.running = True #setting the thread running to true
 
  def run(self):
    global gpsd
    while gpsp.running:
      gpsd.next() #this will continue to loop and grab EACH set of gpsd info to clear the buffer
 
if __name__ == '__main__':
  gpsp = GpsPoller() # create the thread
  try:
    gpsp.start() # start it up
    while True:
      #It may take a second or two to get good data
      #print gpsd.fix.latitude,', ',gpsd.fix.longitude,'  Time: ',gpsd.utc
 
      os.system('clear')
	  
      latitude = gpsd.fix.latitude
      longitude = gpsd.fix.longitude
      time = gpsd.utc,' + ', gpsd.fix.time
	  
      #GPIO read
      button = GPIO.input(17)
	  
      #if button is pressed than write to file
      if button == False:
        gpsdLog = open("GPSLOG.txt", "a")
        print(latitude, sep = "*", end="\n",file=gpsdLog)
        print(longitude, sep = "*", end="\n",file=gpsdLog)
        print(time, sep = "*", end="\n",file=gpsdLog)
        button = True
        time.sleep(3) #delay
      elif button == True:
        print("variables are resetting")
        time.sleep(3) 
 
  except (KeyboardInterrupt, SystemExit): #when you press ctrl+c
    print("\nKilling Thread...")
    gpsp.running = False
    gpsp.join() # wait for the thread to finish what it's doing
    GPIO.cleanup() 
  print("Done.\nExiting.")
  GPIO.cleanup() 
