
str_21 = "48.25 1,117.84 57.90 514.69 466.44 160.84 3,168.55 305.60"



def property_tax(str):
    
    str1 = ''
    for i in str:
        if i != ',':
            str1 += i
    
    #print("H: ", str1)
            
    
    newArr = str1.split(' ')
    #print(newArr)
    
    for i in range(0, len(newArr)):
        newArr[i] = int(float(newArr[i]))
    
    #print(newArr)
    
    sum = 0
    
    for i in newArr:
        sum += i
    
    return sum
    
        
    

print(property_tax(str_21))


