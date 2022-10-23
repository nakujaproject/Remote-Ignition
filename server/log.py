# Writes received data to file
def secretary(text):
    with open("logs.txt","a+") as file:
        file.write(text+'\n')