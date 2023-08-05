import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    lo = len(accounts[accounts['income'] < 20000])
    avg = len(accounts[(accounts['income'] >= 20000) & (accounts['income'] <= 50000)])
    hi = len(accounts[accounts['income'] > 50000])
    df = pd.DataFrame({
        'category': ['Low Salary', 'Average Salary', 'High Salary'], 
        'accounts_count': [lo, avg, hi]
    })
    return df