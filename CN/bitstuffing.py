



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

