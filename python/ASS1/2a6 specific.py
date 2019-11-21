import sys
import csv
import re
import math
import itertools 
map1,dict,counter = {},{},0
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          key,value = row[0],row[1]
          if value[0]=='[':
               value = value[1:len(value)-1]
          value_list = list(value.split(":"))
          dict[key]=value_list
          for i in iter(value_list):
               if i not in map1.keys():
                    map1[i]=1
               else:
                    map1[i]=map1[i]+1
          counter+=1
freq_items=math.floor((counter-1)*0.1)
print(freq_items)
print("-------------------------------Map--------------------------------------")
iterator,map2,map3,map5 = iter(map1),{},{},{}
for i in iterator:
     if(map1[i]>= freq_items):
          map2[i]=map1[i]
list1,list3 = list(map2.keys()),[]
print(list1)
def findsubsets(s, n): 
    return (list(itertools.combinations(s, n))) 
list2 = findsubsets(list1,2)
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for i in iter(list2):
       str = ":"
       temp = str.join(i)
       map3[temp]=0
       list3.append(temp)
print(dict.values())
for i in iter(list2):
     for j in dict.keys():
          if i[0] in dict[j] and i[1] in dict[j]:
               temp=i[0]+":"+i[1]
               map3[temp] = map3[temp]+1
print(map3)
for i in iter(map3):
     if(map3[i]>= freq_items):
          map5[i]=map4[i]
print(map5)
                 
