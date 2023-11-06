SELECT 
query_name, 
ROUND(AVG(q.rating / q.position), 2) AS quality, 
ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*) * 100, 2) AS poor_query_percentage 
-- SUM(rating < 3)
FROM Queries AS q
GROUP BY query_name