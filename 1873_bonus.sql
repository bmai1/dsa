SELECT employee_id, 0 AS bonus
FROM Employees
WHERE MOD(employee_id, 2) = 0 OR SUBSTRING(name, 1, 1) = 'M'

UNION

SELECT employee_id, salary AS bonus
FROM Employees
WHERE MOD(employee_id, 2) != 0 AND name NOT LIKE 'M%'
ORDER BY employee_id
