import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # merged_df = customers.merge(orders, left_on='id', right_on='customerId', how='left')
    # result_df = merged_df[merged_df['customerId'].isnull()]
    # result_df.rename(columns={'name': 'Customers'}, inplace=True)
    # return result_df[['Customers']]

    # rows in which id not present in orders[customerId]
    df = customers[~customers['id'].isin(orders['customerId'])]

    # df.rename(columns={'name': 'Customers'}, inplace=True)
    # return df[['Customers']]

    df = df[['name']].rename(columns={'name': 'Customers'})
    return df