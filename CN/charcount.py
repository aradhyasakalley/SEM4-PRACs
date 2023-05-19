#sender side code
num_of_units = int(input('enter the nmumber of data units : '))
#empty list 

data_units = []

for i in range(num_of_units) : 
    data_unit = input('enter the data unit {} : '.format(i+1))
    data_units.append(data_unit)
    
resultData = ''

for data_unit in data_units : 
    lenght = len(data_unit) + 1
    resultData += str(lenght) + data_unit

print('the final data to be sent is : ',resultData)

#reciever side code 

receivedData = input('enter the received data : ')
decodedData = []

while receivedData : 
    lenght = int(receivedData[0]) -1
    decodedData.append(receivedData[1:lenght +1])
    receivedData = receivedData[lenght+1:]
    
print("the original data was : ")
for data_unit in decodedData : 
    print(data_unit)
