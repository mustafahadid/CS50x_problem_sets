from math import floor
from cs50 import get_float

while True:
    dollar_owed = get_float("Change owed: ")
    if dollar_owed > 0:
        break
    
cent = floor(dollar_owed * 100)

quarter = cent // 25
dimes = (cent % 25) // 10
nickels =(cent % 25) % 10 // 5
pennies = (cent % 25) % 10 % 5

print(f"{quarter + dimes + nickels + pennies}")