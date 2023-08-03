import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    cnt = courses['class'].value_counts()
    return pd.DataFrame(cnt[cnt >= 5].index, columns=['class'])