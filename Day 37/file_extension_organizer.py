
import os
import shutil

folder = input("Enter folder path: ")

if not os.path.isdir(folder):
    print("Folder does not exist")
else:
    for filename in os.listdir(folder):
        source = os.path.join(folder, filename)

        if os.path.isfile(source):
            extension = os.path.splitext(filename)[1]

            if extension:
                category = extension[1:].upper() + "_Files"
            else:
                category = "No_Extension"

            destination_folder = os.path.join(folder, category)
            os.makedirs(destination_folder, exist_ok=True)

            destination = os.path.join(destination_folder, filename)

            if os.path.abspath(source) != os.path.abspath(destination):
                shutil.move(source, destination)

    print("Files organized successfully!")
