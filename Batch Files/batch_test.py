import sys

print(f"This file is: {sys.argv[0]}")
print(f"args: {sys.argv[1:]}")
user_data = ["first name", "date of birth", "postcode"]

if len(sys.argv) <= 1:
    print("No args given")
else:
    for i in range(len(user_data)):
        print(f"{user_data[i]} is {sys.argv[i+1]}")
        