#180
# Write your MySQL query statement below
select distinct num consecutivenums
from (
       // case 要用來比的需要有北select
       select num, case
                   when @record=num then @count:=@count+1
                   when @record:=num then @count:=1
                   end as n
       from logs , (select @count:=0, @record:=null) r
    
     ) as a

where a.n>=3
