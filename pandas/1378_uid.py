import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    m = employees.set_index('id').combine_first(employee_uni.set_index('id')).reset_index()
    return m[['unique_id', 'name']]

    # close, but doesn't create null values
    # df = pd.merge(employees, employee_uni, on='id') 
    # return df