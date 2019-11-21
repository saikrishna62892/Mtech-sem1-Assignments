import pandas as pd
import math
df = pd.read_csv("Rainfall.csv") 
for i in range(df.shape[0]):
    if math.isnan(df.loc[i,'ANNUAL']):
        df.loc[i,'ANNUAL']=df.loc[i,'JAN':'DEC'].sum()
g=df.groupby('SUBDIVISION')
list1,j,new_df = list(g.mean()[['JAN','FEB','MAR','APR','MAY','JUN','JUL','AUG','SEP','OCT','NOV','DEC']].mean(axis=1)),0,pd.DataFrame()
for SUBDIVISION,SUBDIVISION_df in g:
    SUBDIVISION_df.fillna(list1[j],inplace=True)
    new_df,j=pd.concat([new_df,SUBDIVISION_df]),j+1
southwest_monsoon,northeast_monsoon = list(new_df[['JUN','JUL','AUG','SEP']].sum(axis=1)), list(new_df[['OCT','NOV','DEC']].sum(axis=1))
new_df['South-West Monsoon'],new_df['North-East Monsoon']= southwest_monsoon,northeast_monsoon
region={'WEST RAJASTHAN':'NORTH','EAST RAJASTHAN':'NORTH','HIMACHAL PRADESH':'NORTH','PUNJAB':'NORTH','VIDARBHA':'NORTH','ARUNACHAL PRADESH':'NORTH','MADHYA MAHARASHTRA':'NORTH','JAMMU & KASHMIR':'NORTH','UTTARAKHAND':'NORTH','HARYANA DELHI & CHANDIGARH':'NORTH','RAYALSEEMA':'SOUTH','TELANGANA':'SOUTH','LAKSHADWEEP':'SOUTH','KERALA':'SOUTH','ANDAMAN & NICOBAR ISLANDS':'SOUTH','TAMIL NADU':'SOUTH','SOUTH INTERIOR KARNATAKA':'SOUTH','COASTAL KARNATAKA':'SOUTH','COASTAL ANDHRA PRADESH':'SOUTH','NORTH INTERIOR KARNATAKA':'SOUTH','CHHATTISGARH':'EAST','EAST UTTAR PRADESH':'EAST','ORISSA':'EAST','JHARKHAND':'EAST','ASSAM & MEGHALAYA':'EAST','NAGA MANI MIZO TRIPURA':'EAST','BIHAR':'EAST','EAST MADHYA PRADESH':'EAST','GUJARAT REGION':'WEST','SAURASHTRA & KUTCH':'WEST','GANGETIC WEST BENGAL':'WEST','KONKAN & GOA':'WEST','MATATHWADA':'WEST','WEST MADHYA PRADESH':'WEST','WEST UTTAR PRADESH':'WEST', 'SUB HIMALAYAN WEST BENGAL & SIKKIM':'WEST'}
new_df['REGION']=new_df.SUBDIVISION.apply(lambda x: region[x])
h,prev_df=new_df.groupby(["YEAR","REGION"])[['South-West Monsoon','North-East Monsoon']].sum(),df.loc[:,['YEAR','SUBDIVISION','ANNUAL']]
prev_df['RAINFALL-PREV1'],prev_df['RAINFALL-PREV2'],prev_df['RAINFALL-PREV3']=prev_df.groupby('SUBDIVISION').ANNUAL.shift(1),prev_df.groupby('SUBDIVISION').ANNUAL.shift(2),prev_df.groupby('SUBDIVISION').ANNUAL.shift(3)


#import apriori
#frq_items = apriori(basket_France, min_support = 0.05, use_colnames = True) 

