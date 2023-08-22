SELECT CASE
    WHEN COUNT(Employee.salary) > 1
        THEN MIN(Employee.salary)
        ELSE NULL
    END AS SecondHighestSalary
FROM 
    (SELECT DISTINCT salary
     FROM Employee
     ORDER BY salary DESC
     LIMIT 2) Employee
