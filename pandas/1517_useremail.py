import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    df = users[users['mail'].str.contains('^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$')]
    return df[['user_id', 'name', 'mail']]