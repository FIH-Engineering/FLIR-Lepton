# Written by Alex Gitlitz
 
from __future__ import print_function 
import os
from gps import *
from time import *
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
	  
      #GPIO read
      button = GPIO.input(17)
	  
      with open("/media/pi/63BE-12A3/FIHDocuments/Other/index.txt", "rb") as ind:
      	#change file name to "/media/pi/63BE-12A3/FIHDocuments/Other/    other index files saved there in USB
	    index = ind.readline()
	    number = int(index)
      
	  #if button is pressed than write to file
      if button == False:
        latitude = gpsd.fix.latitude
        longitude = gpsd.fix.longitude
        time1 = gpsd.utc,' + ', gpsd.fix.time
        gpsdLog = open("/media/pi/63BE-12A3/FIHDocuments/LogFiles/GPSLOG.txt", "a")
		# change file name to /media/pi/63BE-12A3/FIHDocuments/LogFiles/    other log file saved there in USB
        indfile = open("/media/pi/63BE-12A3/FIHDocuments/Other/index.txt", "w")
		#same as above
        print("image", number, sep = "*", end="  *  ",file=gpsdLog)
        number = number + 1
        print(number, file = indfile)
        indfile.close()
        print(latitude, sep = "*", end="  *  ",file=gpsdLog)
        print(longitude, sep = "*", end="  *  ",file=gpsdLog)
        print(time1, sep = "+", end="\n",file=gpsdLog)
        #print("button was pressed")
        gpsdLog.close()
        button = True
        time.sleep(1) #delay
      elif button == True:
        time.sleep(.2) 
 
  except (KeyboardInterrupt, SystemExit): #when you press ctrl+c
    print("\nKilling Thread...")
    gpsp.running = False
    gpsp.join() # wait for the thread to finish what it's doing
    GPIO.cleanup() 
  print("Done.\nExiting.")
  GPIO.cleanup() 
