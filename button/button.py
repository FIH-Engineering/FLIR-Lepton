import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    red_state = GPIO.input(18)
	blue_state = GPIO.input(17)
    if red_state == False:
        print('RED')
        time.sleep(0.2)
	elif blue_state == False:
		print('BLUE')
		time.sleep(0.2)