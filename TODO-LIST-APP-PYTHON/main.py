import time

todo = ["" for _ in range(1024)]

while True:
    try:
        request_input = int(input("\nWhat would you like to do? \n1) Look at List\n2) Add to List\n3) Delete from List\n4) Quit: "))
        print("\n")
    except ValueError:
        request_input = -1
        
    if request_input == 1:
        for i in range(1024):
            if todo[i] != "":
                print(todo[i])
    elif request_input == 2:
        index = int(input("Please Select Where To Put: "))
        todo[index] = input("Input Message: ")
    elif request_input == 3:
        index = int(input("Select Where To Delete: "))
        todo[index] = ""
    elif request_input == 4:
        print("Quitting..")
        time.sleep(1)
        break
    else:
        print("Invalid Input please try Again")   