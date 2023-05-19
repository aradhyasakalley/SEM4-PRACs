#sender
inputData = input('enter the input data: ')
#important 
inputData = inputData.replace('#','##').replace('$','#$')

finalData = '$' + inputData + '$'
print('the data to be sent is: ',finalData)


#reciever
receivedData = input('enter the received data:')

i = 1
originalData = ''


while i < len(receivedData) -1 :
    if receivedData[i] != '#':
        originalData+=receivedData[i]
    else : 
        if receivedData[i+1] != '#' and receivedData[i+1] != '$':
            originalData+=receivedData[i]
        elif receivedData[i+1] == '$' and receivedData[i-1] == '#':
            originalData+=receivedData[i]

    i+=1

print('the original data is: ',originalData)
