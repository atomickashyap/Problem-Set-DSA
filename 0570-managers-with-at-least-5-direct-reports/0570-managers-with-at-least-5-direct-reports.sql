# Write your MySQL query statement below
SELECT  name FROM Employee e 
JOIN (SELECT managerId, COUNT(managerId) AS mcount FROM Employee
GROUP BY managerId HAVING COUNT(managerId)>4 ) d ON e.id = d.managerID