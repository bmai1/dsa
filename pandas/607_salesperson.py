import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # select RED company id
    R_ID = company['com_id'][company['name'] == 'RED'].item()
    # select names from orders with R_ID
    df = pd.merge(sales_person, orders, on='sales_id')
    red_orders = df[df['com_id'] == R_ID][['name']]
    # select names not in name series
    return sales_person[~sales_person['name'].isin(red_orders['name'])][['name']]