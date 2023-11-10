#----Chaining without Replacement----
n = int(input("Enter total values to be inserted into Hash Table:"))
list = [[],[],[],[],[],[],[],[],[],[]]
def hash_fun(key):
    return key%10
def display(list):
    for i in range(10):
        print(i,"->",list[i])

def search(key):
    for i in range(10):
        for j in range(len(list[i])):
            for k in range(len(list[i][j])):
                if list[i][j][k]==key:
                    return i

def delete(key):
    for i in range(10):
        for j in range(len(list[i])):
            for k in range(len(list[i][j])):
                if list[i][j][k]==key:
                    return j

for i in range(n):
    key =int(input("Enter key :"))
    value = int(input("Enter value :"))
    index = hash_fun(key)
    temp = []
    temp.append(key)
    temp.append(value)
    temp.append(-1)
    while list[index]!=[]:
        index+=1
        if index>=10:
            index = 0
    list[index].insert(index,temp)
display(list)

search_key = int(input("Enter key to be searched :"))
print(search_key, "found at position :",search(search_key))
delete_key = int(input("Enter key to be deleted :"))
val1 = search(delete_key)
val = delete(delete_key)
list[val1].pop(val)
display(list)