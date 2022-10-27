import requests
url = 'http://192.168.100.95/' #IP for ESP32
headers = {'Command':"Test"}
r = requests.get(url,headers=headers)
print(r.text)