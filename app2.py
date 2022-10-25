from cmath import log
import RPi.GPIO as GPIO
from flask import Flask, render_template, request
import serial

import time



app = Flask(__name__)


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#define actuators GPIOs Relay
ledRed = 19


ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.flush()

ledRedSts = 0

GPIO.setup(ledRed, GPIO.OUT)   

GPIO.output(ledRed, GPIO.LOW)
testNum = 0



@app.route("/")
def index():
    global testNum
    global log 
    global allPoints
    testNum = 0
	# Read GPIO Status
    ledRedSts = GPIO.input(ledRed)
    templateData = {
      'ledRed'  : ledRedSts,
	  'testNum' : testNum,
      }
    return render_template('index.html', **templateData)

# The function below is executed when someone requests a URL with the actuator name and action in it:
@app.route("/<action>")
def action(action):
    allPoints=[]
    log = True
    if action == "on":
        ser.flush()
        
        GPIO.output(ledRed,GPIO.HIGH)
        time.sleep(5)
        GPIO.output(ledRed,GPIO.LOW)
        
        while log:
            val = ser.readline().decode('utf-8').rstrip()
            allPoints.append(val)
            time.sleep(0.01)
    if action == "off":
        log = False
        filename = datetime.now().strftime("%A %d %B %Y %I-%M%p") + ".csv"
        np.savetxt(filename, allPoints, newline="\n", fmt='%s')
        testNum=+1

    templateData = {
      'ledRed'  : ledRedSts,
	  'testNum' : testNum,
      }    
    
    return render_template('index.html', **templateData)



if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True)
