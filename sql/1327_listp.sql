SELECT p.product_name, SUM(o.unit) AS unit
FROM Products AS p
LEFT JOIN Orders AS o 
ON o.product_id = p.product_id
WHERE MONTH(o.order_date) = 2
AND YEAR(o.order_date) = 2020
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100;