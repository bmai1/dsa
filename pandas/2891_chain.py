import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    condition = animals['weight'] > 100
    return animals.sort_values(by='weight', ascending=False)[condition][['name']]