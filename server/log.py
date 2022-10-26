# Writes received data to file
def secretary(text: bytes):
    with open("logs.txt","ab") as file:
        file.write(text)