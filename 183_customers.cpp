SELECT name AS Customers
FROM Customers 
WHERE NOT EXISTS (SELECT 1
                  FROM Orders
                  WHERE Customers.id = Orders.customerId)
