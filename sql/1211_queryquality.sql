SELECT 
query_name, 
ROUND(AVG(q.rating / q.position), 2) AS quality, 
ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2) AS poor_query_percentage 
FROM Queries AS q
GROUP BY query_name