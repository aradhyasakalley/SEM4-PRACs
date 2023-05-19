#sender
num_of_units = int(input('enter the number of data units: '))
data_units = []

for i in range(num_of_units):
    data_unit = input('enter the data unit {}: '.format(i+1))
    data_units.append(data_unit)
resultData = ''
for data_unit in data_units:
    length = len(data_unit) + 1
    resultData += str(length) + data_unit

print('the final data to be sent is : ',resultData)


#receiver
receivedData = input('enter the received data: ')
originalData = []

while receivedData:
    length = int(receivedData[0]) - 1
    originalData.append(receivedData[1:length+1])
    receivedData = receivedData[length+1:]

print('the orignal data bits were: ')

for i in originalData:
    print(i)