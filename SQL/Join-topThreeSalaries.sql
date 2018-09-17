#185

# Write your MySQL query statement below

# 要選出前三高，就是沒有超過三個人的薪水比他多
# join 的好處 !

select d.Name as Department, e1.Name as Employee, e1.Salary
from Employee e1 join Department d on e1.departmentId = d.Id
where 3 > (
            select count(distinct e2.Salary)
            from Employee e2
            where e2.Salary > e1.Salary and e2.DepartmentId = e1.DepartmentId
          )
order by d.Name, e1.Salary DESC      
