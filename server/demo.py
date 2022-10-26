from rwCOM import COM

serialCOM = COM('COM6')

file = open('logs.txt')
while 1:
    # print(file.readline())
    print(COM.getLatest())