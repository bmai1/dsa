import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(employee, department, left_on='departmentId', right_on='id', how='outer')
    df = df[['name_y', 'name_x', 'salary']]
    df.columns = ['Department', 'Employee', 'Salary']
    
    maxSalary = df.groupby('Department')['Salary'].transform('max')
    df = df[df['Salary'] == maxSalary]
    return df

    # create new column with max salary series in corresponding department as Salary
    employee['Salary'] = employee.groupby('departmentId')['salary'].transform('max')
    df = employee[employee['salary'] == employee['Salary']]
    
    # map department name to department id in dictionary
    dep_name = department.set_index('id')['name'].to_dict()
    df['Department'] = df['departmentId'].map(dep_name)

    df.rename(columns={'name': 'Employee'}, inplace=True)
    return df[['Department', 'Employee', 'Salary']]