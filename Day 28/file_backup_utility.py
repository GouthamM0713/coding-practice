import shutil
from pathlib import Path
from datetime import datetime


source = Path(input("Enter file path to back up: ").strip('"'))

if not source.is_file():
    print("File does not exist.")

else:
    backup_folder = Path("Backups")
    backup_folder.mkdir(exist_ok=True)

    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    destination = backup_folder / (
        f"{source.stem}_{timestamp}{source.suffix}"
    )

    try:
        shutil.copy2(source, destination)

        print("Backup created successfully!")
        print("Saved at:", destination.resolve())

    except OSError as error:
        print("Backup failed:", error)