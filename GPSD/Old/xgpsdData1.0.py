#! /usr/bin/python
# Written by Dan Mandle http://dan.mandle.me September 2012
# License: GPL 2.0

from __future__ import print_function
import os
from gps import *
from time import *
import time
import threading
 
gpsd = None #seting the global variable
 
os.system('clear') #clear the terminal (optional)
 
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
      test = open("gpsLog.txt", "a")
      print
      print ("GPS reading", sep='*', end='\n', file=test)
      print ('----------------------------------------')
      print ('latitude    ' , gpsd.fix.latitude, sep='*', end='\n', file=test)
      print ('longitude   ' , gpsd.fix.longitude, sep='*', end='\n', file=test)
      print ('time utc    ' , gpsd.utc,' + ', gpsd.fix.time, sep='*', end='\n', file=test)
      print ('altitude (m)' , gpsd.fix.altitude, sep='*', end='\n', file=test)
      print ('eps         ' , gpsd.fix.eps, sep='*', end='\n', file=test)
      print ('epx         ' , gpsd.fix.epx, sep='*', end='\n', file=test)
      print ('epv         ' , gpsd.fix.epv, sep='*', end='\n', file=test)
      print ('ept         ' , gpsd.fix.ept, sep='*', end='\n', file=test)
      print ('speed (m/s) ' , gpsd.fix.speed, sep='*', end='\n', file=test)
      print ('climb       ' , gpsd.fix.climb, sep='*', end='\n', file=test)
      print ('track       ' , gpsd.fix.track, sep='*', end='\n', file=test)
      print ('mode        ' , gpsd.fix.mode, sep='*', end='\n', file=test)
      print ('sats        ' , gpsd.satellites, sep='*', end='\n', file=test)
      test.close()
      time.sleep(5) #set to whatever
 
  except (KeyboardInterrupt, SystemExit): #when you press ctrl+c
    print ("\nKilling Thread...")
    gpsp.running = False
    gpsp.join() # wait for the thread to finish what it's doing
  print ("Done.\nExiting.")