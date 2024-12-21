# Write your MySQL query statement below
SELECT e.name as Employee FROM Employee as e , Employee as m
WHERE e.managerId = m.id AND e.salary > m.salary