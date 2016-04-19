import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BCM)

GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# ISR: if our button is pressed, we will have a falling edge on pin 31
# this will trigger this interrupt:

def Int_shutdown(channel): 
  # shutdown our Raspberry Pi
  os.system("sudo shutdown -h now")

# Now we are programming pin 18 as an interrupt input
# it will react on a falling edge and call our interrupt routine "Int_shutdown"
GPIO.add_event_detect(18, GPIO.FALLING, callback = Int_shutdown, bouncetime = 2000)   
while 1:
  time.sleep(1)