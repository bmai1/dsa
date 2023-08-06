import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    df = actor_director.groupby(['actor_id','director_id']).filter(lambda x: len(x) >= 3)
    df.drop_duplicates(subset=['actor_id', 'director_id'], inplace=True)
    return df[['actor_id', 'director_id']]