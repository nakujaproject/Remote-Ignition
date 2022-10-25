from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive

def uploadToDrive(filename):
    gauth = GoogleAuth() 
    gauth.LocalWebserverAuth()          
    drive = GoogleDrive(gauth)  

    gfile = drive.CreateFile({'parents': [{'id': '1bG4QZx4oe6HZUs45IRMhtAu1wVk5MJ9C'}]})
    # Read file and set it as the content of this instance.
    gfile.SetContentFile(filename)
    gfile.Upload() # Upload the file.
