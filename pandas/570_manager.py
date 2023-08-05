import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    ds = employee['managerId'].value_counts()
    ds = ds[ds >= 5]
    df = employee[employee['id'].isin(ds.index)]
    return df[['name']]