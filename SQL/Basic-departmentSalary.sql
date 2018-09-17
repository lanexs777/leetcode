#184
# Write your MySQL query statement below
select D.Name as Department, E2.Name as Employee, a.Salary 
from Department D, ( 
                     select Max(E.Salary) as Salary, E.DepartmentId
                     from Employee E
                     group by E.DepartmentId
                   ) as a ,
     Employee E2
where D.Id = a.DepartmentId and E2.Salary = a.Salary and E2.DepartmentId = a.DepartmentId
