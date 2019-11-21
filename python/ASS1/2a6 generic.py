import sys
import csv
import re
import math
import itertools
import operator
map1,dict,counter,map4 = {},{},0,{}
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          key,value = row[0],row[1]
          if value[0]=='[':
               value = value[1:len(value)-1]
          value_list = list(value.split(":"))
          dict[key]=value_list
          re_list,dist_list =[],[]
          lam= lambda  y: re.match( r'(.*) (.*)', y, re.M|re.I)
          for x in iter(value_list):
                  matchObj=lam(x)
                  if matchObj:
                          re_list.append(matchObj.group(2))
                          map1[matchObj.group()]=matchObj.group(2)
                  else:
                          re_list.append(x)
          re_list.sort()
          for i in re_list:
                  if i not in dist_list:
                          dist_list.append(i)
          dict[key] = dist_list
          counter+=1
          for i in iter(dist_list):
               if i not in map4.keys():
                    map4[i]=1
               else:
                    map4[i]=map4[i]+1
freq_items=math.floor((counter-1)*0.1)
iterator,map2,map3,map5 = iter(map4),{},{},{}
for i in iterator:
     if(map4[i]>= freq_items):
          map2[i]=map4[i]
list1 = list( sorted(map2.keys(), key=operator.itemgetter(0),reverse=True))
list3 = []
print(list1)
print("-------------------------------Map--------------------------------------")
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
                 
