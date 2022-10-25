
# Python program killing
# a thread using ._stop()
# function
  
import time
import threading
import RPi.GPIO as GPIO
  
class Ignition(threading.Thread):
  
    # Thread class with a _stop() method. 
    # The thread itself has to check
    # regularly for the stopped() condition.
  
    def __init__(self, actuator, *args, **kwargs):
        super(Ignition, self).__init__(*args, **kwargs)
        self._stop = threading.Event()
        self._actuator = actuator
  
    # function using _stop function
    def stop(self):
        self._stop.set()
  
    def stopped(self):
        return self._stop.isSet()
  
    def run(self):
        GPIO.output(self._actuator, GPIO.HIGH)
        time.sleep(5)
        while True:
            if self.stopped():
                GPIO.output(self._actuator, GPIO.LOW)
                return
  

