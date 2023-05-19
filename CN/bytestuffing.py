inputData = input('enter the input data: ')
inputData = inputData.replace('#','##').replace('$','#$')

finalData = '$' + inputData + '$'
print('the data to be sent is :',finalData)


receivedFrame = input('enter the receieved data: ')
originalData = ''

i=1

while i < len(receivedFrame) -1 : 
    if receivedFrame[i] != '#' :
        originalData += receivedFrame[i]
        
    else : 
        if receivedFrame[i+1]!='#' and receivedFrame[i+1]!='$':
            originalData += receivedFrame[i]
        elif receivedFrame[i+1] =='$' and receivedFrame[i-1] =='#':
            originalData += receivedFrame[i]
            
    i+=1
    
print('received data is ',originalData)