SELECT 
  contest_id,  
  ROUND(COUNT(DISTINCT Users.user_id) * 100.0 / (SELECT COUNT(DISTINCT user_id) FROM Users), 2) AS percentage
FROM Register
LEFT JOIN Users
ON Users.user_id = Register.user_id
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC