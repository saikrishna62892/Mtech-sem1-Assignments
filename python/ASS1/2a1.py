import csv

dict = {}
counter =0
with open('market.csv','rt')as f:
  data = csv.reader(f)
  for row in data:
          counter+=1
          if counter==20:
                  break
          dict[row[0]] = row[1]
print(dict)
