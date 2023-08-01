import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    df = employee.drop_duplicates(subset='salary')
    df.sort_values(by='salary', ascending=False, inplace=True)
    return df.iloc[N-1:N][['salary']]
    