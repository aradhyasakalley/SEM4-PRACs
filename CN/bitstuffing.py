dataString = input('enter the data string: ')
frame = list(dataString)

i = 0
count = 0
flag = 0

while i < len(frame) : 
    if frame[i] == '1' : 
        count +=1
        if count == 5 and flag == 1 : 
            frame.insert(i+1,'0')
            count = 0
    else : 
        count = 0
        flag = 1

    i += 1


output = '01111110' + ''.join(frame) + '01111110'
print('data to be sent is : ',output)



receivedFrame = input('enter the received frame: ').replace('01111110','')
arr = list(receivedFrame)

orig = []
i=0
count = 5

while i < len(arr) : 
    if (count == 5) and arr[i] == '0' : 
        count = 0
        i+=1
        continue
    
    if arr[i] == '1': 
        orig.append(arr[i])
        count+=1
    else : 
        count = 0
        orig.append(arr[i])
    

    i+=1

print("the original data stirng is : ",''.join(orig))

