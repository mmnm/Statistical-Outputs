appraised_value_21_66 = 402100
str_21_66 = "48.25 1,117.84 57.90 514.69 466.44 160.84 3,168.55 305.60"
###
appraised_value_20_66 = 320000
str_20_66 = "4,928.58"
###
appraised_value_19_66 = 320000
str_19_66 = "4,744.89"
###
appraised_value_18_66 = 287100
str_18_66 = "3,840.11"

######################

appraised_value_21_56 = 391000
str_21_56 = "46.92 1,086.98 56.30 500.48 453.56 156.40 3,081.08 297.16"
###
appraised_value_20_56 = 354500
str_20_56 = "5,474.41"
###
appraised_value_19_56 = 354500
str_19_56 = "5,271.35"
###
appraised_value_18_56 = 313600
str_18_56 = "4,707.55"

######################

appraised_value_21_76 = 368000
str_21_76 = "20.59 6.9500 477.05 0.3600 24.71 3.2000 219.65 2.9000 199.06 1.0000 71.64 19.7000"
###
appraised_value_20_76 = 331900
str_20_76 = "1,297.91"
###
appraised_value_19_76 = 331900
str_19_76 = "1,196.70"
###
appraised_value_18_76 = 297000
str_18_76 = "1,178.57"

def percent_calc(num1, num2):
    num1 = int(num1)
    num2 = int(num2)
    increase = num1 - num2
    return str((increase * 100/ num2)) + '%'
    


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
    
        


print("66 appraised 2021 value: ", appraised_value_21_66, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_21_66, appraised_value_20_66), 
      " property_tax: ", property_tax(str_21_66), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_21_66), property_tax(str_20_66))
     )
print("################\n")

print("56 appraised 2021 value: ", appraised_value_21_56, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_21_56, appraised_value_20_56), 
      " property_tax: ", property_tax(str_21_56), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_21_56), property_tax(str_20_56))
     )
print("################\n")

print("76 appraised 2021 value: ", appraised_value_21_76, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_21_76, appraised_value_20_76), 
      " property_tax: ", property_tax(str_21_76), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_21_76), property_tax(str_20_76))
     )
print("****************")
print("****************")
print("****************\n")


print("66 appraised 2020 value: ", appraised_value_20_66, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_20_66, appraised_value_19_66), 
      " property_tax: ", property_tax(str_20_66), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_20_66), property_tax(str_19_66))
     )
print("################\n")


print("56 appraised 2020 value: ", appraised_value_20_56, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_20_56, appraised_value_19_56), 
      " property_tax: ", property_tax(str_20_56), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_20_56), property_tax(str_19_56))
     )
print("################\n")

print("76 appraised 2020 value: ", appraised_value_20_76, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_20_76, appraised_value_19_76), 
      " property_tax: ", property_tax(str_20_76), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_20_76), property_tax(str_19_76))
     )
print("****************")
print("****************")
print("****************\n")

print("66 appraised 2019 value: ", appraised_value_19_66, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_19_66, appraised_value_18_66), 
      " property_tax: ", property_tax(str_19_66), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_19_66), property_tax(str_18_66))
     )
print("################\n")


print("56 appraised 2019 value: ", appraised_value_19_56, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_19_56, appraised_value_18_56), 
      " property_tax: ", property_tax(str_19_56), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_19_56), property_tax(str_18_56))
     )
print("################\n")

print("76 appraised 2019 value: ", appraised_value_19_76, 
    "; appraised yearly increase", 
      percent_calc(appraised_value_19_76, appraised_value_18_76), 
      " property_tax: ", property_tax(str_19_76), 
     "; tax yearly increase", 
      percent_calc(property_tax(str_19_76), property_tax(str_18_76))
     )
print("****************")
print("****************")
print("****************\n")

