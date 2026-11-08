# Educational simulation only.
# Does not recover or change real account passwords.

accounts = {
    "student1": {
        "question": "What is your favorite color?",
        "answer": "blue"
    },
    "student2": {
        "question": "What is your favorite subject?",
        "answer": "python"
    }
}

username = input("Enter username: ").strip()

if username not in accounts:
    print("Account not found.")

else:
    question = accounts[username]["question"]
    print("Security question:", question)

    answer = input("Enter answer: ").strip().lower()

    if answer == accounts[username]["answer"]:
        print("Identity verification successful!")
        print("You can now follow your account's official recovery process.")
    else:
        print("Incorrect answer. Verification failed.")