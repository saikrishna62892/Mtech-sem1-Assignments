import sys
import csv
import re
import math
map1,dict,counter = {},{},0
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          key,value = row[0],row[1]
          if value[0]=='[':
               value = value[1:len(value)-1]
          value_list = list(value.split(":"))
          iterator = iter(value_list)
          for i in iterator:
               if i not in map1.keys():
                    map1[i]=1
               else:
                    map1[i]=map1[i]+1
          counter+=1
freq_items=math.floor((counter-1)*0.1)
print(freq_items)
print("-------------------------------Map--------------------------------------")
iterator,map2 = iter(map1),{}
for i in iterator:
     if(map1[i]>= freq_items):
          map2[i]=map1[i]
print(map2)
