# Furit
fruits = ["apple", "banana", "mango"] 

prices = {
    "apple": 50,
    "banana": 30,
    "mango": 20
}  # Dictionary

closed_days = ("Saturday", "Sunday")  # Tuple

customers = {"ali", "omer", "ali", "sara"}

print("--- Fruit Price List ---")
for fruit in fruits:
    price = prices[fruit]
    
    if price >= 50:
        print(f"{fruit.capitalize()} costs Rs. {price} - Expensive")
    else:
        print(f"{fruit.capitalize()} costs Rs. {price} - Affordable")


print("\n--- Shop Status ---")
print("Shop is closed on:",closed_days)
print("Unique customers today:", len(customers))

mango_stock = 3

while mango_stock > 0:
    print("Selling one Mango. Stock left: ", mango_stock-1)
    mango_stock-=1
print ("No more Mangoes left!")