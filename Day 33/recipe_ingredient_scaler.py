
print("=== RECIPE INGREDIENT SCALER ===")

original_servings = float(input("Original number of servings: "))
new_servings = float(input("Desired number of servings: "))

if original_servings <= 0 or new_servings <= 0:
    print("Servings must be greater than zero.")
else:
    ingredients = {
        "Rice (cups)": 2,
        "Water (cups)": 4,
        "Salt (teaspoons)": 1,
        "Oil (tablespoons)": 2
    }

    factor = new_servings / original_servings

    print("\n=== UPDATED INGREDIENTS ===")

    for ingredient, quantity in ingredients.items():
        print(ingredient, ":", round(quantity * factor, 2))
