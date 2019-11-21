import pandas as pd
df = pd.read_csv("Rainfall.csv") 
new_df = df.pivot_table(index=pd.Grouper(key='SUBDIVISION'))
print(new_df['JAN'])