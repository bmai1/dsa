import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({ 
        'teacher_id': sorted(teacher['teacher_id'].unique()),
        'cnt': teacher.groupby('teacher_id')['subject_id'].nunique()
    })