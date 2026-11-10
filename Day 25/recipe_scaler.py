print("Recipe Ingredient Scaler")

original_servings = float(input("Original servings: "))
new_servings = float(input("Required servings: "))

if original_servings <= 0 or new_servings <= 0:
    print("Servings must be greater than zero.")
else:
    ingredients = {
        "Flour (grams)": 200,
        "Sugar (grams)": 100,
        "Milk (ml)": 250,
        "Butter (grams)": 50
    }

    factor = new_servings / original_servings

    print("\nScaled Ingredients:")

    for item, quantity in ingredients.items():
        print(item, ":", round(quantity * factor, 2))