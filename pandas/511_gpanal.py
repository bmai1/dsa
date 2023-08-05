import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # activity['first_login'] = activity.groupby('player_id')['event_date'].transform('min')
    # df = activity.drop_duplicates(subset='player_id', keep='first')
    # return df[['player_id', 'first_login']]

    return activity.groupby('player_id')['event_date'].min().reset_index(name='first_login')
    return activity.groupby('player_id').agg(first_login=('event_date', 'min')).reset_index()
