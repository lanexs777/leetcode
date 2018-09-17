#176

select IFNULL( 
              (select distinct Salary
              from Employee
              order by Salary DESC
              limit 1 offset 1 ),
              NULL ) as SecondHighestSalary;
