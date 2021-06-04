import cs50

while True:
    h = cs50.get_int("Height: ")
    if h >= 1 and h < 9:
        break

for i in range(h):
    print(" " * (h - 1 - i), end="")
    print("#" * (i + 1))