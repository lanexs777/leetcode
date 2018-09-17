#175
select P.FirstName, P.LastName, A.city, A.State
from Person P left join Address A on P.PersonId
