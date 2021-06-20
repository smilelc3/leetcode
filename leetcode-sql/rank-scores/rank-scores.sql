# 初始化
create database if not exists leetcode;
use leetcode;

drop table if exists Scores;

Create table Scores
(
    Id    int,
    Score DECIMAL(3, 2)
);
Truncate table Scores;
insert into Scores (Id, Score)
values ('1', '3.5');
insert into Scores (Id, Score)
values ('2', '3.65');
insert into Scores (Id, Score)
values ('3', '4.0');
insert into Scores (Id, Score)
values ('4', '3.85');
insert into Scores (Id, Score)
values ('5', '4.0');
insert into Scores (Id, Score)
values ('6', '3.65');


# 获取成绩排名
select Score, dense_rank() over (order by Score desc ) as 'Rank'
from Scores;