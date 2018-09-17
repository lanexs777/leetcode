#183
select N.Name as Customers
from 
    Customers N
where N.Id not in (select O.CustomerId as Id from Customers C, Orders O where C.Id = O.CustomerId )
