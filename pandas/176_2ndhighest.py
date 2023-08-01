import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.drop_duplicates(subset='salary')
    df.sort_values(by='salary', ascending=False, inplace=True)
    return pd.DataFrame({'SecondHighestSalary': [df['salary'].iloc[1]] if len(df) > 1 else [None]})