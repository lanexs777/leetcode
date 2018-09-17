# Write your MySQL query statement below

// this is the variabl-version but a little thing wrong.
// the question wants a int type for rank, this answer will return string type instead.
/*select Score, case
              when @preRank = Score then @curRank
              when @preRank := Score then @curRank := @curRank + 1
              end as Rank
from Scores, (select @curRank := 0, @preRank:=NULL) r
order by Score DESC*/


select A.Score, count(B.Score) as Rank
from Scores as A, ( select distinct Score
                    from Scores) as B
where A.score <= B.Score
group by A.Id
order by A.Score desc;
