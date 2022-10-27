# Writes received data to file
def secretary(text: bytes):
    with open("logs.csv","ab") as file:
        file.write(text)