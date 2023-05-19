#sender 

num = int(input("Enter the number of data units : "))
data_units= []

for i in range(num) : 
    data_unit = input("Enter the data unit {}:".format(i+1))
    data_units.append(data_unit)

result = ""
for data_unit in data_units : 
    length = len(data_unit) + 1
    result += str(length) + data_unit

print("data to be sent : ",result)


#reciever


frame = input("Enter the data frame : ")
decoded = []

while frame : 
    lenght = int(frame[0]) - 1
    decoded.append(frame[1:lenght+1])
    frame = frame[1+lenght:]

print("the data units recieved are : ")
for data_unit in decoded : 
    print(data_unit)

