import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    examinations = examinations.groupby(['student_id', 'subject_name']).agg(attended_exams=('subject_name', 'count')).reset_index()
    # cross join
    students = students.merge(subjects, how='cross')
    # right join
    examinations = examinations.merge(students, on=['student_id', 'subject_name'], how='right')
    # fill null
    examinations = examinations.fillna(0)
    examinations.sort_values(['student_id', 'subject_name'], inplace=True)
    return examinations[['student_id', 'student_name', 'subject_name', 'attended_exams']]