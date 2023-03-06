SELECT sell_date, 
COUNT(distinct product) AS num_sold, 
GROUP_CONCAT(distinct product) AS products
FROM Activities
GROUP BY sell_date
