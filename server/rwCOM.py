import serial

serialPort = serial.Serial(port = "COM7", baudrate=9600,bytesize=8, timeout=2000)
