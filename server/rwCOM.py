import serial
import time
from log import secretary

#Format -> index, hx711_value
class COM:
    latest = '' #holds the latest reading from the COM port
    def __init__(self, port):
        self.serialPort = serial.Serial(port = port, baudrate=9600,timeout=.2)

    def getLatest():
        return COM.latest
    
    def write(self,command: bytes):
        self.serialPort.write(command)
        time.sleep(0.9)
        while 1:
            if(self.serialPort.in_waiting > 0):
                    print(self.serialPort.readline().decode('Ascii'))
                    break
        
    def main(self):
        while 1:
            if(self.serialPort.in_waiting > 0):
                # Read data out of the buffer until a carraige return / new line is found
                COM.latest = self.serialPort.readline()
                secretary(COM.latest)
                # Print the contents of the serial data
                print(COM.latest.decode('Ascii'))

if __name__=="__main__":
    serialCOM = COM('COM6')
    # serialCOM.write((bytes('xammzy', 'utf-8')))
    serialCOM.main()