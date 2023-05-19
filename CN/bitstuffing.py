#sender
inputData = input('enter the input data : ')
inputList = list(inputData)


i = 0
count = 0
flag = 0

while i < len(inputList) : 
    if inputList[i] == '1':
        count+=1
        if count == 5 and flag == 1 :
            inputList.insert(i+1,'0')
            count = 0

    else : 
        count = 0
        flag = 1
    
    i+=1

finalData = '01111110'+''.join(inputList)+'01111110'
print('the data to be sent is: ',finalData)


#receiver
receivedData = input('enter the received data: ').replace('01111110','')
receivedList = list(receivedData)


originalData = []


i = 0
count = 0

while i < len(receivedList):
    if count == 5 and receivedList[i] == '0':
        count = 0
        i+=1
        continue
    if receivedData[i] == '1':
        count+=1
        originalData.append(receivedList[i])
    else :
        count = 0
        originalData.append(receivedList[i])

    i+=1

   
print('the original data is: ' + ''.join(originalData))






