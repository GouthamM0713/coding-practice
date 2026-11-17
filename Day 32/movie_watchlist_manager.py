import json
import os

FILE = "movie_watchlist.json"

def load_movies():
    if os.path.exists(FILE):
        with open(FILE, "r") as file:
            return json.load(file)

    return []

def save_movies(movies):
    with open(FILE, "w") as file:
        json.dump(movies, file, indent=4)


movies = load_movies()

while True:
    print("\n1. Add Movie")
    print("2. View Watchlist")
    print("3. Mark as Watched")
    print("4. Exit")

    choice = input("Choose: ")

    if choice == "1":
        name = input("Enter movie name: ")

        movies.append({
            "name": name,
            "watched": False
        })

        save_movies(movies)
        print("Movie added!")

    elif choice == "2":
        for i, movie in enumerate(movies, 1):
            status = "Watched" if movie["watched"] else "Pending"
            print(i, movie["name"], "-", status)

    elif choice == "3":
        for i, movie in enumerate(movies, 1):
            print(i, movie["name"])

        try:
            number = int(input("Enter movie number: "))

            if 1 <= number <= len(movies):
                movies[number - 1]["watched"] = True
                save_movies(movies)
                print("Movie marked as watched!")
            else:
                print("Invalid number!")

        except ValueError:
            print("Enter a valid number!")

    elif choice == "4":
        break

    else:
        print("Invalid choice!")