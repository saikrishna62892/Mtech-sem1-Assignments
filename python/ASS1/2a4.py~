import sys
import csv
import re

map1,dict,counter = {},{},0
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          if counter==20 :
                  break
          key,value = row[0],row[1]
          if value[0]=='[':
               value = value[1:len(value)-1]
          value_list = list(value.split(":"))
          iterator = iter(value_list)
          re_list,dist_list =[],[]
          lam= lambda  y: re.match( r'(.*) (.*)', y, re.M|re.I)
          for x in iterator:
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

print(dict)
print("-------------------------------Map--------------------------------------")
print(map1)


