from cs50 import get_string

let = 0
word = 1
sen = 0

text = get_string("Text: ")

for i in range(len(text)):
    if text[i].isalnum()==True:
        let += 1
for i in range(len(text)):
    if text[i].isspace()== True:
        word += 1
for i in range(len(text)):
    if text[i]=="?" or text[i]=="." or text[i]=='!':
        sen += 1

L = let * 100 / word
S = sen * 100 / word

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade < 1:
    print("Befor Grade 1")
elif grade < 16:
    print(f"Grade {grade}")
else:
    print("Grade 16+")

