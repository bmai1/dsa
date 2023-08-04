import pandas as pd

def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    df = store[store['amount'] > 500]
    return pd.DataFrame({df['customer_id'].nunique()}, columns=['rich_count'])