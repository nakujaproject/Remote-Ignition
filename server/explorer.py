#Script to test quality of received data in terms of continuity and checks characteristics of obtained data
import csv

with open('logs.csv') as logs:
    reader = csv.reader(logs)
    count = 0 #number of entries
    omega = 0 #final entry in log file
    constantStep = 50
    steps=constantStep
    stepCount=0
    missingInRange = []
    max = 0.0
    
    for row in reader:
        if (row[0]==''or row[1]==''):
            print(row)
            continue
        if count==0: #Assign first entry
            firstEntry = row[0]
        ###
        if steps==0:
            omegaStep = int(row[0])
            missingInRange.append((omegaStep-alphaStep)-stepCount)
            steps=constantStep
            stepCount=0
        if steps==constantStep:
            alphaStep = int(row[0])
        stepCount+=1
        steps-=1
        ###
        count+=1
        omega = int(row[0])
        #assign max reading
        if float(row[1])>max:
            max=float(row[1])
    
    print('First entry:',firstEntry,'&& Last entry:',omega)
    print('Number of entries:',count)
    print('Lost entries:',omega-count)
    print('Highest reading:',max)
    for v,i in enumerate(missingInRange):
        print(f"Bettween entry {v*constantStep}-{v*constantStep+constantStep} :: {i} == {round(i/constantStep*100,2)}%")