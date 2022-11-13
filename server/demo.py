import requests

file = open("logs.csv",'r')
while True:
    line=file.readline().split(',')
    omega=line[1]