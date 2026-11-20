
import shutil
import os

source = input("Enter source file name: ")

if os.path.isfile(source):
    backup = source + ".backup"
    shutil.copy2(source, backup)
    print("Backup created:", backup)
else:
    print("File does not exist")
