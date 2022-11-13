from flask import Flask, request, send_from_directory
from flask_cors import CORS
import os
import random

app = Flask(__name__, static_folder='frontend/dist')
CORS(app)
omega: str = ''

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


@app.route('/fetch') #respond to web app request of data
def fetch():
    return {'data': random.randint(1,500)}