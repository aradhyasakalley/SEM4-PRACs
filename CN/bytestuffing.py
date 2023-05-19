#sender
inputData = input('enter the data to be stuffed : ')
inputData = inputData.replace('#','##').replace('$','#$')

finalData = '$' + inputData + '$'
print('the data to be sent is : ',finalData)



#receiver

recievedData = input('enter the received frame : ')
originalData = ''
i = 1

while i < len(recievedData) - 1:
    if recievedData[i] != '#':
        originalData += recievedData[i]
    else : 
        if recievedData[i+1] != '$' and recievedData[i+1] !='#':
            originalData+=recievedData[i]
        elif recievedData[i+1] == '$' and recievedData[i-1] == '#':
            originalData+=recievedData[i]
    i+=1

print('sent data was : ',originalData)
