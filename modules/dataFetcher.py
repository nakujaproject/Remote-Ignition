
# Python program killing
# a thread using ._stop()
# function
  
import time
import threading
import RPi.GPIO as GPIO
import numpy as np
import random
from datetime import datetime
#from modules.drive import uploadToDrive
  
class FetchData(threading.Thread):
  
    # Thread class with a _stop() method. 
    # The thread itself has to check
    # regularly for the stopped() condition.
  
    def __init__(self, ser, *args, **kwargs):
        super(FetchData, self).__init__(*args, **kwargs)
        self._stop = threading.Event()
        self._ser = ser
  
    # function using _stop function
    def stop(self):
        self._stop.set()
  
    def stopped(self):
        return self._stop.isSet()
  
    def run(self):
        allPoints = []
        time.sleep(2)
        while True:
            val = self._ser.readline().decode('utf-8').rstrip()
            allPoints.append(val)
            time.sleep(0.0125)
            if self.stopped():
                filename = datetime.now().strftime("%A %d %B %Y %I-%M%p") + ".csv"
                np.savetxt(filename, allPoints, newline="\n", fmt='%s')
                #uploadToDrive(filename)
                return
  

