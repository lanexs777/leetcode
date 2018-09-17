#181
# Write your MySQL query statement below

#way 1
select E1.Name as Employee
from Employee E1, Employee E2
where E1.ManagerId = E2.Id and E1.Salary > E2.Salary

#way 2
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
