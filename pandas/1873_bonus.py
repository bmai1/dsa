import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    tmp = []
    for id, name, salary in employees.values:
        if id % 2 != 0 and not name.startswith('M'):
            tmp.append(salary)
        else:
            tmp.append(0)
    employees['bonus'] = tmp
    return employees[['employee_id', 'bonus']].sort_values(by='employee_id')