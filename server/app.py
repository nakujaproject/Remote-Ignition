from flask import Flask, request, send_from_directory
import requests
from flask_cors import CORS
import os
from log import secretary

app = Flask(__name__, static_folder='frontend/dist')
CORS(app)
latest = ''
url = 'http://192.168.100.95/' #IP for ESP32

# Serve React App
@app.route('/', defaults={'path': ''})
@app.route('/<path:path>')
def serve(path):
    if path != "" and os.path.exists(app.static_folder + '/' + path):
        return send_from_directory(app.static_folder, path)
    else:
        return send_from_directory(app.static_folder, 'index.html')

@app.route("/test")
def test():
    return {"test":"Server says hello"}

@app.route('/gateway') #Data from esp32, embedded in URL
def gateway():
    data = request.args
    latest = data.get('payload')+'\n'
    secretary(bytes(latest,'utf-8'))
    return {'null':'null'}

@app.route("/command") # Send command to esp32
def command():
    headers = {'Command':request.args.get('command')}
    r = requests.get(url,headers=headers)
    print(r.text)
    return {'null':'null'}

@app.route('/fetch') #respond to web app request of data
def fetch():
    return {'data': latest}