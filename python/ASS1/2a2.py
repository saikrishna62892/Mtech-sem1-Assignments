import csv
r_chars = ['[',']']
dict,counter = {},0
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          counter+=1
          key,value = row[0],row[1]
          if value[0]=='[':
               value = value[1:len(value)-1]
          value_list = list(value.split(":"))
          dict[key] = value_list
          if counter==20 :
                  break
print(dict)
