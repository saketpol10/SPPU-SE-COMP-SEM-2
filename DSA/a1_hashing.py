n = int(input("Enter the value of hashtable: "))
hashtable = [[], [], [], [], [], [], [], [], [], []]


def linear_probing(val, phone):
    temp = []
    temp.append(phone)
    comparisons = 1
    while hashtable[val] != []:
        val = val + 1
        if val > 9:
            val = 0
        comparisons += 1
    hashtable[val] = temp
    return val


def separate_chaining(val, phone):
    hashtable[val].append(phone)


def hash_fun(phone):
    return phone % 10


def insert_value(phone):
    val = hash_fun(phone)
    if hashtable[val] == []:
        temp = []
        temp.append(phone)
        hashtable[val] = temp
    else:
        value = int(input("\nCollision has occurred\n1. Linear probing\n2. Separate chaining\nChoose an option: "))
        if value == 1:
            val = linear_probing(val, phone)
        if value == 2:
            separate_chaining(val, phone)
    print("Inserted at hash value = ", val)


def display():
    for i in range(10):
        print(str(i) + " -> " + str(hashtable[i]))


def search(phone):
    comparisons = 1
    for i in range(10):
        for j in range(len(hashtable[i])):
            if hashtable[i][j] == phone:
                return i, comparisons
            comparisons += 1
    return -1, comparisons


for i in range(n):
    pno = int(input("Enter the phone number: "))
    insert_value(pno)

print("\nHashtable:\n")
display()

s = int(input("Enter the number to be searched: "))
position, num_comparisons = search(s)
if position != -1:
    print("Phone number found at position:", position)
else:
    print("Phone number not found.")
print("Number of comparisons required:", num_comparisons)