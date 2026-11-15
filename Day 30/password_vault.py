import json
import shutil
from pathlib import Path
from datetime import datetime

source = Path(input("Enter JSON file path: "))

if not source.is_file() or source.suffix.lower() != ".json":
    print("Please provide an existing JSON file.")
else:
    try:
        with source.open("r", encoding="utf-8") as file:
            json.load(file)

        backup_folder = Path("backups")
        backup_folder.mkdir(exist_ok=True)

        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        destination = backup_folder / (
            f"{source.stem}_{timestamp}{source.suffix}"
        )

        shutil.copy2(source, destination)

        print("Backup created successfully!")
        print("Saved at:", destination)

    except json.JSONDecodeError:
        print("The file contains invalid JSON.")
    except OSError as error:
        print("File error:", error)