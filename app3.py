import RPi.GPIO as GPIO
from flask import Flask, render_template, request

import time

app = Flask(__name__)


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

ledRed = 26
ledRedSts = 0
testNum = 0

GPIO.setup(ledRed, GPIO.OUT)   

GPIO.output(ledRed, GPIO.LOW)

@app.route("/")
def index(): 
    global testNum

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
    global testNum

    if action == "on":
        GPIO.output(ledRed,GPIO.HIGH)
        print("Igniting")
        time.sleep(1)
        GPIO.output(ledRed,GPIO.LOW)
        print("Not igniting")
            
    if action == "off":
        print("Done logging")
        testNum=+1

    templateData = {
      'ledRed'  : ledRedSts,
	  'testNum' : 1,
      }    
    
    return render_template('index.html', **templateData)



if __name__ == "__main__":
   app.run(host='0.0.0.0', port=80, debug=True)
